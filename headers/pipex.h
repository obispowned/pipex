/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:47:18 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/17 17:00:19 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ_END 0
# define WRITE_END 1

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct	s_pipex
{
	int		fd_i;
	int		fd_o;
	int		pipefd[2];
	char	*cmd1;
	char	*cmd2;
	char	**envp;
	char	*path;
	int		dirfd;
}				t_pipex;

/*
*		msgs
*/
void	ft_putchar(char *str);
int		print_err(char *str);
void	print_exit(char *str);

/*
*		checkers
*/
int		check_argv(char *argv);
int		check_args(int argc, char **argv);

int		run_child_in(t_pipex *ppx);
int		run_child_out(t_pipex *ppx, char *str);

#endif
