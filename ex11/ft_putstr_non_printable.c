/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:55:50 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/03/26 11:24:33 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(int num)
{
	if (num < 16)
	{
		if (num < 10)
		{
			ft_putchar(num + '0');
		}
		else
		{
			ft_putchar(num + 87);
		}
		return ;
	}
	else
	{
		ft_puthex(num / 16);
		if (num % 16 < 10)
		{
			ft_putchar((num % 16) + '0');
		}
		else
		{
			ft_putchar((num % 16) + 87);
		}
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			if (str[i] < 16)
			{
				ft_putchar('0');
			}
			ft_puthex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
/*
int	main(void)
{
	ft_putstr_non_printable("Oi\nvoce esta bem?");
}
*/
