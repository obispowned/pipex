/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:45:53 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/05 20:20:18 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size1;
	size_t	size2;
	size_t	i;

	if (!(s1 && s2))
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!(dest))
		return (0);
	i = -1;
	while (++i < size1)
		dest[i] = s1[i];
	i = -1;
	while (++i < size2)
		dest[size1 + i] = s2[i];
	dest[size1 + size2] = 0;
	return (dest);
}

char	*ft_strjoint(char *str, char c)
{
	char	*finally;
	int		i;

	i = 0;
	finally = (char *)malloc(((sizeof(char *)) * ft_strlen(str)) + 2);
	if (!(finally))
		print_exit("ERROR: malloc my_strjoin ha fallado");
	while (str[i] != '\0')
	{
		finally[i] = str[i];
		i++;
	}
	finally[i] = c;
	finally[i + 1] = '\0';
	return (finally);
}

char	*ft_strchr(const char *s, int c)
{
	char	*sc;

	sc = (char *)s;
	while ((*sc) && (*sc != (char)c))
		sc++;
	if (*sc == (char)c)
		return (sc);
	else
		return (0);
}

char	*ft_strdup(char *str)
{
	char	*finally;
	int		i;

	i = 0;
	finally = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!(finally))
		printf("Malloc ha fallado en: ft_strdup.c");
	while (str[i] != '\0')
	{
		finally[i] = str[i];
		i++;
	}
	finally[i] = '\0';
	return (finally);
}
