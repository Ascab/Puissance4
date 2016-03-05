#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "struct.h"


void ft_placement_pion(char **grille, int column, char pion, int nb_rows);
int ft_victory_check(char **grille, char pion, int row, int column);
float ft_average_tab (float* grades, int nb_grades);
void ft_switchColumns (float systeme[][102], int lignesMax, int colonnesMax);
void fnc_decaleTableauColonne (float systeme[][102], int lignesMax, int colonnesMax);
void ft_print2Dtab (char **tab, int nb_rows, int nb_columns);
void ft_init2Dtab (char **tab, int nb_rows, int nb_columns, char c);

int main (void)
{
    int column, tour, victory, row;
    struct joueur joueur1={"",0}, joueur2={"",0};
    char grille[7][7] ;
    char continuer;

    printf("Joueur 1 quel est votre nom?\n");
    scanf("%s", joueur1.nom);
    printf("Joueur 2 comment vous appelez-vous?\n");
    scanf("%s", joueur2.nom);

    srand(time(NULL));
    do
    {
        ft_init2Dtab(grille, 7,7, 'a');
        victory=0;

        tour = (rand()%2)+1;
        if (tour%2 == 0)
            printf("%s commence\n", joueur2.nom); //joueur 2 tours pair
        else
            printf("%s commence\n", joueur1.nom); //joueur 1 tours impair
        printf ("Preparez vos meninges la partie va commencer\n");
        while (victory == 0)
        {
            ft_print2Dtab(grille, 7, 7);
            if (tour%2 == 0)
            {
                printf("%s c'est a votre tour\nSur quelle colonne voulez vous placer votre pion?swag\n", joueur2.nom);
                do
                {
                    scanf("%d", &column);
                }while((column < 1 || column > 7)||(grille[0][column]=! ' '));
                ft_placement_pion(grille, column-1, 'X', 7);
                printf("\n\t%d", row);
                ft_print2Dtab(grille, 7, 7);
                victory=ft_victory_check (grille, 'X', row, column-1);
                tour++;
            }
            else
            {
                printf("%s c'est a votre tour\nSur quelle colonne voulez vous placer votre pion?\n", joueur1.nom);
                do
                {
                    scanf("%d", &column);
                    printf("%d", column);
                }while((column < 0 || column > 7)||(grille[0][column]=! ' '));
                ft_placement_pion(grille, column-1, 'O',7);
                ft_print2Dtab(grille, 7,7);
                victory=ft_victory_check (grille, 'O', row, column-1);
                tour++;
            }
        }
        if (tour%2==0)
        {
            printf("Notre vainqueur est %s. Bien joue\n", joueur2.nom);
            joueur2.score++;
        }
        else
        {
            printf("Bien joue %s, vous avez gagne cette manche swag\n", joueur1.nom);
            joueur1.score++;
        }
        printf("Voulez-vous rejouer?[O/N] ");
        do
        {
            scanf(" %c", &continuer);
        }while(continuer != 'O' || continuer != 'o' || continuer != 'N' ||continuer != 'n');
    }while (continuer == 'O' || continuer == 'o' );
    printf ("Tableau des scores swag :\n%s : %d\n%s : %d",joueur1.nom, joueur1.score, joueur2.nom, joueur2.score);

    return 0;
}
