#include<stdlib.h>
#include<stdio.h>


#define TAB1SIZE 10
#define TAB2SIZE 100
#define TAILLEAJOUT 50

int initTab(int* tab, int size);


int afficheTab(int* tab, int size, int nbElts);


int ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element);
