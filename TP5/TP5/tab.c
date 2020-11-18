#include<stdlib.h>
#include<stdio.h>
#include"tab.h"


int initTab(int* tab, int size)
{
	if (tab == NULL || size < 0)
	{
		return -1;
	}
	for (int i = 0; i < size; i++)
	{
		tab[i] = 0;
	}
	return size;
}

int afficheTab(int* tab, int size, int nbElts)
{
	if (tab == NULL || size < 0 || size < nbElts)
	{
		return -1;
	}
	for (int i = 0; i < nbElts; i++)
	{
		printf("%d ", tab[i]);
	}
	return 0;
}

int ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element)
{
	if (tab == NULL || *size < 0)
	{
		printf("ajout impossible");
		return -1;
	}
	else if (*size < *nbElts)
	{
		// On agrandi le tableau avec realloc
		int* tab2 = tab;
		tab = (int *) realloc(tab,sizeof (int) * (*size + TAILLEAJOUT));
		if (tab == NULL)
		{
			tab = tab2;
			return -1;
		}
		for (int i = 0; i < TAILLEAJOUT; i++)
		{
			tab[*size + i] = 0;				// initialisation des nouveaux elements à 0
		}
		*size = *size + TAILLEAJOUT;
		

	}
	tab[*nbElts] = element;
	return *nbElts;
}