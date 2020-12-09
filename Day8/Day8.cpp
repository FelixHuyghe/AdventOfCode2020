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

int main()
{
	fstream myfile("input.txt");
	int counter = 0;
	string line;
	vector<pair<string, int>> instructions;
	string s;
	int operand;
	while (getline(myfile, line)) {
		stringstream ss(line);
		ss >> s >> operand;
		instructions.push_back(make_pair(s, operand));
	}
	int numberToFind = instructions.size();
	bool found = false;
	int acc = 0;
	int i = -1;
	while (!found) {
		i++;
		if (instructions[i].first == "jmp")
			instructions[i].first = "nop";
		else if (instructions[i].first == "nop")
			instructions[i].first = "jmp";
		else
			continue;
		bitset<1000> visited;
		acc = 0;
		int pos = 0;
		while (1) {
			if (pos == numberToFind) {
				found = true;
				break;
			}
			if (visited[pos])
				break;
			else
				visited[pos] = true;
			string ins = instructions[pos].first;
			int op = instructions[pos].second;
			if (ins == "nop") {
				pos++;
				continue;
			}
			else if (ins == "acc") {
				pos++;
				acc += op;
			}
			else if (ins == "jmp") {
				pos += op;
			}
		}
		if (instructions[i].first == "jmp")
			instructions[i].first = "nop";
		else if (instructions[i].first == "nop")
			instructions[i].first = "jmp";
	}
	cout << acc << endl;
	printf("#############");
}
