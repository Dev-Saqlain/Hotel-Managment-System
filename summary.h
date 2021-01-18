#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
//function for summary report
void summary_report()
{
	string b;
	ifstream report("Check_in.txt",ios::in);
	//read data from file
	while (report >> b) 
	{
    	cout << b<<endl; 
	}
}
