/*
Author: Frida Mesa
Course: CSCI-135
Instructor: 
Assignment: Lab3B
Wrote a program that finds the minimum and maximum storage in East basin in 2018.
*/

#include<iostream>
#include<fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
string date;
double eastSt;
double eastEl;
double westSt;
double westEl;
double min;
double max;

ifstream fin("Current_Reservoir_Levels.tsv");
if (fin.fail()) {
cerr << "File cannot be opened for reading." << endl;
exit(1); 
}
  
  string junk; 
getline(fin, junk);
  
  int i=0;
while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
{
fin.ignore(INT_MAX, '\n'); 
if(i==0)
{
  min = eastSt;
  max = eastSt;
}
  if(min>eastSt)
    min = eastSt;
  if(max<eastSt)
    max = eastSt;
    i++;
}
  
cout<<"minimum storage in East basin: "<<min<<" billion gallons"<<endl;
cout<<"MAXimum storage in East basin: "<<max<<" billion gallons"<<endl;

fin.close();

return 0;

}
