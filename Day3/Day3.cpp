using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

int main()
{
	fstream myFile("input.txt");
	int counter = 0;
	string line;
	int x = 0;
	int y = -1;
	char c;
	while (getline(myFile, line)) {
		if (++y % 1 == 0) {
			cout << "checking: " << x % line.size() << " on line " << y << endl;
			cout << line << endl;
			if (line[x % line.size()] == '#')
				counter++;
			x += 7;
		}
	}
	cout << counter << endl;
	printf("#############");
}
