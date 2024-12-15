/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:01:00 by antbonin          #+#    #+#             */
/*   Updated: 2024/12/12 20:33:49 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# define HEXA_CAPS "0123456789ABCDEF"
# define HEXA_MIN "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	ft_specifier(char specifier, va_list ap);
int	ft_printdecimal(long int n);
int	ft_printundecimal(unsigned int n);
int	ft_printhexa(unsigned long int n, char hex);
int	ft_printpointer(void *s);
#endif