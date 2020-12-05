//code gebruikt van het interenet voor deel 2 want geen zin in manueel checks schrijven :(
using namespace std;
#define _crt_secure_no_warnings
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

int main()
{
	fstream myfile("input.txt");
	int counter = 0;
	string line;
	int numbofnecccomponents = 0;
	while (getline(myfile, line)) {
		if (line.size() == 0) {
			if (numbofnecccomponents == 7)
				counter++;
			numbofnecccomponents = 0;
		}
		else {
			if (line.find("byr") != string::npos)
				numbofnecccomponents++;
			if (line.find("iyr") != string::npos)
				numbofnecccomponents++;
			if (line.find("eyr") != string::npos)
				numbofnecccomponents++;
			if (line.find("hgt") != string::npos)
				numbofnecccomponents++;
			if (line.find("hcl") != string::npos)
				numbofnecccomponents++;
			if (line.find("ecl") != string::npos)
				numbofnecccomponents++;
			if (line.find("pid") != string::npos)
				numbofnecccomponents++;
		}
	}
	cout << counter << endl;
	printf("#############");
}