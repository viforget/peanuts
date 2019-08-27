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
		if (ac == 1)
			j = 0;
		else
			j = arc4random() % ac;
		a = -1;
		while(j >= 0)
		{
			a++;
			if (per[a] != NULL)
				j--;
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

int 			check_same(t_person **per, t_person **shu, int ac)
{
	int i;

	i = 0;
	while(i < ac)
	{
		if (per[i]->nb == shu[i]->nb)
			return (1);
		i++;
	}
	return (0);
}

int				main(int ac, char **av)
{
	int 			i;
	unsigned int	b;
	t_person		**per;
	t_person		**shu;
	
	i = 0;
	av += 1;
	ac--;
	per = malloc((sizeof(t_person *)) * ac - 1);
	shu = malloc((sizeof(t_person *)) * ac - 1);
	while (i < ac)
	{
		per[i] = malloc(sizeof(t_person));
		shu[i] = malloc(sizeof(t_person));
		b = find_wave(av[i]);
		per[i]->nb = i; 
		shu[i]->nb = i; 
		per[i]->name = ft_strdup(av[i]);
		shu[i]->name = ft_strdup(av[i]);
		per[i]->name[b] = '\0';
		shu[i]->name[b] = '\0';
		per[i]->mail = ft_strdup(av[i] + b + 1);
		shu[i]->mail = ft_strdup(av[i] + b + 1);
		i++;
	}
	while(check_same(shu, per, ac) == 1)
		shu = shuffle(shu, ac);
	i = 0;
	while(i < ac)
	{
		send_mail(create_mail(per[i]->name, shu[i]->name), per[i]->mail);
		i++;
	}
}
