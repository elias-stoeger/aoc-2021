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
	// Reading the input
 	fstream input;
	input.open("input1.txt", ios::in);
	
	// defining my Vars, I could have done % lineCounter to save some
	// maybe next year :/
	string line;
	int a = 0, b = 0, c = 0, d = 0;
	int counter = 0, lineTracker = 0, lineCounter = 0;

	// while there are lines to read ...
	while(getline(input, line))
	{
		// line (string) to int
		int lineN = stoi(line);
		
		// check what the lineTracker is at
		// increase vars accordingly
		if(lineTracker == 0) {
			a = lineN;
			c += lineN;
			d += lineN;

			if(b < c && lineCounter > 2)
				counter++;
		}
		else if(lineTracker == 1)
		{
			b = lineN;
			a += lineN;
			d += lineN;

			if(c < d && lineCounter > 2)
				counter++;
		}
		else if(lineTracker == 2)
		{
			c = lineN;
			a += lineN;
			b += lineN;

			if(d < a  && lineCounter > 2)
				counter++;
		}
		else if(lineTracker == 3)
		{
			d = lineN;
			b += lineN;
			c += lineN;

			if(a < b && lineCounter > 2)
				counter++;

			lineTracker = -1;
		}

		lineTracker++;
		lineCounter++;
	}
	input.close();

	cout << "There are " << counter << " times the newer sum is bigger" << endl;

	return 0;
}
