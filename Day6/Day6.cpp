using namespace std;
#define _crt_secure_no_warnings
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>

int main()
{
	fstream myfile("input.txt");
	int counter = 0;
	string line;
	int numbofnecccomponents = 0;
	vector<int> seats;
	int groupSize = 0;
	map<char, int> letNum;
	while (getline(myfile, line)) {
		if (line.size() == 0) {
			int curCount = 0;
			for (auto const& x : letNum) {
				if (x.second == groupSize)
					curCount++;
			}
			counter += curCount;
			letNum.clear();
			groupSize = 0;
		}
		else {
			groupSize++;
			for (int i = 0; i < line.size(); i++)
			{
				char curChar = line[i];
				if (letNum.find(curChar) == letNum.end())
					letNum[curChar] = 1;
				else
					letNum[curChar]++;
			}
		}
	}
	cout << counter << endl;
	printf("#############");
}
