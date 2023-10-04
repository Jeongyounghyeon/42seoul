/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:41:23 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/04 22:18:24 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
private:
	int rawBits;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed& ref);
	~Fixed();
	
	Fixed& operator=(const Fixed& ref);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};