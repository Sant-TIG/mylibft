/*
  NAME
  ****
  ft_tolower ---> convert char to lowercase

  SYNOPSIS
  ********
  #include "convert.h"
  int	ft_tolower(int c);

  PARAMETERS
  **********
  c --> The character to convert.

  DESCRIPTION
  ***********
  The ft_tolower() function uses the ft_isupper() function to check if 'c'
  is alphabetic and uppercase. If it is the case, converts it to lowercase and
  if it not, it does not modify it.

  RETURN VALUE
  ************
  - The character converted to lowercase.
  - If it is not possible to convert, the original character.
*/

#include "check.h"

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}
