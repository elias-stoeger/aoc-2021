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
//#include <vector>

using namespace std;

int main()
{
	// reading the input file
 	fstream input;
	input.open("input1.txt", ios::in);
	
	// initiate the vars I'll need, names are desciptive
	string line;
	int lastValue = 0;
	int counter = 0;

	// while there are new line ...
	while(getline(input, line))
	{
		// convert the line to int so I can compare them
		int lineN = stoi(line);

		// if the value increases, counter goes up and the lastValue set ...
		if(lineN > lastValue && lastValue != 0)
		{
			counter++;
			lastValue = lineN;
		// if not I just set the lastValue ...
		} else 
			lastValue = lineN;
	}
	input.close();

	cout << "There are " << counter << " measurements that are larger than the previous one" << endl;	

	return 0;
}
