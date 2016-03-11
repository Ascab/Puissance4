#include <stdio.h>
#include <stdlib.h>

void ft_print2Dtab (char** tab, int nb_rows, int nb_columns);

int ft_placement_pion(char grille[][7], int column, char pion, int nb_rows)
{
    int i;
    i=0;

    while ((grille[i+1][column]== ' ' )&&(i< nb_rows))
    {
        i++;
        printf("%d\n", i);
    }
    grille[i][column] = pion;
    return i;
}
int ft_victory_check (char grille[][7], char pion, int row, int column)
{
    int i;
    i=0;

    //Victoire colonne?
    while ((row+i <7)&&(i<4))
    {
        if (grille[row][column] == grille[row+i][column])
        {
            i++;
            printf("Row+i = %d", row+i);
        }
        else
            break;
    }
    if (i==3)
        return 1;
    i=0;
    while ((row-i > 0)&&(i<4))
    {
        if (grille[row][column] == grille[row-i][column])
        {
            i++;
            printf("Row+i = %d", row+i);
        }
        else
            break;
    }
    if (i==3)
        return 1;
    i=0;
    //Victoire ligne?
    while ((column+i < 7)&& (i < 4))
    {
        if (grille[row][column] == grille[row][column+i])
            i++;
        else
            break;
    }
    if (i==3)
        return 1;
    i=0;
    while ((column-i > 0)&&(i<4))
    {
        if (grille[row][column] == grille[row][column+i])
            i++;
        else
            break;
    }
    if (i==3)
        return 1;
    i=0;
    //Victoire diagonale?
    while ((column+i < 7)&&(i < 4)&&row+i < 7)
    {
        if (grille[row][column] == grille[row+i][column+i])
            i++;
        else
            break;
    }
    if (i==3)
        return 1;
    i=0;
    while ((column-i > 0)&&(i < 4)&&row-i > 0)
    {
        if (grille[row][column] == grille[row-i][column-i])
            {
                i++;
                printf("Row+i = %d", row+i);
            }
        else
            break;
    }
    if (i==3)
        return 1;
    return 0;
}
