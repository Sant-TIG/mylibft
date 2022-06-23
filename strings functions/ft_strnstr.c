
/*
  NAME
  ****
  ft_strnstr ---> search for a substring in a string to at most n bytes.

  SYNOPSIS
  ********
  #include "mylibft.h"
  char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

  PARAMETERS
  **********
  haystack ---> the string where to find the substring.
  needle   ---> the substring to find.
  n        ---> the number of characters to be checked(at most).

  DESCRIPTION
  ***********
  The ft_strnstr() function searches for the first ocurrence of the substring
  'needle' in the string 'haystack', where no more than n bytes are searched.

  If it finds the entire secuence of characters specified in 'needle' within
  the limit marked by n, it returns a pointer to the beginning of the first
  occurrence of the substring.

  RETURN VALUE
  ************
  - If 'needle' is in 'haystack' searching at most n bytes, returns a pointer
    to the beginning of its first occurrence.
  - If not, returns NULL.
  - If 'needle is empty string, returns haystack.
*/

#include "../mylibft.h"
#include <unistd.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle || !haystack)
		return (FT_NULL);
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + i) && n)
	{
		j = 0;
		while (n-- && *(haystack + i + j) == *(needle + j))
		{
			if (*(needle + j++ + 1) == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (FT_NULL);
}
