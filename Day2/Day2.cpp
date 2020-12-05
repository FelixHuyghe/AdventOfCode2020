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
	int minN, maxN, charCount, dashPos, colonPos;
	char c;
	while (getline(myFile, line)) {
		charCount = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == '-') {
				dashPos = i;
				string sub = line.substr(0, i);
				stringstream ss(sub);
				ss >> minN;
			}
			else if (line[i] == ':') {
				colonPos = i;
				stringstream ss(line.substr(dashPos + 1, i - 3 - dashPos));
				ss >> maxN;
				c = line[i - 1];
			}
			/*else if (i >= 7) {
				if (line[i] == c)
					charCount++;
			}*/
		}
		/*if (charCount >= minN && charCount <= maxN)
			counter++;*/
		int right = 0;
		if (line[colonPos + 2 + minN - 1] == c)
			right++;
		if (line[colonPos + 2 + maxN - 1] == c)
			right++;
		if (right == 1)
			counter++;
	}
	cout << counter << endl;
	printf("#############");
}
