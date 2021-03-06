/*
** EPITECH PROJECT, 2017
** getnbr.c
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>
#include "mathstick.h"

int get_nbr(char *str)
{
	int i = 0;
	int e = 1;
	int result = 0;

	my_revstr(str);
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			result = result + ((str[i] - 48) * e);
			e = e * 10;
		}
		i ++;
	}
	my_revstr(str);
	return (result);
}

void my_error(char *str)
{
	write(2, str, my_strlen(str));
}

int my_put_nbr_error(int nb)
{
	int mod = 0;

	if (nb < 0) {
		my_put_error('-');
		nb = -nb;
	}
	if (nb >= 10) {
		mod = nb % 10;
		nb = nb / 10;
		my_put_nbr(nb);
		my_put_error(mod + 48);
	}
	else
		my_put_error(nb + 48);
	return (0);
}

void my_put_error(char c)
{
	write(2, &c, 1);
}