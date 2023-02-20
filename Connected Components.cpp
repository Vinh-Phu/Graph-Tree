/*
* MSSV : 19110413
* Ho va Ten : Vong Vinh Phu
* Assignment : Assignment 2 - Connected Components
* Created at : 05/12/2021
* IDE : Visual studio 2019
*/
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#define SIZE_OF_ARRAY(array)  (sizeof(array)/sizeof(array[0]))
#define max 100
void load_matrix(istream* is,
    vector<vector<int> >* matrix,
    const std::string& delim = " \t")
{
    string      line;
    string      strnum;

    while (getline(*is, line))
    {
        matrix->push_back(vector<int>());

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
void Result(int* visited, int n, int cComponent) {
    cout << "so luong thanh phan lien thong la " << cComponent << endl;
    for (int i = 1; i <= cComponent; i++) {
        cout <<"Thanh phan lien thong thu "<< i <<":";
        for (int j = 0; j <= n; j++) {
            if (visited[j] == i)
                cout<< "\t" << j + 1;
        }
        cout << "\n";
    }
}
void BFS(vector<vector<int>> G, int n, int i, int* cComponent, int visited[]) {
    int u, headQ, tailQ, j, QUEUE[max];
    headQ = 0; tailQ = 0;
    QUEUE[tailQ] = i; visited[i] = *cComponent;
    while (headQ <= tailQ) {
        u = QUEUE[headQ];
        headQ += 1;
        for (j = 1; j <= n-1; j++) {
            if (G[u][j] == 1 && visited[j] == 0) {
                tailQ = tailQ + 1;
                QUEUE[tailQ] = j;
                visited[j] = *cComponent;
            }
        }
    }
}

 int main() 
 {

    using namespace std;

    // read the file
    std::ifstream file("input_dothi.txt");

    // load the matrix
    vector<vector<int> > matrix;
    int visited[max],cComponent;
    load_matrix(&file, &matrix);
    for (int i = 0; i <= matrix.size(); i++)
        visited[i] = 0;
    cComponent = 0;
    //Output
    for (int i = 0; i < matrix.size(); i++)
        if (visited[i] == 0) {
            cComponent += 1;
            BFS(matrix, matrix.size(), i, &cComponent, visited);
        }
    Result(visited, matrix.size(), cComponent);
    
    file.close();
    return 0;
}
