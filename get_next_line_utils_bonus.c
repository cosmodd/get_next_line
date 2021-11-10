/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:23:47 by mrattez           #+#    #+#             */
/*   Updated: 2021/11/10 12:04:25 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	sublen;
	size_t	i;

	if (start > (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	sublen = 0;
	while (s[start + sublen] && sublen < len)
		sublen++;
	dst = malloc((sublen + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (i < sublen)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	char	*out;
	char	search;

	out = (char *)s;
	search = c;
	while (*out)
	{
		if (*out == search)
			return (out);
		out++;
	}
	if (*out == c)
		return (out);
	return ((void *)0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}
