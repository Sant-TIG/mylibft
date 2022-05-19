/*
  NAME
  ****
  ft_toupper ---> convert char to upper case

  SYNOPSIS
  ********
  #include "convert.h"
  int	ft_toupper(int c);

  PARAMETERS
  **********
  c --> The character to convert.

  DESCRIPTION
  ***********
  The ft_toupper() function converts the character passed as a parameter to
  uppercase if it is possible.

  RETURN VALUE
  ************
  - The character converted to uppercase.
  - If it is not possible to convert, the original character.

*/

#include "check.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}
