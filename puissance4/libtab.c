#include <stdio.h>

float ft_average_tab (float* grades, int nb_grades)
{
	float moyenne;
	int i;

	moyenne = 0;
	for (i = 0 ; i < nb_grades ; i++)
		moyenne = moyenne + grades[i];
	return moyenne/nb_grades ;
}
void ft_switchColumns (float systeme[][102] , int lignesMax, int colonnesMax)
{
    float tab_stockage[102];
    int ligne,colonne;

    for (ligne=0 ; ligne < lignesMax ; ligne++)
    {
        tab_stockage[ligne] = systeme[ligne][0];
    }

    for (colonne=0 ; colonne < colonnesMax ; colonne++)
    {
        for (ligne=0 ; ligne< lignesMax ; ligne++)
        {
            systeme[ligne][colonne]=systeme[ligne][colonne+1];
        }
    }
    for (ligne=0 ; ligne < lignesMax ; ligne++)
    {
        systeme[ligne][colonnesMax-1] = tab_stockage[ligne];
    }
    return ;
}

void fnc_decaleTableauColonne (float systeme[][102] , int lignesMax, int colonnesMax)
{
    float tab_stockage[102];
    int ligne,colonne;

    for (ligne=0 ; ligne < lignesMax ; ligne++)
    {
        tab_stockage[ligne] = systeme[ligne][0];
    }

    for (colonne=0 ; colonne < colonnesMax ; colonne++)
    {
        for (ligne=0 ; ligne< lignesMax ; ligne++)
        {
            systeme[ligne][colonne]=systeme[ligne][colonne+1];
        }
    }
    for (ligne=0 ; ligne < lignesMax ; ligne++)
    {
        systeme[ligne][colonnesMax-1] = tab_stockage[ligne];
    }
    return ;
}
void ft_print2Dtab (char tab[][7], int nb_rows, int nb_columns)
{
    int i, j;
    for (i=0 ; i < nb_rows ; i++)
    {
        for (j=0 ; j < nb_columns ; j++)
        {
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
    return ;
}
void ft_init2Dtab (char tab[][7], int nb_rows, int nb_columns, char c)
{
    int i, j;

    for (i=0 ; i < nb_rows ; i++)
    {
        for (j=0 ; j < nb_columns ; j++)
        {
            tab[i][j] = c;
        }
    }
    return ;
}
