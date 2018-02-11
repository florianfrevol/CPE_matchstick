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

char **reduce_put_info(s_t *s, char **tabl)
{
	char *str;

	if (s->check_turn == 1) {
		display_tabl(tabl);
		my_putstr("\nYour turn:\n");
		s->check_turn ++;
	}
	my_putstr("Line: ");
	str = get_next_line(0);
	if (str == NULL) {
		s->error = 1;
		s->check = 1;
		return (tabl);
	}
	if (check_imput(s, str) == 1 || check_enought(str, tabl) == 0) {
		s->check = 1;
		return (tabl);
	}
	s->first_choice = get_nbr(str);
	my_putstr("Matches: ");
	return (tabl);
}