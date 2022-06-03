/*
NAME
****
ft_memchr ---> scan memory for a character in at most n bytes

SYNOPSIS
********
#include "strings.h"
void	*ft_memchr(const void *str, int c, size_t n);

PARAMETERS
**********
str ---> the pointer to the memory area where the search is performed
c   ---> the character to find
n   ---> the number of bytes to be analyzed

DESCRIPTION
***********
The ft_memchr() function searches for the first ocurrence of the character 'c'
in the first n bytes of the memory area pointed to by 'str'. Both 'c' and the
bytes of the memory area are interpreted as unsigned characters.

If it finds, it returns a pointer to its first occurrence so that we would have
acces to the rest of the memory area starting from that character.

RETURN VALUE
************
- If 'c' is in str, returns a pointer to its first ocurrence.
- If not, returns NULL.

*/

#include "../mylibft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)str == (unsigned char)c)
			return (str);
		str++;
	}
	return (FT_NULL);
}
