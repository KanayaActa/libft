#include <ft_string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*_dest;
	size_t	len;

	_dest = dest;
	dest += ft_strlen(dest);
	len = ft_strnlen(src, n);
	dest[len] = '\0';
	ft_memcpy(dest, src, len);
	return (_dest);
}
