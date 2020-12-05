using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <fstream>

int main()
{
	fstream myFile("input.txt");
	vector<int> money;
	int a;
	while (myFile >> a)
		money.push_back(a);
	for (int i = 0; i < money.size(); i++)
	{
		for (int j = 0; j < money.size(); j++)
		{
			for (int k = 0; k < money.size(); k++)
			{
				if (i != j != k) {
					if (money[i] + money[j] + money[k] == 2020)
						printf("%d %d %d", money[i], money[j], money[k]);
				}
			}
		}
	}
	printf("#############");
}
