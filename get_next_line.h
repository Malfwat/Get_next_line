/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admoufle <admoufle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:08:54 by admoufle          #+#    #+#             */
/*   Updated: 2025/04/24 13:08:56 by admoufle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 60
# endif /*BUFFER_SIZE*/

# if (BUFFER_SIZE < 0)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_stash
{
	char			*str;
	struct s_stash	*next;
}t_buf;

char	*get_next_line(int fd);
char	*get_line(int fd, char *stash, char **line, t_buf *lst);
int		check_stash(char **stash, char	**line, char *new_stash, int i);
int		join_t_buf(t_buf **begin, char **stash, char **line);
int		new_elem_back(t_buf **begin, char *buf);
int		is_in_str(char *str, char c);
int		free_lst(t_buf **lst);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif /*GET_NEXT_LINE_H*/