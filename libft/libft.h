/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:35:48 by mely-pan          #+#    #+#             */
/*   Updated: 2024/05/22 20:25:50 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>

# define BUFFER_SIZE 10

/*--------------------------------------- */
/*              MEMORY FUNCTIONS          */

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

/*---------------------------------------*/
/*              STRING FUNCTIONS         */

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/*---------------------------------------*/
/*              WRITE FUNCTIONS          */

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

/*---------------------------------------*/
/*              	GNL	               */
char	*ft_strjoin_gnl(char *s1, char *s2);
int		cut_remaining(char *buf);
char	*get_next_line(int fd);

#endif
