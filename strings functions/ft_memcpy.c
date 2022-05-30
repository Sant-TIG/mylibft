/*
NAME
****
ft_memcpy ---> copy memory area

SYNOPSIS
********
#include "strings.h"
void	*ft_memcpy(void *dst, const void *src, size_t n);

PARAMETERS
**********
dst ---> the destination array
src ---> the array to be copied
n   ---> the number of bytes to be copied

DESCRIPTION
***********
The ft_memcpy function copies n bytes from the src memory area to the dst memory
area. These memory areas must not overlap. In these cases, use the ft_memmove()
function instead.

First, it verifies that the arrays passed as parameters exist. If so it copies,
in order and directly from source, the first n bytes that follows the memory address
stored in src. Is for this reason that memory spaces must not overlap, since the
data could be overwritten.

RETURN VALUE
************
- A pointer to dst.
- If there is an error whith the arrays, NULL.
*/

#include <stddef.h>
#include <unistd.h>
#include "strings.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	ssize_t	i;

	i = -1;
	if (!dst || !src)
		return (FT_NULL);
	while (++i < n)
		*(char *)(dst + i) = *(char *)(src+ i);
	return (dst);
}

/* ANOTHER WAY TO DO THE SAME

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	ssize_t	i;

	i = -1;
	if (!dst || !src)
		return (FT_NULL);
	while (++i < n)
		((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}

*/
