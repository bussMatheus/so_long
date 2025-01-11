/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:40:28 by mely-pan          #+#    #+#             */
/*   Updated: 2024/05/08 19:19:34 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;

	if (!big && !len)
		return (NULL);
	if (!little)
		return ((char *)big);
	while (*big && len)
	{
		j = 0;
		while (*(big + j) == *(little + j) && *(little + j) && j < len)
		{
			if (*(little + j + 1) == '\0' || *(big + 1) == '\0')
				return ((char *)big);
			j++;
		}
		big++;
		len--;
	}
	if (big == little)
		return ((char *)big);
	return (NULL);
}
