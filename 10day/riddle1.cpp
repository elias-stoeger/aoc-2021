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
 	string line;
	fstream input;

	input.open("input.txt", ios::in);

	vector<string> lines;

	while(getline(input, line))
		lines.push_back(line);

	input.close();
	
	map<char, char> styles;
	styles.insert({'{', '}'});
	styles.insert({'[', ']'});
	styles.insert({'(', ')'});
	styles.insert({'<', '>'});

	map<char, int> bounty;
	bounty.insert({')', 3});
	bounty.insert({']', 57});
	bounty.insert({'}', 1197});
	bounty.insert({'>', 25137});

	int total = 0;
	for(auto chunk: lines)
	{
		vector<char> openings;
		for(auto brack: chunk)
		{
			if(brack == '{' or brack == '(' or brack == '[' or brack == '<')
				openings.push_back(brack);
			else
			{
				if(brack == styles[openings[openings.size() - 1]])
					openings.pop_back();
				else
				{
					cout << "CORRUPTION DETECTED! "
					     << openings[openings.size() - 1]
					     << " isn't closed by " << brack << endl; 
				        total += bounty[brack];
					break;	
				}
			}

		}
	}

	cout << "Total bounty: " << total << endl;

	return 0;
}

