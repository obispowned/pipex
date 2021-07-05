/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:03:20 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/05 19:24:13 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	check_argv(char *argv)
{
	if (!argv)
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5)
		return (0);
	while (i < argc)
	{
		if (!(check_argv(argv[i])))
			return (0);
		i++;
	}
	return (1);
}

void	args(t_pipex *ppx, int argc, char **argv, char **envp)
{
	if (!(check_args(argc, argv)))
		return (print_exit("Argumentos erroneos"));
	ppx->fd_i = open(argv[1], O_RDONLY);
	ppx->cmd1 = argv[2];
	ppx->cmd2 = argv[3];
	ppx->fd_o = open(argv[4], O_WRONLY
			| O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
	if (ppx->fd_i == -1 || ppx->fd_o == -1)
		return (print_exit("Error:\nArgumentos erroneos.\n"));
	ppx->envv = get_all_path(envp, "PATH=");
	ppx->envv[0] = strchr(ppx->envv[0], '/');
}
