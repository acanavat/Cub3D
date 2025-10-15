/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:46:52 by isibio            #+#    #+#             */
/*   Updated: 2022/12/07 15:46:53 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sprintf.h"

char	*fts_flag_x(unsigned int number)
{
	char	*ret;

	ret = ft_ctos('\0');
	if (number >= 16)
	{
		ret = ft_freejoin(ret, fts_flag_x(number / 16));
		ret = ft_freejoin(ret, fts_flag_x(number % 16));
	}
	if (number <= 9)
		ret = ft_freejoin(ret, ft_ctos(number + '0'));
	else if (number > 9 && number < 16)
		ret = ft_freejoin(ret, ft_ctos((number - 10) + 'a'));
	return (ret);
}

char	*fts_flag_x2(unsigned int number)
{
	char	*ret;

	ret = ft_ctos('\0');
	if (number >= 16)
	{
		ret = ft_freejoin(ret, fts_flag_x2(number / 16));
		ret = ft_freejoin(ret, fts_flag_x2(number % 16));
	}
	if (number <= 9)
		ret = ft_freejoin(ret, ft_ctos(number + '0'));
	else if (number > 9 && number < 16)
		ret = ft_freejoin(ret, ft_ctos((number - 10) + 'A'));
	return (ret);
}

char	*fts_flag_p(unsigned long long c)
{
	char	*ret;

	ret = 0;
	if (c == 0)
		return (ft_strdup("0x0"));
	ret = ft_freejoin(ft_strdup("0x"), fts_flag_ull(c));
	return (ret);
}

char	*fts_flag_ull(unsigned long long number)
{
	char	*ret;

	ret = ft_ctos('\0');
	if (number >= 16)
	{
		ret = ft_freejoin(ret, fts_flag_ull(number / 16));
		ret = ft_freejoin(ret, fts_flag_ull(number % 16));
	}
	if (number <= 9)
		ret = ft_freejoin(ret, ft_ctos(number + '0'));
	else if (number > 9 && number <= 15)
		ret = ft_freejoin(ret, ft_ctos((number - 10) + 'a'));
	return (ret);
}
