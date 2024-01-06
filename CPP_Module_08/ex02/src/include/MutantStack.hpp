/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:36:45 by youjeong          #+#    #+#             */
/*   Updated: 2024/01/02 17:57:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;
		
		MutantStack() : std::stack<T, Container>() {}
		MutantStack(const MutantStack& ref): std::stack<T, Container>(ref) {}
		virtual ~MutantStack() { }

		MutantStack& operator=(const MutantStack& ref) {
			if (this != &ref) {
				this->c = ref.c;
			}
			return *this;
		}

		iterator begin() { return this->c.begin(); }
		const_iterator begin() const { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		const_iterator end() const { return this->c.end(); }
		
		reverse_iterator rbegin() { return this->c.rbegin(); }
		const_reverse_iterator rbegin() const { return this->c.begin(); }
		reverse_iterator rend() { return this->c.rend(); }
		const_reverse_iterator rend() const { return this->c.rend(); }

		const_iterator cbegin() const { return this->c.begin(); }
		const_iterator cend() const { return this->c.end(); }

		const_reverse_iterator crbegin() const { return this->c.rbegin(); }
		const_reverse_iterator crend() const { return this->c.rend(); }
};