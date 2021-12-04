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
#include <sstream>

using namespace std;

int check(vector<string> matrix, int round, vector<int> numbers)
{
	int checker = 0;	
	vector<int> ints;
	vector<vector<int>> real_m;
	real_m.clear();
	for(auto x: matrix)
	{
		ints.clear();
		string tracker = "";
		for(auto y: x)
		{
			if(y != ' ')
				tracker += y;
			else
			{
				if(tracker.length() != 0)
				{
					ints.push_back(stoi(tracker));
					tracker = "";	
				}
			}
		}
		ints.push_back(stoi(tracker));
		real_m.push_back(ints);
	}
	
	vector <int> bingo_nums;
	for(int i = 0; i < round; i++)
		bingo_nums.push_back(numbers[i]);

	// horizontal check
	for(auto x: real_m)
	{
		for(auto y: x)
		{
			for(auto z: bingo_nums)
			{
				if(y == z)
					checker += 1;
			}
		}
		if(checker == 5)
		{
			cout << "BINGO" << endl;
			cout << "Numbers: " << endl;
		        for(auto num: bingo_nums)
				cout << num << " ";
			cout << endl;	
			for(auto a: real_m)
			{
				for(auto b: a)
					cout << b << " ";
				cout << endl;
			}
			return 1;
		}
		checker = 0;
	}

	// vertical check
	vector<int> v_nums;
	int iter = 0;
	int counter;
	for(int i = 0; i < 5; i++)
	{
		for(auto x: real_m)
		{
			v_nums.push_back(x[iter]);	
		}	
		counter = 0;
		for(auto x: v_nums)
		{
			for(auto y: bingo_nums)
				if(x == y)
					counter++;
		}
		if(counter == 5)
		{
			cout << "BINGO VERT" << endl;
			cout << "Numbers: " << endl;
		        for(auto num: bingo_nums)
				cout << num << " ";
			cout << endl;
			int sum = 0;	
			for(auto a: real_m)
			{
				for(auto b: a)
				{
					cout << b << " ";
					sum += b;
					for(auto bin: bingo_nums)
						if(bin == b)
							sum -= b;
				}
				cout << endl;
			}
			cout << "SUM: " << sum << endl;
			cout << "Product: " << sum * bingo_nums[bingo_nums.size() - 1] << endl;
			return 1;
		}
		iter++;
		v_nums.clear();
	}
	return 0;
}

int main()
{
 	string line;
	vector<string> storage;
	string firstl = "";
	
	fstream input;
	input.open("input1.txt", ios::in);

	int counter = 0;
	while(getline(input, line))
	{
		if(counter > 1)
			storage.push_back(line);
		else
			firstl += line;
		counter++;
	}
	input.close();

	vector<int> numbers;

	string temp = "";
	for(auto x: firstl)
	{
		if(x != ',')
			temp += x;
		else
		{
			numbers.push_back(stoi(temp));
			temp = "";
		}
	}

	vector<string> tempv;
	int iter = 0;
	int curr_num = 5;
	bool found = false;

	while(!found and curr_num < numbers.size())
	{
		while(iter < storage.size() / 6 + 1)
		{
			tempv.clear();
			for(int i = iter * 6; i < iter * 6 + 5; i++)
			{
				tempv.push_back(storage[i]);
			}
			int checker = check(tempv, curr_num, numbers);
			if(checker == 1)
				found = true;
			iter++;
		}
		iter = 0;
		curr_num++;
	}
	
	return 0;
}
