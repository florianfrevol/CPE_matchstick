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

char *re_alloc(char *chaine, int compt, int c)
{
	char *str2 = malloc(sizeof(char) * (READ_SIZE * (compt + 1) + 1 + c));
	int p = 0;

	while(chaine[p] != '\0') {
		str2[p] = chaine[p];
		p = p + 1;
	}
	str2[p] = '\0';
	return (str2);
}

static int i = 0;
static int m = 0;

char *get_next_line(int fd)
{
	static char str[READ_SIZE + 1];
	char *chaine = malloc(sizeof(char) * (READ_SIZE * READ_SIZE + 1));
	int e = 0;
	static int compt = 0;
	int p = 0;

	for (i = 0; 1; compt++) {
		for ((m = read(fd, str, READ_SIZE)); i != m; e++, i++) {
			if (str[i] == '\n') {
				i ++;
				chaine[e] = '\0';
				return (chaine);
			}
			chaine[e] = str[i];
		}
		chaine[e] = '\0';
		chaine = re_alloc(chaine, compt, p);
	}
}