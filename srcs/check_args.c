/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:03:20 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/15 19:03:22 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/pipex.h"

int		check_argv(char *argv)
{
	// A esta funcion llegan los argv[i] en bucle para checkear cada argumento
	return (1);
}

int		check_args(int argc, char **argv)
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
