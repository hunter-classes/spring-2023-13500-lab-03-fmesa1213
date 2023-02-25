/*
Author: Frida Mesa
Course: CSCI-135
Instructor: 
Assignment: Lab3D
Wrote a program which asks the user to input two dates.
The program should report the West basin elevation for all 
days in the interval in the reverse chronological order.
*/


#include<iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <sstream>
using namespace std;
#include <vector>

int main()
{
ifstream fin("Current_Reservoir_Levels.tsv");
if (fin.fail())
{
cerr << "File cannot be opened for reading." << endl;
exit(1);
}
vector<string> Date;
vector<float> westElVec;
string header;
getline(fin, header); 
string dateArr[365], date;
double eastSt, eastEl, westSt, westEl;
string date1, date2;
cout << "Enter starting date: ";
cin >> date1; 

cout << "Enter ending date: ";
cin >> date2; 
int count = 0;
while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
{
fin.ignore(INT_MAX, '\n'); 
if (date1 <= date && date2 >= date)
{
Date.push_back(date);
westElVec.push_back( westEl);
count++;
}
}

for (int i = 0; i < count; ++i)
{
for (int j = 0; j < count - i - 1; ++j)
{
if (Date[j] < Date[j + 1])
{

string tDate = Date[j];
Date[j] = Date[j + 1];
Date[j + 1] = tDate;
}
}
}
for (int i = 0; i < count; i++)
cout << Date[i] << "\t" << westElVec[i] <<"ft"<< endl;
fin.close();

  return 0;
}
