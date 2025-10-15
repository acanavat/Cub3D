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

#ifndef FT_SPRINTF_H
# define FT_SPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# include <stdio.h> //

char	*ft_sprintf(const char *s, ...);
char	*fts_flag_d(int number);
char	*fts_flag_i(int number);
char	*fts_flag_u(unsigned int number);
char	fts_flag_c(const char c);
char	*fts_flag_s(const char *s);
char	*fts_flag_x(unsigned int number);
char	*fts_flag_x2(unsigned int number);
char	*fts_flag_p(unsigned long long c);
char	*fts_flag_ull(unsigned long long number);
char	*fts_flag_f(double number);
char	*ft_utoa(unsigned int n);

#endif
