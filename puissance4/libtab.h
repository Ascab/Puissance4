#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
float ft_average_tab (float* grades, int nb_grades);
void ft_switchColumns (float systeme[][102], int lignesMax, int colonnesMax);
void fnc_decaleTableauColonne (float systeme[][102], int lignesMax, int colonnesMax);
void ft_print2Dtab (char** tab, int nb_rows, int nb_columns);
void ft_init2Dtab (char **tab, int nb_rows, int nb_columns, char c);
#endif // HEADER_H_INCLUDED

