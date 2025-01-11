/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:31:15 by mely-pan          #+#    #+#             */
/*   Updated: 2024/05/13 20:06:07 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*init_str;

	if (nmemb > 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	init_str = malloc(size * nmemb);
	if (!init_str)
		return (NULL);
	ft_memset(init_str, 0, (size * nmemb));
	return (init_str);
}
