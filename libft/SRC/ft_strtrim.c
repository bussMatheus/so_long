/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:59:31 by mely-pan          #+#    #+#             */
/*   Updated: 2024/04/23 20:29:00 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	check_char(char const *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	char	*new_s_ptr;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (*(s1 + start) && check_char(set, *(s1 + start)))
		start++;
	end = ft_strlen(s1);
	while (end > start && check_char(set, *(s1 + (end - 1))))
		end--;
	new_s = (char *)malloc(sizeof (char) * (end - start + 1));
	if (!new_s)
		return (NULL);
	new_s_ptr = new_s;
	while (start < end)
		*new_s++ = *(s1 + start++);
	*new_s = '\0';
	return (new_s_ptr);
}
