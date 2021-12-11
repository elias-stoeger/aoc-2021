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
	vector<string> lines;

	input.open("input_test.txt", ios::in);
	while(getline(input, line))
		lines.push_back(line);

	vector<vector<short>> octs;
	for(auto y: lines)
	{
		vector<short> line_n;
		for(auto x: y)
			line_n.push_back(x - '0');

		octs.push_back(line_n);
		line_n.clear();
	}

	input.close();
	
	for(auto y: octs)
	{
		for(auto x: y)
			cout << x;
		cout << endl;
	}
	
	vector<vector<short>> octs2;
	for(auto x:  octs)
		octs2.push_back(x);
	int flashes = 0;

	int y = 0;
	int x = 0;
	// The steps taken
	for(short i = 0; i < 2; i++)
	{
		vector<pair<short, short>> flashing;
		do
		{
			x = 0;
			y = 0;
			for(auto lin: octs)
			{
				for(auto oct: lin)
				{
					if(oct > 8)
					{
						flashing.push_back(pair<short, short>(x, y));
						flashes++;
						octs2[y][x] = 0;
					}
					//else
					//	cout << "... " << octs2[y][x] << endl;
					x++;
				}
				y++;
			}
			octs = octs2;
		}
		while(flashing.size() > 0);
	}

	cout << " -------- " << endl;
	for(auto y: octs)
	{
		for(auto x: y)
			cout << x;
		cout << endl;
	}

	return 0;
}
