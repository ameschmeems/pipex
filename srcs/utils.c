/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:32:38 by kpucylo           #+#    #+#             */
/*   Updated: 2022/03/04 20:27:27 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &(s[i]), 1);
		i++;
	}
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
	{
		return ((char *)big);
	}
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
		}
		if (!little[j])
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	front;
	size_t	back;
	char	*dest;

	if (!s1 && !set)
	{
		return (NULL);
	}
	front = 0;
	back = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
	{
		front++;
	}
	while (back && ft_strchr(set, s1[back - 1]) && back > front)
	{
		back--;
	}
	dest = malloc(sizeof(char) * (back - front + 1));
	if (!dest)
	{
		return (NULL);
	}
	ft_strlcpy(dest, s1 + front, back - front + 1);
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
	{
		return (NULL);
	}
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = 0;
	return (ptr);
}

void	close_descriptors(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
