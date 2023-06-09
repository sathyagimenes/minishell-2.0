/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:01:52 by briferre          #+#    #+#             */
/*   Updated: 2023/05/02 18:11:16 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_string	ft_strcpy(t_string src, t_bool src_free)
{
	int			i;
	int			src_size;
	t_string	dest;

	src_size = ft_strlen(src);
	dest = malloc(sizeof(char) * src_size + sizeof(char));
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	if (src_free)
		ft_free(src);
	return (dest);
}

t_string	ft_strcat(t_string src1, t_string src2, t_bool free1, t_bool free2)
{
	int			i;
	int			j;
	t_string	new_dest;

	if (!src2)
		return (src1);
	i = ft_strlen(src1) + ft_strlen(src2) + 1;
	new_dest = malloc(sizeof(char) * i);
	j = -1;
	i = -1;
	while (src1[++j])
		new_dest[++i] = src1[j];
	j = -1;
	while (src2[++j])
		new_dest[++i] = src2[j];
	new_dest[++i] = '\0';
	if (free1)
		ft_free(src1);
	if (free2)
		ft_free(src2);
	return (new_dest);
}

t_string	ft_strcatc(t_string src1, char src2, t_bool free1)
{
	int			i;
	int			j;
	t_string	new_dest;

	if (!src2)
		return (src1);
	if (src1)
		i = ft_strlen(src1) + 2;
	else
		i = 2;
	new_dest = malloc(sizeof(char) * i);
	j = 0;
	i = -1;
	if (src1)
	{
		while (src1[j])
			new_dest[++i] = src1[j++];
	}
	new_dest[++i] = src2;
	new_dest[++i] = '\0';
	if (free1)
		ft_free(src1);
	return (new_dest);
}

t_string	ft_strrpc(t_string dest, t_string src, t_bool free1, t_bool free2)
{
	if (free1)
		ft_free(dest);
	return (ft_strcpy(src, free2));
}

int	ft_strcmp(t_string str1, t_string str2)
{
	int	i;

	if ((ft_strlen(str1) - ft_strlen(str2)) != 0)
		return (-1);
	i = -1;
	while (str1[++i])
		if (str1[i] - str2[i] != 0)
			return (str1[i] - str2[i]);
	return (0);
}
