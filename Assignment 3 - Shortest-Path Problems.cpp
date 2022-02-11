/*
* MSSV : 19110413
* Ho va Ten : Vong Vinh Phu
* Assignment : Assignment 3 - Shortest-Path Problems
* Created at : 26/12/2021
* IDE : Visual studio 2019
*/
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <sstream>
#include <vector>
#include <limits.h>
using namespace std;
#define inf UINT_MAX
void get_information(istream* is,
    vector<vector<unsigned int> >* matrix,
    const std::string& delim = " \t")
{
    string      line;
    string      strnum;

    while (getline(*is, line))
    {
        matrix->push_back(vector<unsigned int>());

        for (string::const_iterator i = line.begin(); i != line.end(); ++i)
        {
            if (delim.find(*i) == string::npos)
            {
                strnum += *i;
                if (i + 1 != line.end()) 
                    continue;
            }

            if (strnum.empty())
                continue;
            double       number;

            istringstream(strnum) >> number;
            matrix->back().push_back(number);

            strnum.clear();
        }
    }
}
unsigned int N;
unsigned int graph[50][50];
unsigned int dist[50];
bool visited[50];
unsigned int parent[50];
vector<int> target;
vector<vector<unsigned int>> adjList(vector<vector<unsigned int> > data)
{
    vector<vector<unsigned int> > adjlist;
    int u,v,w,j=0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].size() == 3)
        {
            adjlist.push_back(vector<unsigned int>());
            u = data[i][0];
            v = data[i][1];
            w = data[i][2];
            adjlist[j].push_back(u);
            adjlist[j].push_back(v);
            adjlist[j].push_back(w);
            j++;
        }
    }
    return adjlist;
}
vector<int> Target(vector<vector<unsigned int> > data)
{
    vector<int> target;
    int start, goal;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].size() == 2)
        {
            start = data[i][0];
            goal = data[i][1];
            target.push_back(start);
            target.push_back(goal);
        }
    }
    return target;
}

void createGraph()
{
    std::ifstream file("thong_tin_dinh.txt");
    vector<vector<unsigned int> > data;
    vector<vector<unsigned int> > adjlist;
    
    get_information(&file, &data);
    adjlist = adjList(data);
    int u, v, w;
    N = data[1][0];
    if (data[0][0] == 0) // Undirected graph
    {
        for (int i = 0; i < adjlist.size(); i++)
        {
            
                u = adjlist[i][0];
                v = adjlist[i][1];
                w = adjlist[i][2];
                
                graph[u][v] = w;
                graph[v][u] = w;
                
        }
    }
    else // Directed graph
    {
        for (int i = 0; i < adjlist.size(); i++)
        {
            u = adjlist[i][0];
            v = adjlist[i][1];
            w = adjlist[i][2];

            graph[u][v] = w;
        }
    }
    target = Target(data);
    file.close();
}
int minDistance()
{
    int min = inf, minDist;
    for (int v = 1; v <= N; v++)
        if (visited[v] == false && dist[v] <= min)
        {
            min = dist[v];
            minDist = v;
        }
    return minDist;
}
void printPath(ostream& output, int j)
{
    if (parent[j] == -1)
        return;
    printPath(output, parent[j]);
    output << j << " -> ";
}
void dijkstra()
{
    int start,end;
    start = target[0];
    end = target[1];
    for (int i = 1; i <= N; i++)
    {
        parent[0] = -1;
        dist[i] = inf;
        visited[i] = false;
    }
    dist[start] = 0;
    for (int j = 1; j <= N - 1; j++)
    {
        int u = minDistance();
        visited[u] = true;
        for (int v = 1; v <= N; v++)
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    std::ofstream Output("ket_qua_bai_3_19110413.txt");
    if (dist[end] == inf)
    {
        Output << "Khong co duong di ngan nhat";
    }
    else
    {
        
        Output << "Tong chi phi di chuyen = " << dist[end] << "\n";
        Output << "Duong di ngan nhat cua do thi la: ";
        printPath(Output, end);
        Output.close();
        std::ifstream fileIn("ket_qua_bai_3_19110413.txt");                   

        std::stringstream buffer;                             
        buffer << fileIn.rdbuf();
        std::string contents = buffer.str();

        fileIn.close();
        contents.pop_back(); 
        contents.pop_back();
        contents.pop_back();                                  

        std::ofstream fileOut("ket_qua_bai_3_19110413.txt", std::ios::trunc); 
        fileOut << contents;                                  
        fileOut.close();
    }
    
}
int main()
{
    createGraph();
    dijkstra();
    return 0;
}
