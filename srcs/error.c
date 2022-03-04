/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:30:45 by kpucylo           #+#    #+#             */
/*   Updated: 2022/03/04 19:28:05 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_argc(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error\nNot enough arguments\n", 2);
		exit(1);
	}
}

void	check_fd(int fd, char *s)
{
	if (fd == -1)
	{
		perror(s);
		exit(2);
	}
}
