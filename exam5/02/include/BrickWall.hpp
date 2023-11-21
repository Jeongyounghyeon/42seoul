/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:31:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/21 18:47:02 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

class BrickWall : public ATarget {
	public:
		BrickWall();
		BrickWall(const std::string& type);
		BrickWall(const BrickWall& ref);
		virtual ~BrickWall();

		BrickWall& operator=(const BrickWall& ref);

		const std::string& getType() const;

		virtual BrickWall* clone() const;
};