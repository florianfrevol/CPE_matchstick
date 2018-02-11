/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** 
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "mathstick.h"

char *re_alloc(char *str)
{
	char *str2;
	int i;

	i = 0;
	str2 = malloc((my_strlen(str) + 2) * sizeof(char));
	while (str[i] != '\0') {
		str2[i] = str[i];
		i++;
	}
	str2[i + 1] = '\0';
	free(str);
	return (str2);
}

char *get_next_line(int fd)
{
	int i;
	int size;
	char *str;
	static char buf[READ_SIZE];

	i = 0;
	size = 0;
	str = malloc(sizeof(char));
	str[0] = '\0';
	while ((size = read(fd, buf, READ_SIZE)) > 0 && buf[0] != '\n') {
		str = re_alloc(str);
		str[i] = buf[0];
		i++;
	}
	if (size == 0 && i == 0)
		return (NULL);
	else
		return (str);
}

int end(s_t *s)
{
	if (s->ia_or_you == 0) {
		my_putstr("You lost, too bad...\n");
		return (2);
	}
	else {
		my_putstr("I lost... snif... but I'll get you next time!!\n");
		return (1);
	}
}

char **reduce_main(s_t *s, char **tabl)
{
	if (s->ia_or_you == 0 && pipe_are_real(tabl, s) == 1) {
		ia_turn(tabl, s);
	}
	if (s->ia_or_you == 1 && pipe_are_real(tabl, s) == 0)
		display_tabl(tabl);
	return (tabl);
}