/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admoufle <admoufle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:08:37 by admoufle          #+#    #+#             */
/*   Updated: 2025/04/24 13:19:09 by admoufle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	free_lst(t_buf **lst)
{
	t_buf	*tmp;

	while (*lst && (*lst)->next != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->str)
			free(tmp->str);
		if (tmp)
			free(tmp);
	}
	if (*lst && (*lst)->str)
		free((*lst)->str);
	if (*lst)
		free(*lst);
	return (0);
}

int	is_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

t_buf	*gnl_new_elem(char *buf)
{
	t_buf	*new;
	int		i;

	i = -1;
	new = malloc(sizeof(t_buf));
	if (!new)
		return (NULL);
	new->str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new->str)
		return (free(new), NULL);
	while (buf && buf[++i])
		(new->str)[i] = buf[i];
	(new->str)[i] = 0;
	new->next = NULL;
	return (new);
}

int	new_elem_back(t_buf **begin, char *buf)
{
	t_buf	*tmp;
	t_buf	*new;

	if (buf && buf[0] == 0)
		return (free(buf), 0);
	new = gnl_new_elem(buf);
	if (!new)
		return (free_lst(begin), -1);
	tmp = *begin;
	if (*begin == NULL)
	{
		*begin = new;
		return (0);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (dst && src && size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	len = 0;
	while (src[len])
		len++;
	return (len);
}
