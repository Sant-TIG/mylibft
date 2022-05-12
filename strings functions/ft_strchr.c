/*
  NAME
  ****
  ft_strchr ---> search for a character in a string

  SYNOPSIS
  ********
  #include "strings.h"
  char	*ft_strchr(const char *str, int c);

  PARAMETERS
  **********
  str ---> the string where to look for the character.
  c   ---> the character to find.

  DESCRIPTION
  ***********
  The ft_strchr() function searches for the first ocurrence of the character 'c'
  in he string pointed to by 'str'.

  If it finds, it returns a pointer to its first occurrence so that we would
  have acces to the rest of the string starting from that character.

  RETURN VALUE
  ************
  - If c is in str, returns a pointer to its first occurrence.
  - If not, returns NULL.
*/

#include "strings.h"

char  *ft_strchr(const char *str, int c)
{
    while (*str)
    {
        if (*str == c)
            return ((char *)str);
        str++;
    }
    return (FT_NULL);
}
