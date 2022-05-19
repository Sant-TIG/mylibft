/*
  NAME
  ****
  ft_islower ---> is lowercase

  SYNOPSIS
  ********
  #include "check.h"
  int	ft_islower(int c);

  PARAMETERS
  **********
  c --> The character to check.

  DESCRIPTION
  ***********
  The ft_islower() function checks if the character passed as a parameter is
  a lowercase alphabetic character or not.

  RETURN VALUE
  ************
  - If the character is lowercase, non-zero.
  - If not, zero.
*/

int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}
