// NOTE : 17/20

#include <stdio.h>
#include <time.h>

void initgrille(int grille[9][9] , int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			grille[i][j] = 0;
		}
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
		printf("\nCoorndonees invalides\n");
	}
	else
	{
		printf("Quelle valeur voulez-vous rentrer ?\n");
		scanf_s("%d", &valeur);
		grille[ligne][colonne] = valeur;
		if (verification(grille, n) == 0)
		{
			while (verification(grille, n) == 0)
			{
				printf("Valeur invalide ! Veuillez reessayer: \n");
				scanf_s("%d", &valeur);
				grille[ligne][colonne] = valeur;
			}
		}
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
	for (int i = 0; i < n; i++) //Vérifie si les nombres sont entre 0 et n
	{
		for (int j = 0 ; j < n; j++)
		{
			if ((grille[i][j] < 1 && grille[i][j] != 0) || grille[i][j] > n)
			{
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				if (grille[i][j] == grille[i][k] && grille[i][j] != 0) //Vérifie si un nombre est présent une fois par ligne
				{
					return 0;
				}
				if (grille[j][i] == grille[k][i] && grille[j][i] != 0) //Vérifie si un nombre est présent une fois par colonne
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

void fillgrille(int grille[9][9], int n, int parametre)
{
	int limite = 0;
	int x = 0;
	int y = 0;
	srand(time(NULL));
	switch (parametre)
	{
	case 1:
		limite = n*n/2;
		break;
	case 2:
		limite = n * n / 3;
		break;
	case 3:
		limite = n * n / 4;
		break;
	default:
		printf("Parametre invalide !\n");
		break;
	}
	for (int i = 0; i < limite; i++)
	{
		while (1)
		{
			x = rand() % (n);
			y = rand() % (n);
			if (grille[y][x] == 0)
			{
				break;
			}
		}
		while(1)
		{
			grille[y][x] = rand() % (n - 1) + 1;
			if (verification(grille, n) == 1)
			{
				break;
			}
		}
	}
}

int grilleFinie(int grille[9][9], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grille[i][j] == 0)
			{
				return 0;
			}
			
		}
	}
	printf("Felecitations !\n");
	return 1;
}

int main()
{
	int grille[9][9] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0 ,0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	while(1)
	{
		initgrille(grille, 9);
		int tailleGrille = 9;
		char ouiNon = 'o';
		int niveau = 1;

		printf("Choisissez une taille de grille : ");
		scanf_s("%d", &tailleGrille);
		getchar();

		printf("Voulez-vous initialiser la grille ? (o/n) : ");
		scanf_s("%c", &ouiNon);
		getchar();
		if (ouiNon == 'o')
		{
			editgrille(grille, tailleGrille);
			showgrille(grille, tailleGrille);	
		}

		printf("Voulez-vous generer alealatoirement la grille ? (o/n) : ");
		scanf_s("%c", &ouiNon);
		getchar();
		if (ouiNon == 'o')
		{
			printf("Choisissez un niveau : ");
			scanf_s("%d", &niveau);
			getchar();
			fillgrille(grille, tailleGrille, niveau);
			showgrille(grille, tailleGrille);
		}

		printf("Voulez-vous resoudre la grille ? (o/n) : ");
		scanf_s("%c", &ouiNon);
		getchar();
		while (grilleFinie(grille, tailleGrille) == 0)
		{
			editgrille(grille, tailleGrille);
			showgrille(grille, tailleGrille);
		}

		printf("Voulez-vous fermer le programme ? (o/n) : ");
		scanf_s("%c", &ouiNon);
		getchar();
		if (ouiNon == 'o')
		{
			return 0;
		}
	}
}