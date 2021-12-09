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

	input.open("input_test.txt");

	vector<string> lines;
	while(getline(input, line))
		lines.push_back(line);

	//int sum = 0;
	int line_length = lines[0].length();
	vector<pair<short, short>> lows;
	for(int i = 0; i < lines.size(); i++)
	{
		string current = lines[i];

		// The first line
		if(i == 0)
		{
			string after = lines[i + 1];
			for(int j = 1; j < line_length - 1; j++)
			{
				if(current[j] < current[j - 1] and current[j] < current[j + 1]
				   and current[j] < after[j - 1] and current[j] < after[j]
				   and current[j] < after[j + 1])
					lows.push_back(pair<short, short>(j, i));
			}
		}
		// The last line
		else if(i == lines.size() - 1)
		{
			string before = lines[i - 1];
			for(int j = 1; j < line_length - 1; j++)
			{
				if(current[j] < current[j - 1] and current[j] < current[j + 1]
				   and current[j] < before[j - 1] and current[j] < before[j]
				   and current[j] < before[j + 1])
					lows.push_back(pair<short, short>(j, i));
			}
		}
		// The main part
		else
		{
			string before = lines[i - 1];
			string after = lines[i + 1];
			for(int j = 1; j < line_length - 1; j++)
			{
				if(current[j] < current[j - 1] and current[j] < current[j + 1]
				   and current[j] < after[j - 1] and current[j] < after[j]
				   and current[j] < after[j + 1] and current[j] < before[j - 1]
				   and current[j] < before[j] and current[j] < before[j + 1])
					lows.push_back(pair<short, short>(j, i));
			}
			// edges
			// left
			char edge = current[0];
			if(edge < current[1] and edge < before[0] and edge < before[1] and
			   edge < after[0] and edge < after[1])
				lows.push_back(pair<short, short>(0, i));

			// right
			edge = current[line_length - 1];
			if(edge < current[line_length - 2] and edge < before[line_length - 1] 
			   and edge < before[line_length - 2] and edge < after[line_length - 1] 
			   and edge < after[line_length - 2])
				lows.push_back(pair<short, short>(line_length - 1, i));
		}
	}
	// The corners
	
	// top left
	char corner = lines[0][0];
	if(corner < lines[0][1] and corner < lines[1][0] and corner < lines[1][1])
		lows.push_back(pair<short, short>(0, 0));

	// top right
	corner = lines[0][line_length - 1];
	if(corner < lines[0][line_length - 2] and corner < lines[1][line_length - 1] 
	   and corner < lines[1][line_length - 2])
		lows.push_back(pair<short, short>(line_length - 1, 0));

	// bottom left
	int last = lines.size() - 1;
	corner = lines[last][0];
	if(corner < lines[last][1] and corner < lines[last - 1][0] 
	   and corner < lines[1][line_length - 2])
		lows.push_back(pair<short, short>(0, last));

	// bottom right
	corner = lines[last][line_length - 1];
	if(corner < lines[last][line_length - 2] and corner < lines[last - 1][line_length - 1] 
	   and corner < lines[last - 1][line_length - 2])
		lows.push_back(pair<short, short>(line_length - 1, last));

	cout << "All low points: " << endl;
	for(auto low: lows)
		cout << low.first << " - " << low.second << ": " << lines[low.second][low.first]
		     << endl;


	return 0;
}
