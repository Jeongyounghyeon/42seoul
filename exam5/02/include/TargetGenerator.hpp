/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:52:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/21 19:03:37 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <map>

#include "ATarget.hpp"

class TargetGenerator {
	private:
		std::map <std::string, ATarget*> targets;

		TargetGenerator(const TargetGenerator& ref);

		TargetGenerator& operator=(const TargetGenerator& ref);

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget*);
		void forgetType(std::string const &);
		ATarget* createTarget(std::string const &);
};