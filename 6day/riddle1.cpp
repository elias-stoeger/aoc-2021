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

// A basic lanternfish
class Fish {
	public:
		short days;
};

int main()
{
	// My school of fish
 	vector<Fish> school;
	vector<int> inp;
	string line;
	fstream input;
	
	input.open("input1.txt", ios::in);

	getline(input, line);
	
	for(auto x: line)
		if(x != ',')
			// apparantly that converts chars to ints
			inp.push_back(x - '0');	
	
	// adding some fish to my swarm	
	for(int x: inp)
	{
		Fish fishy;
		fishy.days = x;
		school.push_back(fishy);	
	}

	// Spawn is the newly born fish
	vector<Fish> spawn;
	for(int i = 0; i < 80; i++)
	{
		spawn.clear();
		for(auto &fish: school)
		{
			if(fish.days == 0)
			{
				Fish fishy;
				fishy.days = 8;
				spawn.push_back(fishy);
				fish.days = 6;
			}
			else
			{
				fish.days--;
			}
		}

		// The spawn is added to the school
		for(auto fish: spawn)
			school.push_back(fish);

		cout << "Day: " << i+1 << " Size: " << school.size() << endl;
	}

	cout << "After 80 days there will be " << school.size() << " lanternfish" << endl;

	return 0;
}
