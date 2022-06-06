/*
NAME
****
strcasecmp ---> compare two strings ignoring case

SYNOPSIS
********
#include "strings.h"
int	ft_strcasecmp(const char *str1, const char *str2);

PARAMETERS
**********
str1 ---> the first string to compare
str2 ---> the second string to compare

DESCRIPTION
***********
The ft_strcasecmp() function checks if two strings are equal or not ignoring the
case of the characters. To do this, it compares both strings character by
character until it finds a difference or one of them ends.

In any of the cases, the return value will be the difference between the last
parsed pairs of bytes, so that if all pairs bytes parsed are equal, the result
is zero.

RETURN VALUE
************
- If the strings are equal, returns zero.
- If any character of str1 is greater than its equivalent in str2, after
  ignoring the case, returns an integer greater than zero.
- If any character of str1 if less than its equivalent in str2, after ignoring
  the case, returns an integer less than zero.

*/

int	ft_strcasecmp(const char *str1, const char *str2)
{
	int	nbr;

	nbr = 0;
	while (*str1 && *str2)
	{
		if (*(unsigned char *)str1 != *(unsigned char *)str2)
		{
			nbr = *(unsigned char *)str1 - *(unsigned char *)str2;
			if (nbr != 32 && nbr != -32)
				break ;
		}
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
