#include "peanuts.h"
#include <unistd.h>

t_person		**shuffle(t_person **per, int ac)
{
	t_person	**ret;
	int 			a;
	int 			i;
	int 			j;

	i = 0;
	ret = malloc((sizeof(t_person *)) * ac);
	while(ac > 0)
	{
		j = arc4random() % ac;
		a = 0;
		while(j >= 0)
		{
			if (per[a] != NULL)
				j--;
			a++;
		}
		ret[i] = per[a];
		per[a] = NULL;
		i++;
		ac--;
	}
	free(per);
	return (ret);
}

unsigned int	find_wave(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] && s[i] != '~')
	{
		i++;
	}
	return (i);
}

int				main(int ac, char **av)
{
	int 			i;
	unsigned int	b;
	t_person		**per;
	
	i = 1;
	per = malloc((sizeof(t_person *)) * ac);
	while (i < ac)
	{
		per[i - 1] = malloc(sizeof(t_person));
		b = find_wave(av[i]);
		per[i - 1]->name = ft_strdup(av[i]);
		per[i - 1]->name[b] = '\0';
		per[i - 1]->mail = ft_strdup(av[i] + b + 1);
		i++;
	}
	per = shuffle(per + 1, ac);
	i = 1;
	while(i < ac)
	{
		printf("%s\n", per[i - 1]->name);
		i++;
	}
}
