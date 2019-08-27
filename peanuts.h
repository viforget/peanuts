#ifndef PEANUTS
# define PEANUTS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct	s_person
{
	int 		nb;
	char 		*name;
	char 		*mail;
}				t_person;

char			*ft_strdup(const char *s1);
char			*create_mail(char *from, char *to);
int				send_mail(char *obj, char *mailer);
char			*ft_strjoindel(char *s1, char const *s2);
size_t			ft_strlen(const char *str);

#define BODY_1 "Salut "
#define BODY_2 "\n ceci est un test, dis à Victor que tu as pioché:\n"

#endif
