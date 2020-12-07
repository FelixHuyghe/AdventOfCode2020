//code gebruikt van het interenet voor deel 2 want geen zin in manueel checks schrijven :(
using namespace std;
#define _crt_secure_no_warnings
using namespace std;

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

struct bag {
	string color;
	vector<string> holding;
	vector<int> numbersholding;
};

vector<bag> bags;

int howManyBags(string s, int c) {
	for (int i = 0; i < bags.size(); i++)
	{
		if (bags[i].color == s) {
			if (bags[i].holding.size() == 0)
				return c;
			else {
				int som = 0;
				for (int j = 0; j < bags[i].holding.size(); j++)
					som += c * howManyBags(bags[i].holding[j], bags[i].numbersholding[j]);
				return som + c;
			}
		}
	}
	return c;
}

int main()
{
	fstream myfile("input.txt");
	int counter = 0;
	string line;
	queue<string> idQ;
	vector<int> countGold;
	set<string> idSet;
	while (getline(myfile, line)) {
		stringstream ss(line);
		string s;
		int i = 0;
		bag b;
		vector<string> appHolding;
		vector<string> colorsHolding;
		string appearence, color;
		b.numbersholding = vector<int>();
		while (ss >> s)
		{
			if (s == "no")
				break;
			else if (i == 0) {
				appearence = s;
				i++;
			}
			else if (i == 1) {
				color = s;
				i++;
			}
			else if (s.substr(0, 3) == "bag")
				continue;
			else if (s == "contain")
				continue;
			else if (i == 2) {
				int t = stoi(s);
				b.numbersholding.push_back(t);
				i++;
			}
			else if (i == 3) {
				appHolding.push_back(s);
				i++;
			}
			else if (i == 4) {
				colorsHolding.push_back(s);
				i = 2;
			}
		}
		b.color = appearence + color;
		vector<string> holding;
		for (int i = 0; i < appHolding.size(); i++) {
			string s = appHolding[i] + colorsHolding[i];
			if (b.color == "shinygold") {
				countGold.push_back(b.numbersholding[i]);
				idQ.push(s);
				idSet.insert(s);
			}
			holding.push_back(s);
		}
		b.holding = holding;
		bags.push_back(b);
	}
	//partOne
	/*while (!idQ.empty()) {
		string s = idQ.front();
		idQ.pop();
		for (int i = 0; i < bags.size(); i++)
		{
			for (int j = 0; j < bags[i].holding.size(); j++)
			{
				if (bags[i].holding[j] == s) {
					idQ.push(bags[i].color);
					idSet.insert(bags[i].color);
				}
			}
		}
	}*/
	int i = 0;
	int total = 0;
	while (!idQ.empty()) {
		string s = idQ.front();
		idQ.pop();
		int t = howManyBags(s, countGold[i++]);
		total += t;
	}
	cout << total << endl;
	printf("#############");
}