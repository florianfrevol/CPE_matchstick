/*
** EPITECH PROJECT, 2018
** play_game
** File description:
** play
*/


#include <unistd.h>
#include <stdlib.h>
#include "mathstick.h"

int check_if_number(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i ++;
	}
	return (0);
}

int check_imput(s_t *s, char *str)
{
	if (check_if_number(str) == 0) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (1);
	}
	if (get_nbr(str) > s->nbr_lign) {
		my_putstr("Error: this line is out of range\n");
		return (1);
	}
	return (0);
}

int check_enought(char *str, char **tabl)
{
	int i = 0;
	int number = get_nbr(str);

	while (tabl[number][i] != '\0') {
		if (tabl[number][i] == '|')
			return (1);
		i ++;
	}
	my_putstr("Error: not enough matches on this line\n");
	return (0);
}

int check_imput_2(s_t *s, char *str)
{
	if (check_if_number(str) == 0) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (1);
	}
	if (get_nbr(str) > s->nbr_max_stick) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(s->nbr_max_stick);
		my_putstr(" matches per turn\n");
		return (1);
	}
	return (0);
}

char **capt_information(char **tabl, s_t *s)
{
	char *str;

	tabl = reduce_put_info(s, tabl);
	if (s->check == 1) {
		s->check = 0;
		return (tabl);
	}
	str = get_next_line(0);
	if (str == NULL) {
		s->error = 1;
		return (tabl);
	}
	if (check_imput_2(s, str) == 1 || check_enought_2(str, tabl, s) == 1)
		return (0);
	s->second_choice = get_nbr(str);
	s->check_turn = 1;
	delete_pipe(s, tabl);
	return (tabl);
}