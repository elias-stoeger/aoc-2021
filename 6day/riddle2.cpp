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
#include <map>

using namespace std;

int main()
{
	// My school of fish
 	map<short, long long int> school;
	school.insert({0, 0});	
	school.insert({1, 0});
	school.insert({2, 0});
	school.insert({3, 0});
	school.insert({4, 0});
	school.insert({5, 0});
	school.insert({6, 0});
	school.insert({7, 0});
	school.insert({8, 0});

	vector<int> inp;
	string line;
	fstream input;
	
	// Reading the input, a bit quicker than usual since it is only one line
	input.open("input1.txt", ios::in);

	getline(input, line);
	
	for(auto x: line)
		if(x != ',')
			// apparantly that converts chars to ints
			inp.push_back(x - '0');	
	
	input.close();

	for(short x: inp)
		school[x] += 1;	

	for(short i = 0; i < 256; i++)
	{
		// Since I am expecting some really big numbers I'd better take long long int
		// spawn is the changes happening each day	
		long long int spawn[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
 		for(auto const& fish: school)
		{
			// Writing the changes to spawn
			if(fish.first != 0)
			{
				spawn[fish.first - 1] += fish.second;
			}
			else
			{
				spawn[6] += fish.second;
				spawn[8] += fish.second;
			}
		}

		// The spawn is old enough to join the swarm now
		for(short c = 0; c < 9; c++)
			school[c] = spawn[c];

		cout << "Day " << i+1 << ": " << school[0] + school[1] + school[2] + school[3]
		       + school[4] + school[5] + school[6] + school[7] + school[8] << endl;
	}

	return 0;
}
