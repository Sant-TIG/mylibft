/*
NAME
****
ft_strmapi ---> iterate string aplying a function to each character

SYNOPSIS
********
#include "mylibft.h"
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));

PARAMETERS
**********
str ---> the string on which to iterate
f   ---> the function to apply to each character

DESCRIPTION
***********
The ft_strmapi() function applies the function 'f' to each character of the
string 'str' to create a new string resulting from successive applications of
the function. This new string will be allocated in a dinamic memory space using
the malloc() C function.

It first checks if 'str' is not NULL and then reserves the memory space for the
new string 'dst', which will be the same size as the original string.

Once verified that there is no error allocating the memory, it iterates 'str'
assigning to each space of 'dst' the return value of applying the function 'f'
to each character of 'str'.

RETURN VALUE
************
- A pointer to he new string.
- If there is an error allocating memory or if 'str' is NULL, returns NULL.
*/

#include "../mylibft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dst)
		return (NULL);
	while (*(str + i))
	{
		*(dst + i) = f(i, *((char *)(str + i)));
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}
