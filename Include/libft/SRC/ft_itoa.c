/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:52:25 by mely-pan          #+#    #+#             */
/*   Updated: 2024/05/22 20:19:21 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isneg(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_get_int_len(long n)
{
	long	size;

	size = 0;
	if (ft_isneg(n))
	{
		size++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		len;
	int		sign;

	nbr = n;
	len = ft_get_int_len(nbr);
	str = (char *)malloc(sizeof (char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	sign = 0;
	if (ft_isneg(nbr))
	{
		nbr = -nbr;
		sign = 1;
	}
	while (--len >= 0)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
// the function itoa convert an integer to a string, for that, we must know
// the length which the converted integer will ocuppy, that's why we use
// the ft_get_int_len() so we know how many characters we need to allocate,
// including the null-terminator, we also use the length returned by the
// same funtion to iterate over the string the position to be null-terminated
// is the str[len], the last if is used when the number is positive,
// so we guarantee the last (first) number to be allocated in the position
// str[0]