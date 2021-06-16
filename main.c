/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:51:22 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/16 21:48:39 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

int		run_child_in(t_pipex *ppx)
{
	close (ppx->pipefd[READ_END]);
//dup2 para establecer la salida al inicio de la tuberia
//execve() para arrancar el comando
}

int		run_child_out(t_pipex *ppx)
{
//	open del argumento 5
//	dup2(fd, stdout) para tomar la salida del pipe como etrada
//		close (ppx->pipefd[WRITE_END]);
//	dup2(fd ,stdout);
//execve() para arrancar el comando
}

int		main(int argc, char **argv, char **envp)
{
	t_pipex ppx;
	pid_t pid;

	if (!(check_args(argc, argv)))
		return(print_err("Argumentos erroneos"));
	pipe(ppx.pipefd);
	pid = fork();
	if (pid == -1)
		return(print_err("Error al crear el proceso hijo"));
	if (pid == 0)
		run_child_process_in(&ppx);
	else
	{
		pid = fork();
		if (pid == -1)
			return(print_err("Error al crear el proceso hijo"));
		if (pid == 0)
			run_child_process_out(&ppx);
		else
		{
			wait(NULL);
			close(ppx.pipefd[0]);
			close(ppx.pipefd[1]);
		}
	}

	return (1);
}
