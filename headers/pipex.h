/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:47:18 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/03 19:56:03 by agutierr         ###   ########.fr       */
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

typedef struct s_pipex
{
	int		fd_i;
	int		fd_o;
	int		pipefd[2];
	char	*cmd1;
	char	*cmd2;
	char	**envv;
	int		dirfd;
}				t_pipex;

/*
*      libft
*/
char				**ft_split(char const *s, char c);
void				double_kill(char **str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoint(char *str, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(char *str);
int					ft_strlen(const char *str);

/*
*		msgs
*/
void				ft_putchar(char *str);
int					print_err(char *str);
void				print_exit(char *str);

/*
*		checkers
*/
void				args(t_pipex *ppx, int argc, char **argv, char **envp);
int					check_argv(char *argv);
int					check_args(int argc, char **argv);
int					check_line(char *envp);

/*
*		program
*/
void				run_child_in(t_pipex *ppx, char **envp);
void				run_child_out(t_pipex *ppx, char **envp);
char				*search_cmd(t_pipex *ppx, char *command);
char				**get_all_path(char **envp, char *search);

#endif
