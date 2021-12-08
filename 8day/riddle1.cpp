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
	vector<string> inp;
	fstream input;

	input.open("input.txt", ios::in);

	while(getline(input, line))
	{
		inp.push_back(line);		
	}

	input.close();
	
	int bar = inp[0].find('|');

	for(int i = 0; i < inp.size(); i++)
	{
		inp[i] = inp[i].substr(bar + 2, inp.size());
	}

	// For 1, 4, 7 and 8 counters
	int nums[4] = {0};

	string temp = "";
	for(auto x: inp)
	{
		for(auto y: x)
		{
			if(y != ' ' and y != '\n')
				temp += y;
			else
			{
				switch(temp.length()){
					case 2:
						nums[0]++;
						break;
					case 3:
						nums[2]++;
						break;
					case 4:
						nums[1]++;
						break;
					case 7:
						nums[3]++;
						break;
				}
					temp = "";
			}
		}
		switch(temp.length()){
			case 2:
				nums[0]++;
				break;
			case 3:
				nums[2]++;
				break;
			case 4:
				nums[1]++;
				break;
			case 7:
				nums[3]++;
				break;
			}		
		temp = "";
	}

	cout << "Total occurences of 1, 4, 7 and 8: " << nums[0] + nums[1] + nums[2] + nums[3]
	     << endl;
	
	return 0;
}
