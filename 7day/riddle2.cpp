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

	// Maybe I'm wrong but if I use floats and round the value is
	// wrong in the end, "to low", that seems a bit dishonest but okay ...
	int sum = 0, average = 0, fuel = 0;

	for(auto crab: crabs)
		sum += crab;

	average = sum / crabs.size();
	cout << "Average crab: " << average << endl;

	for(auto crab: crabs)
	{
		if(crab < average)
			fuel += (average - crab) * (average - crab + 1) / 2;
		else if(crab > average)
			fuel += (crab - average) * (crab - average + 1) / 2;
	}

	cout << fixed << "Minimal fuel: " << fuel << endl;

	return 0;
}
