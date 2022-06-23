/*
NAME
****
ft_strlen ---> calculate the length of a string

SYNOPSIS
********
#include "mylibft.h"
size_t	ft_strlen(const char *str);

PARAMETERS
**********
str ---> the string whose length is to be found

DESCRIPTION
***********
The ft_strlen() function calculates the length of 'str', excluiding the 
terminating null byte '\0'. If the content of 'str' if NULL, returns zero.

RETURN VALUE
************
- The number of bytes in 'str'.
- If 'str' is NULL, returns zero.
*/

#include "../mylibft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i))
		i++;
	return (i);
}
