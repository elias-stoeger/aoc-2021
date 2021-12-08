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
	vector<string> lines;

	input.open("input.txt", ios::in);

	while(getline(input, line))
		lines.push_back(line);

	input.close();

	// I assign every digit a string, all empty for now
	map<short, string> digits;
	for(short i = 0; i < 10; i++)
		digits.insert({i, ""});

	// An array for the chars a-g, a = 0, b = 1 etc.
	char chars[7] = {' '};

	// The position of the separator to differentiate input and output
	short bar = lines[0].find('|');

	int final_sum = 0;

	for(auto x: lines)
	{
		for(short i = 0; i < 10; i++)
			digits[i] = "";
		
		for(short i = 0; i < 7; i++)
			chars[i] = ' ';

		string inp = x.substr(0, bar);
		string temp = "";
		vector<string> others5;
		vector<string> others6;
		
		for(auto letter: inp)
		{
			if(letter != ' ')
				temp += letter;
			else
			{
				switch(temp.length())
				{
					case 2:
						digits[1] = temp;
						break;
					case 3:
						digits[7] = temp;
						break;
					case 4:
						digits[4] = temp;
						break;
					case 7:
						digits[8] = temp;
						break;
					case 5:
						others5.push_back(temp);
						break;
					default:
						others6.push_back(temp);
				}
				temp = "";
			}
		}

		// getting a
		for(char c: digits[7])
		{
			bool found = false;
			for(char c2: digits[1])
				if(c == c2)
					found = true;
			if(!found)
				chars[0] = c;
		}

		// getting 6
		for(auto dig: others6)
		{
			int counter = 0;
			for(char c: dig)
			{
				for(char c2: digits[1])
				{
					if(c == c2)
						counter++;
				}
			}
			if(counter != 2)
				digits[6] = dig;
		}

		// getting c and f
		for(char c: digits[6])
		{
			bool found = false;
			for(char c2: digits[1])
				if(c == c2)
					found = true;
			if(found)
			{
				chars[5] = c;
				for(char c3: digits[1])
					if(c3 != c)
						chars[2] = c3;
				break;
			}
		}

		// getting 3
		for(auto dig: others5)
		{
			int counter = 0;
			for(char c: dig)
				if(c == chars[0] or c == chars[2] or c == chars[5])
					counter++;
			if(counter == 3)
				digits[3] = dig;
		}

		// getting 2 and 5
		for(auto dig: others5)
		{
			if(dig != digits[3])
			{
				bool foundf = false;
				bool foundc = false;
				for(auto c: dig)
				{
					if(c == chars[5])
						foundf = true;
					else if(c == chars[2])
						foundc = true;
				}
				if(foundf)
					digits[5] = dig;
				else if(foundc)
					digits[2] = dig;
			}
		}

		// getting e
		for(char c: digits[6])
		{
			bool found = false;
			for(char c2: digits[5])
				if(c == c2)
					found = true;
			if(!found)
				chars[4] = c;
		}

		// getting 9 and 0
		for(auto dig: others6)
		{
			bool found = false;
			if(dig != digits[6])
			{
				found = false;
				for(char c: dig)
				{
					if(c == chars[4])
						found = true;
				}
				
				if(found){
					digits[0] = dig;
					break;
				}
						
			}
		}
		for(auto dig: others6)
		{
			if(dig != digits[0] and dig != digits[6])
			{
				digits[9] = dig;
			}
		}

		// The actual calculation
		string out = x.substr(bar + 1, x.length()) + " ";
		vector<string> outs;
		temp = "";
		string num = "";
		for(auto letter: out)
		{
			if(letter != ' ')
				temp += letter;
			else
			{
				for(int i = 0; i < 10; i++)
				{
					int counter = 0;
					for(auto c: temp)
					{
						if(temp.length() == digits[i].length())
							for(auto c2: digits[i])
								if(c == c2)
									counter++;
					}
					if(counter == temp.length() and counter != 0)
						num += to_string(distance(digits.begin(), digits.find(i)));
				}

				temp = "";
			}
		}
		final_sum += stoi(num);
	}

	cout << "The final sum of all the deciphered digits: \n" << final_sum << endl;

	return 0;
}
