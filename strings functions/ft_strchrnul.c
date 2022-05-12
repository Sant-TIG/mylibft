/*
  NAME
  ****
  ft_strchrnul ---> search for a character in a string.

  SYNOPSIS
  ********
  #include "strings.h"
  char	*ft_strchrnul(const char *str, int c);

  PARAMETERS
  **********
  str ---> the string where to look for the character.
  c   ---> the character to find.

  DESCRIPTION
  ***********
  The ft_strchrnul() function searches for the first ocurrence of the character 'c'
  in he string pointed to by 'str'.

  If it finds it, it returns a pointer to its first occurrence so that we would
  have acces to the rest of the string starting from that character.

  The difference with the ft_strchr() function is that if 'c' is not found in 'str'
  it returns a pointer to the null byte at the end of str, rathen than NULL.

  RETURN VALUE
  ************
  - If c is in str, returns a pointer to its first occurrence.
  - If not, returns a pointer to the null byte of str.
*/

char  *ft_strchrnul(const char *str, int c)
{
  while (*str)
  {
    if (*str == c)
      return ((char *)str);
    str++;
  }
  return ((char *)str);
}
