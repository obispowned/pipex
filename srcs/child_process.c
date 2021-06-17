/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:00:34 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/17 17:00:56 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int		run_child_in(t_pipex *ppx)
{
	close (ppx->pipefd[READ_END]);
	dup2 (ppx->pipefd[WRITE_END], STDOUT_FILENO); // para establecer la salida al inicio de la tuberia
	close (ppx->pipefd[WRITE_END]);
//	execve(); // para arrancar el comando
}

int		run_child_out(t_pipex *ppx, char *str)
{
	int	fd;

	fd = open (str, O_WRONLY);
	dup2(ppx->pipefd[READ_END], STDIN_FILENO);
	close (ppx->pipefd[READ_END]);
	dup2(fd ,STDOUT_FILENO);
//	execve(); para arrancar el comando
}
