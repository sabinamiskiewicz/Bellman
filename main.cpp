#include <stdlib.h>
#include <fstream>
#include "GrafMacierz.h"
#include "BellFord.h"
#include <time.h>

using namespace std;

int main() 
	{
	Graf_Macierz_Sasiedztwa graf(10,20);
	unsigned int Koszt[10];
	signed int Wierzcholek_Poprzedzajacy[10];
	Algorytm_Bellmana_Forda(graf, Koszt, Wierzcholek_Poprzedzajacy);
	cout<<graf;
	for(int i =0;i<10;i++)
	 cout<<i <<" " <<Wierzcholek_Poprzedzajacy[i]<<" "<<Koszt[i]<<endl;
	getchar();
	return 0;
	}
