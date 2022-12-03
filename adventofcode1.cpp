#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;
struct 
{
	int manok=0;
	int hanyadik = 1;
	int top[3];
	vector<int> kaloriak;
	int ans = 0;
} elsof;
void elsofeladat()
{
	std::ifstream beolvas;
	beolvas.open("input.txt");
	int temp = 0;
	int p = 0;
	string picsa;
	while (std::getline(beolvas,picsa))
	{
		if (picsa =="")
		{
			elsof.kaloriak.push_back(temp);
			if (temp > elsof.manok)
			{
				elsof.manok = temp;
			}
			temp = 0;
			elsof.hanyadik++;
		}
		else
		{
			temp += std::stoi(picsa);
		}
	}
	p = elsof.kaloriak.size();
	temp = 0;
	int topg = 0;
	for (int u = 0; u < 3; u++)
	{
		for (int i = 0; i < p; i++)
		{
			if (u == 0)
			{
				if (temp < elsof.kaloriak[i])
				{
					temp = elsof.kaloriak[i];
				}
				elsof.top[u] = temp;
			}
			else
			{
				if (temp < elsof.kaloriak[i]&&temp<topg&&elsof.kaloriak[i]<topg)
				{
					temp = elsof.kaloriak[i];
					}
				elsof.top[u] = temp;
			}
		}
		topg = temp;
		temp = 0;
		elsof.ans += elsof.top[u];
	}
}
int main()
{
	elsofeladat();
	cout << "osszesen " << elsof.ans << " kaloriat vittek magukkal";
}