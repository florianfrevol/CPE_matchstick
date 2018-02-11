/*
** EPITECH PROJECT, 2018
** ia_turn
** File description:
** ia_turn
*/

#include "mathstick.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int check_pipe_lign(char **tabl, int number)
{
	int i = 0;

	while (tabl[number][i] != '\0') {
		if (tabl[number][i] == '|')
			return (1);
		i ++;
	}
	return (0);

}

int choose_the_lign(s_t *s, char **tabl)
{
	int number;

	number = random() % (s->nbr_lign) + 1;
	while ((number <= 0 && number > (s->nbr_lign + 1))
		|| check_pipe_lign(tabl, number) == 0) {
		number = random() % (s->nbr_lign) + 1;
	}
	return (number);
}

int choose_numer_pipe(s_t *s, char **tabl, int lign)
{
	int i = 0;
	int number_pipe = 0;
	int result;

	while (tabl[lign][i] != '\0') {
		if (tabl[lign][i] == '|')
			number_pipe ++;
		i ++;
	}
	if (number_pipe > s->nbr_max_stick)
		number_pipe = s->nbr_max_stick;
	result = random() % (number_pipe + 1);
	while (result == 0)
		result = random() % number_pipe + 1;
	return (result);
}

char **ia_turn(char **tabl, s_t *s)
{
	int lign = choose_the_lign(s, tabl);
	int number_pipe = choose_numer_pipe(s, tabl, lign);

	my_putstr("\nAI's turn...\n");
	my_putstr("AI removed ");
	my_put_nbr(number_pipe);
	my_putstr(" match(es) from line ");
	my_put_nbr(lign);
	my_putchar('\n');
	delete_pipe_ia(lign, number_pipe, tabl);
	s->ia_or_you = 1;
	return (tabl);
}