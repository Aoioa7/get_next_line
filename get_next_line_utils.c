/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aichida <aichida@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:58:57 by aichida           #+#    #+#             */
/*   Updated: 2024/07/06 02:27:09 by aichida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// const -> can't s++

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

// return where c is

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*temp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[i])
	{
		len++;
		i++;
	}
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	i = 0;
	while (i < len)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

// null guard

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		temp[i++] = s1[j++];
	j = 0;
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = '\0';
	return (temp);
}

char	*ft_substr(const char *s, unsigned int start_index, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	if (!s)
		return (NULL);
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start_index && j <= len - 1)
		{
			temp[j] = s[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	return (temp);
}
