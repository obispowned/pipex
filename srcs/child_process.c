/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:00:34 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/03 19:49:07 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"



char	*search_cmd(t_pipex *ppx, char *command)
{
	int	i;
	int fd_cmd;
	char *path_try;
	char *correct_path;

	i = 0;
	path_try = ft_strjoint(ppx->envv[i], '/');
	path_try = ft_strjoin(path_try, command);
	while (path_try)
	{
		fd_cmd = open(path_try, O_RDONLY);
		if (fd_cmd >= 0)
		{
			correct_path = ft_strdup(path_try);
			free(path_try);
			close(fd_cmd);
			return (correct_path);
		}
		free(path_try);
		path_try = ft_strjoint(ppx->envv[i], '/');
		path_try = ft_strjoin(path_try, command);
		i++;
	}
	return (NULL);
}


void		run_child_in(t_pipex *ppx, char **envp)
{
	char	**command_in;
	char	*correct_path;

	close (ppx->pipefd[READ_END]);
	command_in = ft_split(ppx->cmd1, ' ');
	correct_path = search_cmd(ppx, command_in[0]);
	//printf("correct_path_in: %s\n", correct_path);
	if (!correct_path)
		print_exit("Error\nPonga un comando existente...\n");
	dup2 (ppx->fd_i, STDIN_FILENO);
	dup2 (ppx->pipefd[WRITE_END], STDOUT_FILENO); // para establecer la salida al inicio de la tuberia
	close (ppx->fd_i);
	close (ppx->pipefd[WRITE_END]);
	execve(correct_path, command_in, envp);
}

void		run_child_out(t_pipex *ppx, char **envp)
{
	char	**command_out;
	char	*correct_path;

	command_out = ft_split(ppx->cmd2, ' ');
	correct_path = search_cmd(ppx, command_out[0]);
	//printf("correct_path_out: %s\n", correct_path);
	if (!correct_path)
		print_exit("Error\nPonga un comando existente...\n");
	dup2(ppx->fd_o, STDOUT_FILENO);
	dup2(ppx->pipefd[READ_END], STDIN_FILENO);
	close(ppx->fd_o);
	close (ppx->pipefd[READ_END]);
	execve(correct_path, command_out, envp);
}
