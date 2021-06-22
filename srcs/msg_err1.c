/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_err1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:03:35 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/15 19:03:38 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i] ,1);
		i++;
	}
}

int		print_err(char *str)
{
	ft_putchar(str);
	return (0);
}

void	print_exit(char *str)
{
	ft_putchar(str);
	exit(0);
}
