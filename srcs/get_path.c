/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:44:16 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/03 20:03:16 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	check_line(char *envp)
{
	int		i;
	char	*path;

	path = "PATH=";
	i = 0;
	while (i < 5)
	{
		if (path[i] != envp[i])
			return (0);
		i++;
	}
	return (1);
}

int	get_position(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (check_line (envp[i]))
			return (i);
		i++;
	}
	return (-1);
}

char	**get_all_path(char **envp, char *search)
{
	int		i;
	char	**str;

	i = get_position(envp);
	str = ft_split(envp[i], ':');
	return (str);
}
