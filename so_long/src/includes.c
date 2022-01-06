/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:51:35 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/06 17:43:21 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_intlen(int c)
{
	int	len;

	len = 0;
	if (c <= 0)
		len++;
	while (c != 0)
	{
		len++;
		c = c / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	num;

	len = ft_intlen(n);
	num = n;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (num)
	{
		str[len--] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit_error(8);
	mlx->win = mlx_new_window(mlx->mlx, mlx->columns * PIXELS,
			mlx->lines * PIXELS, "so_long");
	if (!mlx->win)
		exit_error(8);
}
