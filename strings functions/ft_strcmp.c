/*
  NAME
  ****
  ft_strcmp ---> compare strings

  SYNOPSYS
  ********
  #include "strings.h"
  int	ft_strcmp(const char *str1, const char *str2);

  PARAMETERS
  **********
  str1 ---> the first string to compare.
  str2 ---> the second string to compare.

  DESCRIPTION
  ***********
  The ft_strcmp() function checks if two strings are equal or not. To do this, it compares
  both strings character by character until it finds a difference or one of them ends.
  As the original function, the comparison is done using unsigned characters.
  
  In any of the cases, the function will return the subtraction of the last character it
  checks in both strings, so that if they are equal the result would be zero.

  RETURN VALUE
  ************
  - Zero if the strings are equal.
  - Greater than zero if the last character checked of str1 is greater than that of str2.
  - Less than zero if the last character checked of str1 is less than that of str2.
*/

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		if((unsigned char)*str1 != (unsigned char)*str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
