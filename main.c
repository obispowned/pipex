/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:51:22 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/17 17:08:27 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

void	waits(int x)
{
	int i;
	
	i = 0;
	while (i < x)
	{
		wait(NULL);
		i++;
	}
}

int	check_line(char *envp)
{
	int i;
	char *path;

	path = "PATH=";
	i = 0;
	while (i < 5)
	{
		if (path[i] != envp[i])
			return (0);
	}
	return (1);
}

int	get_position(char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		if(check_line(envp[i]))
			return (i);
	}
}

char **get_all_path(char **envp, char *search)
{
	int i;
	char **str;

	i = get_position(envp);
	write(1, envp[i],4);
	system("pause"); 
	str = ft_split(envp[i], ':');
	return (str);
}


void	args(t_pipex *ppx, int argc, char **argv, char **envp)
{
	if (!(check_args(argc, argv)))
		return(print_exit("Argumentos erroneos"));
	ppx->fd_i = open(argv[1], O_RDONLY);
	ppx->fd_o = open(argv[4], O_RDONLY);
	if (!ppx->fd_i || !ppx->fd_o)
		return(print_exit("Argumentos erroneos"));
	ppx->envv = get_all_path(envp, "PATH=");

}

int		main(int argc, char **argv, char **envp)
{
	t_pipex ppx;
	pid_t pid;

	args(&ppx, argc, argv, envp);
	pipe(ppx.pipefd);
	pid = fork();
	if (pid == -1)
		return(print_err("Error al crear el proceso hijo"));
	if (pid == 0)
		run_child_in(&ppx);
	else
	{
		close (ppx.pipefd[WRITE_END]);
		pid = fork();
		if (pid == -1)
			return(print_err("Error al crear el proceso hijo"));
		if (pid == 0)
			run_child_out(&ppx, argv[5]);
		else
			close (ppx.pipefd[WRITE_END]);
		waits(2);
	}
	return (1);
}
