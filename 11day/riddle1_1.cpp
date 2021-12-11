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

class octopus{
	public:
		short energy;
		short x;
		short y;
		bool counted = false;
		bool flashed = false;
};

int main()
{
 	string line;
	fstream input;

	input.open("input_test.txt", ios::in);
	
	short x_coord = 0;
	short y_coord = 0;
	vector<vector<octopus>> school;
	while(getline(input, line))
	{
		vector<octopus> octoline;
		octopus octo;
		for(auto x: line)
		{
			octo.energy = x - '0';
			octo.y = y_coord;
			octo.x = x_coord;
			octoline.push_back(octo);
			x_coord++;
		}
		school.push_back(octoline);
		octoline.clear();
		y_coord++;
	}

	input.close();

	for(auto pus: school)
	{
		for(auto octo: pus)
			cout << octo.energy;
		cout << endl;
	}

	int flashes = 0;
	octopus helpo;
	for(int i = 0; i < 2; i++)
	{
		int flashing = 0;
		
		for(int group = 0; group < school.size(); group++)
			for(int pus = 0; pus < school[0].size(); pus++)
			{
				school[group][pus].energy++;
				if(school[group][pus].energy > 9)
				{
					school[group][pus].energy = 0;
					school[group][pus].flashed = true;
				}
			}
		cout << "Round: " << i << endl;

		do
		{
			flashes = 0;
			for(int y = 0; y < school.size(); y++)
			{
				for(int x = 0; x < school[0].size(); x++)
				{
					octopus flasho = school[y][x];
					if(flasho.flashed == true and !flasho.counted)
					{
						school[y][x].counted = true;
						int maxl = school[0].size();
						int maxh = school.size();
						// level
						if(x - 1 >= 0 and !school[y][x - 1].flashed)
							school[y][x - 1].energy++;
						if(x + 1 <  maxl and !school[y][x + 1].flashed)
							school[y][x + 1].energy++;
						// above
						if(y - 1 > 0 and !school[y - 1][x - 1].flashed)
							school[y - 1][x - 1].energy++;
						if(y - 1 > 0 and !school[y - 1][x].flashed)
							school[y - 1][x].energy++;
						if(y - 1 > 0 and !school[y - 1][x + 1].flashed)
							school[y - 1][x + 1].energy++;
						// below
						if(y + 1 < maxh and !school[y + 1][x - 1].flashed)
							school[y + 1][x - 1].energy++;
						if(y + 1 < maxh and !school[y + 1][x].flashed)
							school[y + 1][x].energy++;
						if(y + 1 < maxh and !school[y + 1][x + 1].flashed)
							school[y + 1][x + 1].energy++;
	
					}
				}
			}
			
			for(int y = 0; y < school.size(); y++)
			{
				for(int x = 0; x < school[0].size(); x++)
				{
					if(school[y][x].energy > 9)
					{
						school[y][x].energy = 0;
						school[y][x].flashed = true;
						flashes++;
					}
				}
			}
				
		}
		while(flashes != 0);
	}

	cout << " --------- " << endl;	
	for(auto pus: school)
	{
		for(auto octo: pus)
			cout << octo.energy;
		cout << endl;
	}

	cout << "Total flashes: " << flashes << endl;
	
	return 0;
}
