/*
  NAME
  ****
  ft_strstr ---> search for a string in a string

  SYNOPSIS
  ********
  #include "strings.h"
  char	*ft_strstr(const char *haystack, const char *needle);

  PARAMETERS
  **********
  haystack ---> the string where to find the substring.
  needle   ---> the substring to find.

  DESCRIPTION
  ***********
  The ft_strstr() function searches for the first ocurrence of the substring
  'needle' in the string pointed to by 'haystack'. The terminating null bytes
  are not compared.

  If it finds the entire secuence of characters specified in 'needle', it
  returns a pointer to the beginning of the first occurrence of this substring.

  RETURN VALUE
  ************
  - If 'needle' is in 'haystack', returns a pointer to the beginning of its
    first occurrence.
  - If not, returns NULL.
  - If 'needle is empty string, returns haystack.
*/

#include "strings.h"
#include <unistd.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	if (!needle || !haystack)
		return (FT_NULL);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[++i])
	{
		j = -1;
		while (haystack[i + ++j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
		}
	}
	return (FT_NULL);
}


/* ANOTHER WAY TO DO THE SAME
char	*ft_strstr(const char *haystack, const char *needle)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	if (!needle || !haystack)
		return (FT_NULL);
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + ++i))
	{
		j = -1;
		while (*(haystack + i + ++j) == *(needle + j))
		{
			if (*(needle + j + 1) == '\0')
				return ((char *)(haystack + i));
		}
	}
	return (FT_NULL);
}
*/
