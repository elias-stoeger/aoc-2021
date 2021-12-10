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
#include <algorithm>

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
	bounty.insert({')', 1});
	bounty.insert({']', 2});
	bounty.insert({'}', 3});
	bounty.insert({'>', 4});

	vector<long int> total;
	for(auto chunk: lines)
	{
		vector<char> openings;
		bool corrupted = false;
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
					corrupted = true;
					break;	
				}
			}

		}
		if(!corrupted)
		{
			long int sub_total = 0;
			for(int i = openings.size() - 1; i >= 0; i--)
			{
				sub_total *= 5;
				sub_total += bounty[styles[openings[i]]];
			}
			total.push_back(sub_total);

		}
	}

	sort(total.begin(), total.end());

	cout << "Middle score: " << total[(total.size() - 1) / 2] << endl;

	return 0;
}
