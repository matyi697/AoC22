#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;

struct
{
	vector<string>ellen;
	vector<string>sajat;
	int darab = 0;
}rock;

void beolvasas()
{
	std::ifstream beol;
	beol.open("inputday2.txt");
	string temp;
	while (std::getline(beol,temp))
	{
		cout << temp;
		rock.ellen.push_back(temp.substr(0,1));
		rock.sajat.push_back(temp.substr(1,1));
		rock.darab++;
	}
	beol.close();
}
int main()
{
	beolvasas();
	cout << rock.darab;
}