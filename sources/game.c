/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game
*/

#include "mathstick.h"

void display_sentence(s_t *s, char **tabl)
{
	my_putstr("Player removed ");
	my_put_nbr(s->second_choice);
	my_putstr(" match(es) from line ");
	my_put_nbr(s->first_choice);
	my_putchar('\n');
	display_tabl(tabl);
}

char **delete_pipe(s_t *s, char **tabl)
{
	int i = 1;
	int e = 0;

	my_revstr(tabl[s->first_choice]);
	while (tabl[s->first_choice][i] == ' ')
		i ++;
	while (e != s->second_choice) {
		tabl[s->first_choice][i] = ' ';
		i ++;
		e ++;
	}
	my_revstr(tabl[s->first_choice]);
	s->ia_or_you = 0;
	return (tabl);
}

char **delete_pipe_ia(int first_choice, int second_choice, char **tabl)
{
	int i = 1;
	int e = 0;

	my_revstr(tabl[first_choice]);
	while (tabl[first_choice][i] == ' ')
		i ++;
	while (e != second_choice) {
		tabl[first_choice][i] = ' ';
		i ++;
		e ++;
	}
	my_revstr(tabl[first_choice]);
	return (tabl);
}