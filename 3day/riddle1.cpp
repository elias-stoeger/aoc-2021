/* This work is licensed under the IDGAF v1.0 license, a copy should be included.
 * If I forgot to include it you may wanna google it but basically:
 *    -Do whatever but don't blame me if something bad happens
 *    -Would be cool if you credited me if you use my code but whatever
 *    -You should use the same license
 *    -or don't, just don't put some gay, lefty ethical license nonsense
*/

#include <iostream>
#include <string>
#include <bitset>
#include <fstream>

using namespace std;

int main()
{
	// I set my values, this times I need two arrays of 12 zeros 
	// for the gamma and epsilon values 	 	
	string line;
	int gamma[12] = {0}, epsilon[12] = {0};
	int ones = 0, zeros = 0;

	// I iterate over the 12 digits, one at a time for all 1000 values
	for(int i = 0; i < 12; i++)
	{
		// because of some C++ shennanigans I have to 
		// open the input inside the loop
		fstream input;
		input.open("input1.txt", ios::in);
		
		// I count which digit occurs more often
		while(getline(input, line))
		{
			if(line[i] == '1')
				ones++;
			else
			{
				zeros++;
			}
		}
		if(ones > zeros)
			gamma[i]++;

		// I print them for debugging and sanity checks
		cout << "ones: " << ones << " -- zeros: " << zeros << endl;
		ones = 0;
		zeros = 0;
		input.close();
	}

	// I set epsilon to be the binary opposite of gamma
	for(int j = 0; j < 12; j++)
		epsilon[j] = gamma[j] * -1 + 1;
	
	// I convert them both to string
	string s_gamma = "";
	string s_epsil = "";
	for(auto k: gamma)
		s_gamma += to_string(k);
	
	for(auto l: epsilon)
		s_epsil += to_string(l);

	// And I convert the strings to decimal, treating them as binary.
	int res = stoi(s_gamma, nullptr, 2) * stoi(s_epsil, nullptr, 2);

	// Finally, the solution
	cout << "gamma * epsilon is " << res << endl;

	return 0;
}
