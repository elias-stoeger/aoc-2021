/* This work is licensed under the IDGAF v1.0 license, a copy should be included.
 * If I forgot to include it you may wanna google it but basically:
 *    -Do whatever but don't blame me if something bad happens
 *    -Would be cool if you credited me if you use my code but whatever
 *    -You should use the same license
 *    -or don't, just don't put some gay, lefty ethical license nonsense
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	// I read the file into input ...
 	fstream input;
	input.open("input1.txt", ios::in);

	// declare the vars I need ...
	string line;
	int horizontal = 0, depth = 0;

	// and while there are lines to analyse ...
	while(getline(input, line))
	{
		// I get the space position ...
		int spacepos = line.find(' ');

		// split into string and number by space and add/ substract accordingly.
		if(line.substr(0, spacepos) == "forward")
			horizontal += stoi(line.substr(spacepos, line.length()));
		else if(line.substr(0, spacepos) == "down")
			depth += stoi(line.substr(spacepos, line.length()));
		else
			depth -= stoi(line.substr(spacepos, line.length()));
	}

	input.close();

	cout << "The product of horizontal position and depth is " << horizontal * depth << endl;

	return 0;
}
