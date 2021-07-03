/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:45:53 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/03 18:23:29 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/pipex.h"

void			double_kill(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	size_t			size1;
	size_t			size2;
	size_t			i;

	if (!(s1 && s2))
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(dest = (char *)malloc(sizeof(char) * (size1 + size2 + 1))))
		return (0);
	i = 0;
	while (i < size1)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < size2)
	{
		dest[size1 + i] = s2[i];
		i++;
	}
	dest[size1 + size2] = 0;
	return (dest);
}

char				*ft_strjoint(char *str, char c)
{
	char			*finally;
	int				i;

	i = 0;
	if (!(finally = (char *)malloc((sizeof(char *)) * ft_strlen(str)) + 2))
	{
		printf("ERROR: malloc my_strjoin ha fallado");
		exit(-1);
	}
	while (str[i] != '\0')
	{
		finally[i] = str[i];
		i++;
	}
	finally[i] = c;
	finally[i + 1] = '\0';
	return (finally);
}

char		*ft_strchr(const char *s, int c)
{
	char	*sc;

	sc = (char *)s;
	while (*sc && *sc != (char)c)
		sc++;
	return ((*sc == (char)c) ? sc : 0);
}

char		*ft_strdup(char *str)
{
	char	*finally;
	int		i;

	i = 0;
	if (!(finally = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		printf("Malloc ha fallado en: ft_strdup.c");
	while (str[i] != '\0')
	{
		finally[i] = str[i];
		i++;
	}
	finally[i] = '\0';
	return (finally);
}

int					ft_strlen(const char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
