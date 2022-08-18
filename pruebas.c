
#include "get_next_line.h"


size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int main()
{
	char	*s;

	s = malloc(sizeof(char) * 1);
	s [0] = 0;
	printf("%i\n", (int)ft_strlen(s));
	return (0);
}
