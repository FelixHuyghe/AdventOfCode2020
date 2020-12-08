using namespace std;
#define _crt_secure_no_warnings
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
	fstream myfile("input.txt");
	int counter = 0;
	string line;
	int numbofnecccomponents = 0;
	vector<int> seats;
	int curRow = 0, curCol = 0;
	while (getline(myfile, line)) {
		curRow = 0, curCol = 0;
		for (int i = 0; i < 7; i++)
			if (line[i] == 'B')
				curRow += 1 << (7 - i - 1);
		for (int i = 0; i < 3; i++)
			if (line[7+i] == 'R')
				curCol += 1 << (3 - i - 1);
		seats.push_back(curRow * 8 + curCol);
	}
	//cout << *max_element(seats.begin(), seats.end()) << endl;
	sort(seats.begin(), seats.end());
	for (int i = 0; i < seats.size() - 1; i++)
	{
		if (seats[i] + 1 != seats[i + 1])
			cout << seats[i] + 1 << endl;
	}
	printf("#############");
}
