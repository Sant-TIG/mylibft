/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:46:01 by sperez-p          #+#    #+#             */
/*   Updated: 2021/08/20 12:46:04 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
