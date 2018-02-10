/*
** EPITECH PROJECT, 2018
** mathstick.h
** File description:
** mathstick;h
*/

typedef struct s
{
	int nbr_lign;
	int nbr_max_stick;
	int first_choice;
	int second_choice;
	int check_turn;
	int ia_or_you;
} s_t;

#ifndef READ_SIZE
#	define READ_SIZE (1)
#endif /* ! READ_SIZE */

int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char *str);
char *my_revstr(char *str);
int my_strlen(char *str);
int get_nbr(char *str);
char **create_game(s_t *s);
char **put_spaces(s_t *s, char **tabl);
char *get_next_line(int fd);
char **capt_information(char **tabl, s_t *s);
int check_enought_2(char *str, char **tabl, s_t *s);
char **delete_pipe(s_t *s, char **tabl);
int pipe_are_real(char **tabl, s_t *s);
void display_tabl(char **tabl);
char **ia_turn(char **tabl, s_t *s);
void display_sentence(s_t *s, char **tabl);
char **delete_pipe_ia(int first_choice, int second_choice, char **tabl);
void my_error(char *str);
int my_put_nbr_error(int nb);
void my_put_error(char c);
int end(s_t *s);