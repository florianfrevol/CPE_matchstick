/*
** EPITECH PROJECT, 2018
** mathstick
** File description:
** mathstick
*/

#include "mathstick.h"

int check_enought_2(char *str, char **tabl, s_t *s)
{
	int i = 0;
	int number = get_nbr(str);
	int e = 0;

	while (tabl[s->first_choice][i] != '\0') {
		if (tabl[s->first_choice][i] == '|')
			e ++;
		i ++;
	}
	if (number > e) {
		my_putstr("Error: not enough matches on this line\n");
		return (1);
	}
	return (0);
}

int errors(int argc, char **argv, s_t *s)
{
	if (argc < 3) {
		my_putstr("argument invalid\n");
		return (1);
	}
	s->nbr_lign = get_nbr(argv[1]);
	s->nbr_max_stick = get_nbr(argv[2]);
	if (s->nbr_lign > 99 || s->nbr_lign == 0) {
		my_putstr("numbers of sticks invalid\n");
		return (1);
	}
	s->ia_or_you = 1;
	s->check_turn = 1;
	s->error = 0;
	s->check = 0;
	return (0);
}

void display_tabl(char **tabl)
{
	int i = 0;

	while (tabl[i] != 0) {
		my_putstr(tabl[i]);
		my_putchar('\n');
		i ++;
	}
}

int pipe_are_real(char **tabl, s_t *s)
{
	int i = 0;
	int e;

	while (i != s->nbr_lign + 1) {
		e = 0;
		while (tabl[i][e] != '\0') {
			if (tabl[i][e] == '|')
				return (1);
			e ++;
		}
		i ++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	s_t s;
	char **tabl;

	if (errors(argc, argv, &s) == 1)
		return (84);
	tabl = create_game(&s);
	tabl = put_spaces(&s, tabl);
	while (pipe_are_real(tabl, &s) == 1) {
		if (s.ia_or_you == 1)
			capt_information(tabl, &s);
		if (s.error == 1)
			return (84);
		tabl = reduce_main(&s, tabl);
	}
	if (end(&s) == 1)
		return (1);
	else
		return (2);
	return (0);
}