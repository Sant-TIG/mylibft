/*
NAME
****
ft_memset ---> fill memory with a constant byte

SYNOPSIS
********
#include "strings.h"
void	*ft_memset(void *mem, int c, size_t n);

PARAMETERS
**********
mem ---> the pointer to the memory space
c   ---> the character used to fill
n   ---> the number of bytes to fill

DESCRIPTION
***********
The ft_memset() function fills or sets the first 'n' bytes of the memory space
pointed to by 'mem' with the character 'c'.

RETURN VALUE
************
- A pointer to the memory space.

*/

#include <stddef.h>

void	*ft_memset(void *mem, int c, size_t n)
{
	while (n--)
		*(unsigned char *)(mem + n) = (unsigned char)c;
	return (mem);
}
