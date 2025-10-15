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

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		fp_flag_d(int fd, int number);
int		fp_flag_i(int fd, int number);
int		fp_flag_u(int fd, unsigned int number);
int		fp_flag_c(int fd, const char c);
int		fp_flag_s(int fd, const char *s);
int		fp_flag_x(int fd, unsigned int number);
int		fp_flag_x2(int fd, unsigned int number);
int		fp_flag_p(int fd, unsigned long long c);
int		fp_flag_ull(int fd, unsigned long long number);
char	*ft_utoa(unsigned int n);
int		ft_fprintf(int fd, const char *s, ...);

#endif
