#include <stdio.h>

void initgrille(int grille[9][9] , int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			grille[i][j] = 0;		}
	}
}

void editgrille(int grille[9][9], int n)
{
	int ligne = 0;
	int colonne = 0;
	int valeur = 0;
	printf("Entrez les coordonees de la valeur que vous voulez modifier: ");
	scanf_s("%d %d", &ligne, &colonne);
	if (ligne >= n || colonne >= n)
	{
		printf("\nCoorndonees invalides");
	}
	else
	{
		printf("Quelle valeur voulez-vous rentrer ?\n");
		scanf_s("%d", &valeur);
		grille[ligne][colonne] = valeur;
		printf("Valeur modifiee !\n");
	}
}

void showgrille(int grille[9][9], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grille[i][j] != 0)
			{
				printf("%d ", grille[i][j]);
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

int verification(int grille[9][9], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				if (k == j) //Vérifie si un nombre est présent une fois par ligne
				{
					return 0;
				}
				if (grille[j][i] == grille[k][i]) //Vérifie si un nombre est présent une fois par colonne
				{
					return 0;
				}
			}
			if (grille[i][j] < 1 || grille[i][j] > n) //Vérifie si les nombres sont entre 0 et n
			{
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	int grille_facile[9][9] = {
		{6, 0, 4, 9, 0, 0, 3, 0, 8},
		{3, 2, 0, 8, 0, 0, 4, 0, 0},
		{0, 0, 0, 6, 0, 4, 5, 2, 1},
		{1, 0, 2, 7, 4, 3, 8, 9, 6},
		{8, 0, 0, 0, 0, 0, 0, 0, 0},
		{9, 4, 7, 5, 8, 0, 0, 0, 0},
		{4, 9, 0, 2, 0, 8, 6, 0, 3},
		{0, 3, 6, 4, 0, 0, 0, 0, 0},
		{0, 7, 0, 0, 6, 9, 0, 0, 4}
	};

	int grille_moyenne[9][9] = {
		{1, 0, 0, 7, 0, 6, 0, 0, 0},
		{0, 0, 0, 0, 0, 8, 5, 6, 0},
		{6, 0, 8, 0, 5, 3, 4, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 6},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 3, 0, 0, 0, 0, 0, 0, 0},
		{8, 4, 0, 3, 0, 1, 0, 5, 9}
	};

	int grille_valide[9][9] = {
		{1, 2, 3},
		{3, 1, 2},
		{2, 3, 1}
	};

	printf("%d %d %d",verification(grille_facile, 9), verification(grille_moyenne, 9), verification(grille_valide, 3));

	return 0;
}