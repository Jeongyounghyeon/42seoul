/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:41:23 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/07 17:31:47 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
	int	rawBits;
	static const int fractionalBits = 8;

public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& ref);
	~Fixed(void);

	Fixed &operator=(const Fixed& ref);
	bool operator>(const Fixed& ref) const;
	bool operator<(const Fixed& ref) const;
	bool operator>=(const Fixed& ref) const;
	bool operator<=(const Fixed& ref) const;
	bool operator==(const Fixed& ref) const;
	bool operator!=(const Fixed& ref) const;
	Fixed operator+(const Fixed& ref) const;
	Fixed operator-(const Fixed& ref) const;
	Fixed operator*(const Fixed& ref) const;
	Fixed operator/(const Fixed& ref) const;
	Fixed &operator++(void);
	const Fixed operator++(int);
	Fixed &operator--(void);
	const Fixed operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	static Fixed& min(Fixed& ref1, Fixed& ref2);
	const static Fixed& min(const Fixed& ref1, const Fixed& ref2);
	static Fixed& max(Fixed& ref1, Fixed& ref2);
	const static Fixed& max(const Fixed& ref1, const Fixed& ref2);
	
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& ref);