/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:05:36 by osarihan          #+#    #+#             */
/*   Updated: 2023/04/13 06:42:07 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *asd, char *sda)
{
	int		i;
	size_t	len;

	len = ft_strlen(sda);
	i = 0;
	while (len)
	{
		if (asd[i] == sda[i])
			i++;
		else
			return (1);
		len--;
	}
	if (asd[i] != '\0')
		return (1);
	return (0);
}

int	check_char(char *asd, char c)
{
	int	i;

	i = 0;
	while (asd[i] != c && asd[i] != '\0')
		i++;
	if (i == ft_strlen(asd) && asd[i] != c)
		return (0);
	else
		return (1);
	return (0);
}
