/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:08:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/12 18:55:52 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

int ft_printf(const char *format, ...);
int ft_print_c1(const char c, va_list ap);
int ft_print_c2(const char c, va_list ap);
char	*ft_utoa(unsigned int u);
char	*ft_utohex(unsigned int u, int upc);

#endif