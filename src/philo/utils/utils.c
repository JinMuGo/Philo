/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:16:30 by jgo               #+#    #+#             */
/*   Updated: 2023/03/23 19:51:28 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "state_control.h"

uint64_t	char_to_uint64(const char *str)
{
	uint64_t	result;
	int			sign;
	int			i;

	if (get_proc_state() == SET_ERROR)
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
		result = result * 10 + str[i++] - '0';
	if (sign == -1 || str[i] != '\0')
	{
		set_proc_state(SET_ERROR);
		return (0);
	}
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	dst = malloc(size * count);
	if (dst)
		memset(dst, 0, size * count);
	else
		return (NULL);
	return (dst);
}

static size_t	cal_num_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	tmp;
	char			*num;
	int				len;
	int				for_minus;

	for_minus = 0;
	len = cal_num_len(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return ((void *)0);
	tmp = n;
	if (n < 0)
	{
		tmp *= -1;
		num[0] = '-';
		for_minus++;
	}
	num[len] = '\0';
	while (len-- > for_minus)
	{
		num[len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (num);
}


// void	clear_all_asset(t_meta *meta)
// {
	
// }