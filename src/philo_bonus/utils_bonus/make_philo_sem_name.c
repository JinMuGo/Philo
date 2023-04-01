/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo_sem_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:55:38 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 19:26:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
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

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return ((void *)0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return ((void *)0);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		str[i] = s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*make_philo_sem_name(int n)
{
	const char	*default_philo_sem = "/philo_";
	const char	*idx_name = ft_itoa(n);
	char		*rv;

	if (idx_name == NULL)
		return (NULL);
	rv = ft_strjoin(default_philo_sem, idx_name);
	if (rv)
		return (rv);
	else
		return (NULL);
}
