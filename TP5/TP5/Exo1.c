#include<stdlib.h>
#include<stdio.h>
#include "tab.h"


int main()
{
	int myTab1[TAB1SIZE];
	initTab(myTab1, TAB1SIZE);
	//afficheTab(myTab1, TAB1SIZE, 5);
	
	int* MyTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElt = 22;
	int nbremplir = 20;

	MyTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (MyTab2 != NULL)
	{ 
		initTab(MyTab2, tabSize); 
	}
	else 
	{ 
		printf("mémoire insuffisante"); 
		return(-1); 
	}
	for (int i = 0; i < nbremplir; i++)
	{
		MyTab2[i] = i + 1;
	}

	ajoutElementDansTableau(MyTab2, &tabSize, &nbElt, 11);

	afficheTab(MyTab2, TAB2SIZE, 30);

	

	//free(MyTab2);			// destruction du tableau
	
}