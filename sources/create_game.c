/*
** EPITECH PROJECT, 2018
** create_game
** File description:
** create_game
*/

#include "mathstick.h"
#include <stdlib.h>

char *putstars(s_t *s)
{
	char *str = malloc(sizeof(char) * (s->nbr_lign * 2 + 2));
	int i = 0;

	while (i != (s->nbr_lign * 2 + 1)) {
		str[i] = '*';
		i ++;
	}
	str[i] = '\0';
	return (str);
}


char **create_game(s_t *s)
{
	char **tabl = malloc(sizeof(char *) * (s->nbr_lign + 3));
	int i = 1;
	int e = 0;

	tabl[0] = putstars(s);
	while (i != s->nbr_lign + 1) {
		tabl[i] = malloc(sizeof(char) * (s->nbr_lign * 2 + 2));
		e = 1;
		tabl[i][0] = '*';
		while (e != (s->nbr_lign * 2)) {
			tabl[i][e] = '|';
			e ++;
		}
		tabl[i][e] = '*';
		tabl[i][e + 1] = '\0';
		i ++;
	}
	tabl[i] = putstars(s);
	tabl[i + 1] = 0;
	return (tabl);
}

char **put_spaces(s_t *s, char **tabl)
{
	int i = s->nbr_lign;
	int e;
	int space = 1;
	int all = (s->nbr_lign * 2);

	while (i != 0) {
		e = 1;
		while (e != space){
			tabl[i][e] = ' ';
			e ++;
		}
		e = e + (all - (space * 2) + 1);
		while (e != (s->nbr_lign * 2)) {
			tabl[i][e] = ' ';
			e ++;
		}
		space ++;
		i --;
	}
	return (tabl);
}