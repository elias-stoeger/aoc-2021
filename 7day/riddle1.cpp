/* This work is licensed under the IDGAF v1.0 license, a copy should be included.
 * If I forgot to include it you may wanna google it but basically:
 *    -Do whatever but don't blame me if something bad happens
 *    -Would be cool if you credited me if you use my code but whatever
 *    -You should use the same license
 *    -or don't, just don't put some gay, lefty ethical license nonsense
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
 	string line;
	fstream input;

	input.open("input1.txt", ios::in);
	getline(input, line);

	vector<int> crabs;
	string temp = "";
	
	for(auto x: line)
	{
		if(x != ',')
			temp += x;
		else	
		{
			crabs.push_back(stoi(temp));
			temp = "";
		}
	}
	crabs.push_back(stoi(temp));

	// may be a bit cheap but it is in the std ¯\_(ツ)_/¯
	sort(crabs.begin(), crabs.end());

	int median = crabs[crabs.size()/2];
	
	cout << "Crab Median: " << median << endl;
	cout << "Total Crabs: " << crabs.size() << endl;
	cout << "Median more left: " << crabs[crabs.size()/2 - 1] << endl;
	cout << "Median more right: " << crabs[crabs.size()/2 + 1] << endl;

	cout << "Since there are 1000 crabs the median ist between " << median <<
		" and " << crabs[crabs.size()/2 + 1] << endl;

	int fuel1 = 0;
	int fuel2 = 0;

	for(auto crab: crabs)
	{
		if(crab < median)
		{
			fuel1 += median - crab;
			fuel2 += median - crab + 1;
		}
		else if(crab > median)
		{
			fuel1 += crab - median;
			fuel2 += crab - median - 1;
		}
	}

	cout << "Fuel for " << median << ": " << fuel1 << endl;
	cout << "Fuel for " << median + 1 << ": " << fuel2 << endl;

	cout << "AoC likes the first one better so I'll have to roll with that ..." << endl;
	cout << "Solution: " << fuel1 << endl; 

	return 0;
}
