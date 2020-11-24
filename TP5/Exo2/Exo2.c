#include<stdlib.h>
#include<stdio.h>

#define TAILLEINITIALE 100


typedef struct Tableau
{ 
	int* elt;// le tableau d’entiers
	int size;// la taille de ce tableau d’entiers
	int eltsCount;// le nombre d’éléments dans le tableau
} TABLEAU;

TABLEAU newArray()
{
	TABLEAU tab;
	tab.size = TAILLEINITIALE; // initialisation de la taille du tableau
	tab.elt = (int*)malloc(tab.size * sizeof(int)); //allocation de la memoire necessaire 
	if (tab.elt == NULL)
	{
		return tab;  // verifie si il n'y a pas eu d'erreur
	}
	//maintenant on peut remplir le tableau avec des 0
	for (int i = 0; i < tab.size; i++)
	{
		tab.elt[i] = 0;
	}
	tab.eltsCount = 0;
	return tab;
}

int incrementArraySize(TABLEAU* tab, int incrementValue)
{
	int* tab2 = tab->elt; //sauvegarde l'ancien tableau en cas d'erreur
	tab->elt = (int*)realloc(tab->elt, sizeof(int) * (tab->size + incrementValue)); //realloue la memoire necessaire au nouveau tableau
	if (tab->elt == NULL)
	{
		tab->elt = tab2;
		return -1;				// si il y a une erreur pendant le realloc renvoi le tableau initial
	}
	//si tout c'est bien passer on met les nouveaux elements du tableau a 0
	for (int i = 0; i < incrementValue; i++)
	{
		tab->elt[tab->size + i] = 0;
	}
	// on modifie aussi la taille du tableau pour enregistrer la nouvelle taille 
	tab->size = tab->size + incrementValue;
	return tab->size;
}

int setElement(TABLEAU* tab, int pos, int element)
{
	if (pos < 1 || tab->elt == NULL)
	{
		return 0;   // erreur si la position n'est pas logique
	}
	if (tab->size < pos)
	{
		incrementArraySize(tab, pos - tab->size); //si le tableau n'est pas assez grand on reajuste la taille
	}
	tab->elt[pos - 1] = element;
	return pos;
}

int displayElements(TABLEAU* tab, int startPos, int endPos)
{
	if (startPos >= endPos)
	{
		int a = startPos;
		startPos = endPos;
		endPos = a;
	}
	if (tab->elt == NULL || startPos<1 || endPos > tab->size) //si les valeurs ne sont pas logique ou l'adresse du tableau est NULL
	{
		printf("il y a une erreur dans les donnees");
		return -1;					
	}
	//on peut maintenant afficher le tableau
	for (int i = startPos; i <= endPos; i++)
	{
		printf("%d ", tab->elt[i - 1]);
	}
	return 0;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos)
{
	if (startPos >= endPos)
	{
		int a = startPos;
		startPos = endPos;
		endPos = a;
	}
	if (tab->elt == NULL || endPos > tab->size || startPos < 1) //si les valeurs ne sont pas logique ou l'adresse du tableau est NULL
	{
		printf("il y a une erreur dans les donnees");
		return -1;
	}
	int* tab2 = tab->elt;    //sauvegarde le tableau initial 
	int c = 0;
	for (int i = 0; i < tab->size; i++) {
		if (i<(startPos - 1) || i>(endPos - 1)) //On modifie les elements du tableau si l'indice est en dehors de l'intervalle
		{
			tab->elt[c] = tab2[i];
			c++;
		}
	}
	tab->size -= endPos - startPos + 1;
	return tab->size;
}



int main()
{
	TABLEAU tab = newArray();
	setElement(&tab, 126, 4);
	setElement(&tab, 10, 4);
	setElement(&tab, 11, 5);
	setElement(&tab, 12, 6);
	setElement(&tab, 13, 7);
	displayElements(&tab, 1, 126);
	deleteElements(&tab, 11, 12);
	printf("\n");
	displayElements(&tab, 1, 124);
}