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

// This time, I need to define a function to help me with reducing the values
vector<string> reduce(vector<string> vec, int iteration, string amount)
{
	vector<string> new_vec_1 = {};
	vector<string> new_vec_0 = {};
	for(auto x: vec)
	{
		if(int(x[iteration]) - 48 == 1)
			new_vec_1.push_back(x);
		else
			new_vec_0.push_back(x);
	}

	if(amount == "more")
		if(new_vec_1.size() >= new_vec_0.size())
			return new_vec_1;
		else
			return new_vec_0;
	else
		if(new_vec_1.size() >= new_vec_0.size())
			return new_vec_0;
		else
			return new_vec_1;
}

int main()
{
	// I read the values into a vector so that I can play with its size ...
 	string line;
	vector<string> inp = {};

	fstream input;
	input.open("input1.txt", ios::in);

	while(getline(input, line))
	{
		inp.push_back(line);
	}

	// declare some vars ...
	vector<string> least = {};
	vector<string> most = {};

	int size = 1000;
	int iter = 0;
	vector<string> new_v = inp;

	// and call the function as long as there is either only one more entry left
	// or I am at the last bite (the 12th)
	while(size > 1 and iter < 12)
	{
		new_v = reduce(new_v, iter, "more");
		size = new_v.size();
		iter++;
	}
	most = new_v;
	
	size = 1000;
	iter = 0;
	new_v = inp;
	while(size > 1 and iter < 12)
	{
		new_v = reduce(new_v, iter, "less");
		size = new_v.size();
		iter++;
	}
	least = new_v;

	// Then I read the vectors into string
	string oxy = "", co2 = "";
	for(auto bin: most)
		oxy += bin;

	for(auto bin: least)
		co2 += bin;

	// and convert from binary to decimal ints to calculate the product
	cout << "The submarines life support rating is " 
	     << stoi(oxy, nullptr, 2) * stoi(co2, nullptr, 2) << endl;  	

	input.close();
	return 0;	
}
