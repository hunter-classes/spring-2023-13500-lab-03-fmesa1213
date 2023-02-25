/*
Author: Frida Mesa
Course: CSCI-135
Instructor: 
Assignment: Lab3A
Wrote a program that asks the user to input a string representing the date 
(in MM/DD/YYYY format), and prints out the East basin storage on that day.
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
string userdate;
  
cout<<"Enter date: ";
cin>>userdate;

ifstream fin("Current_Reservoir_Levels.tsv");
if (fin.fail()) {
cerr << "File cannot be opened for reading." << endl;
exit(1); 
}

string junk; 
getline(fin, junk);
while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
  fin.ignore(INT_MAX, '\n'); 
  if(date==userdate)
{
  cout<<"East basin storage: "<<eastSt<<" gallons"<<endl;
  break;
}
}

fin.close();

return 0;
}
