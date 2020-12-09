//code gebruikt van het interenet voor deel 2 want geen zin in manueel checks schrijven :(
using namespace std;
#define _crt_secure_no_warnings
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#define int long long

signed main()
{
	fstream myfile("input.txt");
	int counter = 0;
	string line;
	int operand;
	int a;
	vector<int> numbers;
	while (getline(myfile, line)) {
		stringstream ss(line);
		ss >> a;
		numbers.push_back(a);
	}
	/* part1
	vector<pair<int, int>> combos;
	for (int i = 0; i < 25; i++)
	{
		for (int j = i + 1; j < 25; j++)
			combos.push_back(make_pair(i, numbers[i] + numbers[j]));
	}
	int i;
	for (i = 25; i < numbers.size(); i++)
	{
		for (int j = i - 25; j < i - 1 && i != 25; j++)
			combos.push_back(make_pair(j, numbers[j] + numbers[i - 1]));
		bool found = false;
		for (int j = combos.size() - 1; j >= 0; j--)
		{
			if (numbers[i] == combos[j].second)
				found = true;
			if (combos[j].first == i - 25)
				combos.erase(combos.begin() + j);
		}
		if (!found)
			break;
		
	}
	cout << numbers[i] << endl;
	*/
	int i, j, sum, toFind = 26796446;
	bool found = false;
	for (i = 0; i < numbers.size() && !found; i++)
	{
		sum = numbers[i];
		for (j = i+1; j < numbers.size() && !found; j++)
		{
			sum += numbers[j];
			if (sum > toFind)
				break;
			if (sum == toFind)
				found = true;
		}
	}
	int smal = numbers[i], larg = numbers[i];
	for (int k = i; k <= j; k++)
	{
		smal = min(numbers[k], smal);
		larg = max(numbers[k], larg);
	}
	cout << smal + larg << endl;
	printf("#############");
}