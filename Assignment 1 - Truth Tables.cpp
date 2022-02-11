/*
  - MSSV : 19110413
  - Ho Va Ten : Vong Vinh Phu
  - Assignment : Assignment 1 - Truth Tables
  - Created at : 11/5/2021
  - IDE : Visual studio code
 */


#include<iostream> 

int negation(int p); 
int disjunction(int p, int q); 
int bicontional(int p, int q); 
int conjunction(int p, int q);
int conditional(int p, int q);
int dectobin(int dec, int bin[]); // convert decimal to binary 
int truthtable(int bin[], int formula); // print truth table 
char TF(int a); // Output T or F 
int main()
{
	
	
	int cases = 1;
	while (cases <= 5)
	{
		int bin[2] = { 0,0 };
			
			truthtable(bin, cases);
		cases ++;
		std::cout << "\n-----------------------------" << std::endl;
	}

}

int negation(int p)
{
	if (p == 0)
	{
		return 1;
	}
	return 0;
}

int disjunction(int p, int q)
{
	
	if (p == 1 || q == 1)
	{
		return 1;
	}
	return 0;
}

int bicontional(int p, int q)
{
	int temp = conditional(p, q);
	int temp2 = conditional(q, p);
	if (temp == 1 && temp2 == 1)
	{
		return 1;
	}
	return 0;
}

int conjunction(int p, int q)
{
	
	if (p == 1 && q == 1)
	{
		return 1 ;
	}
	
	return 0;
}

int conditional(int p, int q)
{
	
	if (!p == 1 || q == 1)
	{
		return 1;
	}
	
	
	return 0;

}

int dectobin(int dec, int bin[])
{
	int i=0;
	while(dec > 0)
	{
		bin[i] = dec % 2;
		dec = dec / 2;
		i++;
	}
	
	return 0;
}

int truthtable(int bin[], int formula)
{
	int n = 0;
	int i = 0;
	switch (formula)
	{
	
	case 1:
		std::cout << "p" << "\t" << "~p" << "\n\n";
		while (n<2)
		{
			dectobin(n, bin);
			std::cout << TF(bin[i]) << "\t" << TF(negation(bin[i])) << "\n";
			n++;
		}
		break;
		
	case 2:
		std::cout << "p" << "\t" << "q" << "\t" << "p v q" << "\n\n";
		while (n < 4)
		{
			dectobin(n, bin);
			std::cout << TF(bin[i+1]) << "\t" << TF(bin[i]) << "\t" << TF(disjunction(bin[i+1], bin[i])) << "\n";
			n++;
		}
		break;
		
	case 3:
		std::cout << "p" << "\t" << "q" << "\t" << "p ^ q" << "\n\n";
		while (n < 4)
		{
			dectobin(n, bin);
			std::cout << TF(bin[i+1]) << "\t" << TF(bin[i]) << "\t" << TF(conjunction(bin[i+1], bin[i])) << "\n";
			n++;
		}
		break;
		
	case 4:
		std::cout << "p" << "\t" << "q" << "\t" << "p -> q" << "\n\n";
		while (n < 4)
		{
			dectobin(n, bin);
			std::cout << TF(bin[i+1]) << "\t" << TF(bin[i]) << "\t" << TF(conditional(bin[i+1], bin[i])) << "\n";
			n++;
		}break;
		
	case 5:
		std::cout << "p" << "\t" << "q" << "\t" << "p <-> q" << "\n\n";
		while (n < 4)
		{
			dectobin(n, bin);
			std::cout << TF(bin[i+1]) << "\t" << TF(bin[i]) << "\t" << TF(bicontional(bin[i+1], bin[i])) << "\n";
			n++;
		}break;
			
	default:
		std::cout << "Don't have this formula";
	break;
	}
	
	return 0;
}

char TF(int a)
{
	char result;
	char T{ 'T' };
	char F{ 'F' };
	if (a==1)
	{
		result = T ;
	}
	else
	{
		result = F;
	}
	return result;
}
