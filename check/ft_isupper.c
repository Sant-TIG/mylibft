/*
  NAME
  ****
  ft_isupper ---> char is uppercase

  SYNOPSIS
  ********
  #include "check.h"
  int	ft_isupper(int c);

  PARAMETERS
  **********
  c --> The character to check.

  DESCRIPTION
  ***********
  The ft_isupper() function checks if the character passed as a parameter is
  an uppercase alphabetic character or not.

  RETURN VALUE
  ************
  - If the character is uppercase, non-zero.
  - If not, zero.

*/

int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}
