/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:52:43 by isibio            #+#    #+#             */
/*   Updated: 2022/12/07 15:54:50 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		flag_d(int number);
int		flag_i(int number);
int		flag_u(unsigned int number);
int		flag_percent(void);
int		flag_c(const char c);
int		flag_s(const char *s);
int		flag_x(unsigned int number);
int		flag_x2(unsigned int number);
int		flag_p(unsigned long long c);
int		flag_ull(unsigned long long number);
char	*ft_utoa(unsigned int n);
int		ft_printf(const char *s, ...);

#endif
