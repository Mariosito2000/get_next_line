/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:03:17 by marias-e          #+#    #+#             */
/*   Updated: 2022/10/07 11:34:54 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BUFFER_SIZE 42

char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
