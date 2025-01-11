/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:37:59 by mely-pan          #+#    #+#             */
/*   Updated: 2024/05/22 20:13:09 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*aux;

	if (!lst || !del)
		return ;
	aux = *lst;
	while (aux)
	{
		tmp = aux;
		aux = aux->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
