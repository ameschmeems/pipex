/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:25:22 by kpucylo           #+#    #+#             */
/*   Updated: 2022/03/04 20:35:36 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	*str;
	char	**path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	str = ft_strtrim(envp[i], "PATH=");
	path = ft_split(str, ':');
	free(str);
	i = 0;
	while (path[i])
	{
		str = ft_strjoin(path[i], "/");
		free(path[i]);
		path[i] = str;
		i++;
	}
	return (path);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	execute_command(char *command, char **path, char **envp)
{
	int		i;
	char	*cmd;
	char	**cmd_flags;

	i = 0;
	cmd_flags = ft_split(command, ' ');
	while (path[i])
	{
		cmd = ft_strjoin(path[i], cmd_flags[0]);
		execve(cmd, cmd_flags, envp);
		free(cmd);
		i++;
	}
	free_array(path);
	perror(cmd_flags[0]);
	free_array(cmd_flags);
	exit(3);
}

//fd[0] - read
//fd[1] - write

void	spawn_process(char *command, char **path, char **envp)
{
	pid_t	pid;
	int		fd[2];

	check_fd(pipe(fd), "pipe failed");
	pid = fork();
	check_fd(pid, "fork failed");
	if (pid == 0)
	{
		check_fd(dup2(fd[1], 1), "dup2 failed");
		close(fd[0]);
		execute_command(command, path, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fd_infile;
	int		fd_outfile;
	char	**path;

	check_argc(argc);
	fd_infile = open(argv[1], O_RDONLY);
	check_fd(fd_infile, argv[1]);
	fd_outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	check_fd(fd_outfile, argv[argc - 1]);
	check_fd(dup2(fd_infile, 0), "dup2 failed");
	check_fd(dup2(fd_outfile, 1), "dup2 failed");
	path = get_path(envp);
	i = 2;
	while (i < argc - 2)
	{
		spawn_process(argv[i], path, envp);
		i++;
	}
	execute_command(argv[i], path, envp);
	close_descriptors(fd_infile, fd_outfile);
	return (0);
}
