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
	// For this one I'll need a dictionary (I'm comming from Python)
	map<pair<int, int>, int> dic;
 	string line;
	fstream input;

	// Reading the file
	input.open("input1.txt", ios::in);
	while(getline(input, line))
	{
		// There are four numbers to consider, x1, x2, y1, y2
		int vars[4] = {0, 0, 0, 0};
		string temp = "";
		int counter = 0;	

		// I parse the lines
		for(auto x: line)
		{
			if(x != ' ' and x != '-' and x != '>' and x != ',')
				temp += x;
			else
				if(temp != "")
				{
					vars[counter] = stoi(temp);
					temp = "";
					counter++;
				}
					
					
		}
		vars[3] = stoi(temp);

		// depending on whether the direction is horizontal or vertical
		// I make pairs for the coordinates
		//
		// If the coordinate is new I set it to 1, otherwise I increase it by 1

		// vertical line
		if(vars[0] == vars[2])
		{
			if(vars[1] < vars[3])
			{
				for(int i = vars[1]; i <= vars[3]; i++)
				{
					pair<int, int> temp_p = make_pair(vars[0], i);

					if(!dic[temp_p])
						dic[temp_p] = 1;
					else
						dic[temp_p] += 1;
				}
			}
			else
			{
				for(int i = vars[3]; i <= vars[1]; i++)
				{
					pair<int, int> temp_p = make_pair(vars[0], i);
					if(!dic[temp_p])
						dic[temp_p] = 1;
					else
						dic[temp_p] += 1;
				}
			}
		}
		// horizontal line
		else if(vars[1] == vars[3])
		{
			if(vars[0] < vars[2])
			{
				for(int i = vars[0]; i <= vars[2]; i++)
				{
					pair<int, int> temp_p = make_pair(i, vars[3]);
					if(!dic[temp_p])
						dic[temp_p] = 1;
					else
						dic[temp_p] += 1;
				}
			}
			else
			{
				for(int i = vars[2]; i <= vars[0]; i++)
				{
					pair<int, int> temp_p = make_pair(i, vars[3]);
					if(!dic[temp_p])
						dic[temp_p] = 1;
					else
						dic[temp_p] += 1;
				}
			}

		}
		// diagonal line, not the most elegant solution I'll admit
		//
		// Here it is just important to make sure you oprtant to operate on the
		// same x and y, if you accidentally count up/ down x1 and y2 that's bad
		else
		{
			if(vars[0] > vars[2])
			{
				if(vars[1] > vars[3])
					for(int i = vars[0], j = vars[1]; i >= vars[2]; i--, j--)
					{
						pair<int, int> temp_p = make_pair(i, j);
						if(!dic[temp_p])
							dic[temp_p] = 1;
						else
							dic[temp_p] += 1;
					}
				else
					for(int i = vars[0], j = vars[1]; i >= vars[2]; i--, j++)
					{
						pair<int, int> temp_p = make_pair(i, j);
						if(!dic[temp_p])
							dic[temp_p] = 1;
						else
							dic[temp_p] += 1;
					}
			}
			else
			{
				if(vars[1] > vars[3])
					for(int i = vars[0], j = vars[1]; i <= vars[2]; i++, j--)
					{
						pair<int, int> temp_p = make_pair(i, j);
						if(!dic[temp_p])
							dic[temp_p] = 1;
						else
							dic[temp_p] += 1;
					}
				else
					for(int i = vars[0], j = vars[1]; i <= vars[2]; i++, j++)
					{
						pair<int, int> temp_p = make_pair(i, j);
						if(!dic[temp_p])
							dic[temp_p] = 1;
						else
							dic[temp_p] += 1;
					}	
			}
		}
	}

	// In the end I count the dictionary entries with a value greater than 1 ...
	int counter = 0;
	for(const auto& x: dic)
	{
		if(x.second > 1)
			counter++;
	}

	// and print the result
	cout << "There are " << counter << " points where at least two lines overlap." << endl;

	return 0;
}
