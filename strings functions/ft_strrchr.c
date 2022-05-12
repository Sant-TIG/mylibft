/*
  NAME
  ****
  ft_strrchr ---> reverse order search for a character in a string.

  SYNOPSIS
  ********
  #include "strings.h"
  char	*ft_strrchr(const char *str, int c);

  PARAMETERS
  **********
  str ---> the string where to look for the character.
  c   ---> the character to find.

  DESCRIPTION
  ***********
  The ft_strrchr() function searches for the last ocurrence of the character 'c'
  in he string pointed to by 'str'.

  If it finds it, it returns a pointer to it so that we would have acces to the
  rest of the string starting from that character.

  RETURN VALUE
  ************
  - If c is in str, returns a pointer to its last occurrence.
  - If not, returns NULL.
*/

#include <stddef.h>
#include "strings.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str) + 1;
	while (i--)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
	}
	return (FT_NULL);
}
