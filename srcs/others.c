/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeaure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:24:23 by ybeaure           #+#    #+#             */
/*   Updated: 2016/12/14 20:45:55 by ybeaure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		array_size(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**ft_arrsub(char **src, unsigned int start, unsigned int len)
{
	char			**out;
	unsigned int	i;

	i = 0;
	if (src == NULL || i + len > (unsigned int)array_size(src))
		return (NULL);
	out = (char **)malloc(sizeof(char *) * (len + 1));
	while (i < len && src[start] != NULL)
		out[i++] = ft_strdup(src[start++]);
	out[i] = NULL;
	return (out);
}
