/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:02:59 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/12 19:23:18 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>

void	ft_putchar(int c, int *count);
void	ft_putstr(char	*str, int *count);
void	ft_putnbr(int n, int *count);
int		ft_printf(const char *format, ...);
void	ft_putunsigned(unsigned int n, int *count);
void	ft_puthex(unsigned long n, int uppercase, int *count);
void	ft_putptr(void *ptr, int *count);

#endif