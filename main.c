/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:51:22 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/03 19:54:15 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

void	waits(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		wait(NULL);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	ppx;
	pid_t	pid;

	args(&ppx, argc, argv, envp);
	pipe(ppx.pipefd);
	pid = fork();
	if (pid == -1)
		return (print_err("Error al crear el proceso hijo"));
	if (pid == 0)
		run_child_in(&ppx, envp);
	else
	{
		close (ppx.pipefd[WRITE_END]);
		pid = fork();
		if (pid == -1)
			return (print_err("Error al crear el proceso hijo"));
		if (pid == 0)
			run_child_out(&ppx, envp);
		else
			close (ppx.pipefd[READ_END]);
		waits(2);
	}
	return (0);
}
