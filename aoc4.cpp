#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::string;
string data[9] = {"RNFVLJSM","PNDZFJWH","WRCDG","NBS","MZWPCBFN","PRMW","RTNGLSW","QTHFNBV","LMHZNF"};//hehe basszam beleje, faszom olvassa be azt a salatat
void cserebere(int mennyi, int honnan, int hova)
{
	string temp;
	string temp2;
	int x = 0;
	temp = data[honnan];
	temp2 = data[hova];						//dark lasagne, mert ez retegelt :)
	x = data[honnan].size()-1;			//esku szar de mukszik :)
	for (int i = x; i >= x - mennyi+1; i--)
		{temp2 += temp[i];}
	data[hova] = temp2;
	temp2 ="\0";
	for (int i = 0; i < x - mennyi+1; i++)
		{temp2 += temp[i];}
	data[honnan] = temp2;
}

string anyad(string asd1, string asd2, string asd3, string asd4, string asd5, string asd6, string asd7, string asd8, string asd9)
{string ans; int x = 0; x = asd1.size(); ans += asd1[x - 1]; x = asd2.size(); ans += asd2[x - 1]; x = asd3.size(); ans += asd3[x - 1];
x = asd4.size(); ans += asd4[x - 1]; x = asd5.size(); ans += asd5[x - 1]; x = asd6.size(); ans += asd6[x - 1]; x = asd7.size(); ans += asd7[x - 1];
x = asd8.size(); ans += asd8[x - 1]; x = asd9.size(); ans += asd9[x - 1];		
	return ans;}																//ne is kerdezd, teszta az egesz, nyomj ra ketchupot ugy lecsuszik ;)

int main()
{	std::ifstream manok;
	manok.open("data.txt");
	int mennyi,honnan,hova=0;
	while (manok >> mennyi >> honnan >> hova) 
	{
		honnan--, hova--;
		cserebere(mennyi, honnan, hova); //i have a trade offer for you
	}
	cout << anyad(data[0], data[1], data[2], data[3], data[4], data[5],data[6],data[7],data[8]); //monke brain
}
