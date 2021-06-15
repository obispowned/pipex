/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:47:18 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/15 19:39:40 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct	s_ppx
{
	int		fd_i;
	int		fd_o;
	int		pipefd[2];
	char	*cmd1;
	char	*cmd2;
	char	**envp;
	char	*path;
	int		dirfd;
}				t_ppx;

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

#endif
