#include "GrafMacierz.h"
#include "BellFord.h"

#define BRAK -1

void Algorytm_Bellmana_Forda(Graf_Macierz_Sasiedztwa graf, unsigned int* Koszt, signed int* Wierzcholek_Poprzedzajacy) 
	{

	//Pocz¹tkowe ustawienie kosztów wierzcho³ków s¹siaduj¹cych
	//ze startowym jako waga ich krawêdzi oraz pozosta³ych wierzcho³ków
	//jako nieskonczonoœæ
	for (unsigned int i = 0; i < graf.liczba_wierzcholkow; i++) 
		{
		if (graf.Czy_Jest_Krawedz(i, 0)) 
			{
			Koszt[i] = graf.Macierz_Sasiedztwa[0][i];
			Wierzcholek_Poprzedzajacy[i] = 0;
			} 
		else 
			{
			Koszt[i] = 0;
			Wierzcholek_Poprzedzajacy[i] = BRAK;
			}
		}
	for (unsigned int k = 0; k < graf.liczba_wierzcholkow - 1; k++)
		for (unsigned int i = 1; i < graf.liczba_wierzcholkow; i++)
			for (unsigned int j = 0; j < graf.liczba_wierzcholkow; j++)
				if ((!Koszt[i] || Koszt[i] > Koszt[j] + graf.Macierz_Sasiedztwa[i][j]) && Koszt[j] && graf.Macierz_Sasiedztwa[i][j]) 
					{
					Koszt[i] = Koszt[j] + graf.Macierz_Sasiedztwa[i][j];
					Wierzcholek_Poprzedzajacy[i] = j;
					}

	}