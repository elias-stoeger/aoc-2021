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
#include <algorithm>

using namespace std;

vector<pair<short, short>> finder(pair<short, short> pos, vector<string> lines, int level)
{
	vector<pair<short, short>> extra;
	int maxl = lines[0].length() - 1;
	int maxh = lines.size() - 1;
	char num = lines[pos.second][pos.first] - '0';
	// look around if not an edge piece or corner
	if(pos.first > 0 and pos.first < lines[0].length() - 1 and pos.second > 0 and
	   pos.second < lines.size() - 1)
	{
		// check all 8 fields around it
		if(lines[pos.second - 1][pos.first - 1] -'0' == num + 1)
			extra.push_back(pair<short, short>(pos.first - 1, pos.second - 1));
		
		if(lines[pos.second - 1][pos.first] -'0' == num + 1)
			extra.push_back(pair<short, short>(pos.first, pos.second - 1));

		if(lines[pos.second - 1][pos.first + 1] -'0' == num + 1)
			extra.push_back(pair<short, short>(pos.first + 1, pos.second - 1));
	
		if(lines[pos.second][pos.first - 1] -'0' == num + 1)
			extra.push_back(pair<short, short>(pos.first - 1, pos.second));
		
		if(lines[pos.second][pos.first + 1] -'0' == num + 1)
			extra.push_back(pair<short, short>(pos.first + 1, pos.second));
		
		if(lines[pos.second + 1][pos.first - 1] -'0' == num + 1)
			extra.push_back(pair<short, short>(pos.first - 1, pos.second + 1));
		
		if(lines[pos.second + 1][pos.first] -'0' == num + 1)
			extra.push_back(pair<short, short>(pos.first, pos.second + 1));
		
		if(lines[pos.second + 1][pos.first + 1] -'0' == num + 1)
			extra.push_back(pair<short, short>(pos.first + 1, pos.second + 1));
	}
	// corners
	// top left
	else if(pos.first == 0 and pos.second == 0)
	{
		if(lines[0][1] - '0' == num + 1)
	       		extra.push_back(pair<short, short>(1, 0));
		if(lines[1][0] - '0' == num + 1)
			extra.push_back(pair<short, short>(0, 1));
		if(lines[1][1] - '0' == num + 1)
			extra.push_back(pair<short, short>(1, 1));
	}
	// top right
	else if(pos.first == maxl and pos.second == 0)
	{
		if(lines[0][maxl - 1] - '0' == num + 1)
	       		extra.push_back(pair<short, short>(maxl - 1, 0));
		if(lines[1][maxl - 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(maxl - 1, 1));
		if(lines[1][maxl] - '0' == num + 1)
			extra.push_back(pair<short, short>(maxl, 1));
	}
	// bottom left
	else if(pos.first == 0 and pos.second == maxh)
	{
		if(lines[maxh][1] - '0' == num + 1)
	       		extra.push_back(pair<short, short>(1, maxh));
		if(lines[maxh - 1][0] - '0' == num + 1)
			extra.push_back(pair<short, short>(0, maxh - 1));
		if(lines[maxh - 1][1] - '0' == num + 1)
			extra.push_back(pair<short, short>(1, maxh - 1));
	}
	// bottom right
	else if(pos.first == maxl and pos.second == maxh)
	{
		if(lines[maxh][maxl - 1] - '0' == num + 1)
	       		extra.push_back(pair<short, short>(maxl - 1, maxh));
		if(lines[maxh - 1][maxl] - '0' == num + 1)
			extra.push_back(pair<short, short>(maxl, maxh - 1));
		if(lines[maxh - 1][maxl - 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(maxl - 1, maxh - 1));
	}
	// edges
	// top
	else if(pos.first == 0)
	{
		if(lines[0][pos.first - 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first - 1, 0));
		if(lines[0][pos.first + 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first + 1, 0));
		if(lines[1][pos.first - 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first - 1, 1));
		if(lines[1][pos.first] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first, 1));
		if(lines[1][pos.first + 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first + 1, 1));
	}
	// left
	else if(pos.second == 0)
	{
		if(pos.first == 82)
			cout << "HERE" << " Level: " << num + 1 << endl;
		if(lines[0][pos.first - 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first - 1, 0));
		if(lines[0][pos.first + 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first + 1, 0));
		if(lines[1][pos.first - 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first - 1, 1));
		if(lines[1][pos.first] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first, 1));
		if(lines[1][pos.first + 1] - '0' == num + 1)
		{
			if(pos.first == 82)
				cout << "Here 2" << endl;
			extra.push_back(pair<short, short>(pos.first + 1, 1));
		}
	}
	// right
	else if(pos.first == maxl)
	{
		if(lines[pos.second - 1][maxl] - '0' == num + 1)
			extra.push_back(pair<short, short>(maxl, pos.second - 1));
		if(lines[pos.second - 1][maxl - 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(maxl - 1, pos.second - 1));
		if(lines[pos.second][maxl - 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(maxl - 1, pos.second));
		if(lines[pos.second + 1][maxl] - '0' == num + 1)
			extra.push_back(pair<short, short>(maxl, pos.second + 1));
		if(lines[pos.second + 1][maxl - 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(maxl - 1, pos.second + 1));
	}
	// bottom
	else if(pos.second == maxh)
	{
		if(lines[maxh][pos.first - 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first - 1, maxh));
		if(lines[maxh][pos.first + 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first + 1, maxh));
		if(lines[maxh - 1][pos.first - 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first - 1, maxh - 1));
		if(lines[maxh - 1][pos.first] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first, maxh - 1));
		if(lines[maxh - 1][pos.first + 1] - '0' == num + 1)
			extra.push_back(pair<short, short>(pos.first + 1, maxh - 1));
	}
	else
		cout << "Major Bruh Moment ..." << endl;

	//for(auto x: extra)
	//	cout << "extra: " << x.first << " - " << x.second << endl; 	

	return extra;
}

int main()
{
 	string line;
	fstream input;

	input.open("input.txt");

	vector<string> lines;
	while(getline(input, line))
		lines.push_back(line);
	
	// x, y coordinates for all lows
	vector<pair<short, short >> lows;
	int line_length = lines[0].length();
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

	cout << "Amount of lows: " << lows.size() << endl;
	
	//for(auto x: lows)
	//	cout << x.first << " - " << x.second << endl;

	// finding all basins
	//vector<pair<short, short>> test_lows;
	//test_lows.push_back(lows[1]);
	

	for(auto x: lows)
		cout << x.first << " - " << x.second << endl;
	vector<int> basins;
	vector<pair<short, short>> used;
	for(auto low: lows)
	{
		int level = lines[low.second][low.first] - '0';
		vector<pair<short, short>> new_coords;
		vector<pair<short, short>> to_search;
		to_search.push_back(low);
		bool over = false;
		while(level < 9 and !over)
		{
			if(level == 8)
			{
				over = true;
				level = 7;
			}
		       			
			//cout << level << endl;
			vector<pair<short, short>> newest;

			for(auto x: to_search)
			{
				vector<pair<short, short>> found = finder(x, lines, level);
				if(found.size() > 0)
				{
					for(auto y: found)
						newest.push_back(y);
				}
			}
		
			for(auto bas: to_search)
			{
				bool init = false;
				for(auto bas2: new_coords)
					if(bas2 == bas)
						init = true;
				for(auto bas2: used)
					if(bas2 == bas)
						init = true;
				if(!init)
					new_coords.push_back(bas);
			}

			to_search.clear();

			for(auto bas: newest)
				to_search.push_back(bas);

			level++;
		}
		/*
		cout << "-----" << endl;
		for(auto x: new_coords)
		{
			cout << lines[x.second][x.first] << " - " << x.first << " ~ " << x.second << endl;
		}
		*/
		basins.push_back(new_coords.size());
		for(auto x: new_coords)
			used.push_back(x);
		new_coords.clear();
	}
	
	sort(basins.begin(), basins.end());
	int max = basins.size() - 1;

	cout << "----- " << endl;
	for(auto x: basins)
		cout << x << endl;
	
	cout << "Product of biggest three basins: " <<
		basins[max] * basins[max - 1] * basins[max - 2] << endl;
		
	return 0;
}
