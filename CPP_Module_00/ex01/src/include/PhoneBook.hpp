/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:21:37 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/10 15:03:59 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "string"

# define CNT_CONTACT_MAX 8

class PhoneBook
{
private:
	Contact 	contacts[8];
	int			idx;
	int			cnt_contact;

	std::string	formatTextForColumn(std::string str) const;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void		service(void);
	void		add(void);
	void		search(void) const;
	void		toString(void) const;
};

#endif