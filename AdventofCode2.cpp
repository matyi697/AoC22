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
	vector<int>pontszamom;
	int sajatpontom = 0;
	int darab = 0;
}rock;

void beolvasas()
{
	std::ifstream beol;
	beol.open("inputday2.txt");
	string temp;
	while (std::getline(beol, temp))
	{
		rock.ellen.push_back(temp.substr(0, 1));
		rock.sajat.push_back(temp.substr(2, 1));
		rock.darab++;
	}
	beol.close();
}

int ellensegcsuzli(string apadfasza)
{
	if (apadfasza == "A")
	{
		return 1;
	}
	else
	{
		if (apadfasza == "B")
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
}
int sajatcsuzli(string apadfasza)
{
	if (apadfasza == "X")
	{
		return 0;
	}
	else
	{
		if (apadfasza == "Y")
		{
			return 3;
		}
		else
		{
			return 6;
		}
	}
}
int vegkimenetel(int ellenpont, int sajatpont)
{
	if (ellenpont == 1)
	{
		if (sajatpont == 0)
		{
			return 3;
		}
		else
		{
			if (sajatpont == 3)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
	if (ellenpont == 2)
	{
		if (sajatpont == 0)
		{
			return 1;
		}
		else
		{
			if (sajatpont == 3)
			{
				return 2;
			}
			else
			{
				return 3;
			}
		}
	}
	if (ellenpont == 3)
	{
		if (sajatpont == 0)
		{
			return 2;
		}
		else
		{
			if (sajatpont == 3)
			{
				return 3;
			}
			else
			{
				return 1;
			}
		}
	}
}
void pontszamitas()
{
	rock.darab = rock.sajat.size();
	rock.sajatpontom = 0;
	int u = 0;
	int temp = 0;
	while (u != rock.darab)
	{
		rock.sajatpontom += vegkimenetel(ellensegcsuzli(rock.ellen[u]), sajatcsuzli(rock.sajat[u])) + sajatcsuzli(rock.sajat[u]);
		u++;
	}
}
int main()
{
	beolvasas();
	pontszamitas();
	cout << rock.sajatpontom<<"\n";
}