/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:51:22 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/15 19:38:05 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

int		main(int argc, char **argv, char **envp)
{
	if (!(check_args(argc, argv)))
		return(print_err("Argumentos erroneos"));
	return (1);
}
