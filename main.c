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
		close (ppx.pipefd[WRITE_END]);
		pid = fork();
		if (pid == -1)
			return(print_err("Error al crear el proceso hijo"));
		if (pid == 0)
			run_child_process_out(&ppx, argv[5]);
		else
			close (ppx.pipefd[WRITE_END]);
		wait(NULL);
		wait(NULL);
	}

	return (1);
}
