/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:53:55 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 18:55:17 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

class Dummy : public ATarget {
	public:
		Dummy();
		Dummy(const Dummy &ref);
		~Dummy();
	
		Dummy& operator=(const Dummy &ref);

		Dummy* clone() const;
};