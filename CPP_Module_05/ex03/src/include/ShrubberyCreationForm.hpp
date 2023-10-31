/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:23:58 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/30 18:23:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define ASCII_TREE \
"            .        +          .      .          .\n\
	.            _        .                    .\n\
,              /;-._,-.____        ,-----.__\n\
((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n\
`                 \\   _|`\"=:_::.`.);  \\ __/ /\n\
					,    `./  \\:. `.   )==-'  .\n\
	.      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n\
.           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n\
	.    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n\
.      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n\
`.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n\
			\\:  `  X` _| _,\\/'   .-'\n\
.               \":._:`\\____  /:'  /      .           .\n\
					\\::.  :\\/:'  /              +\n\
.                 `.:.  /:'  }      .\n\
		.           ):_(:;   \\           .\n\
					/:. _/ ,  |\n\
				. (|::.     ,`                  .\n\
	.                |::.    {\\\n\
					|::.\\  \\ `.\n\
					|:::(\\    |\n\
			O       |:::/{ }  |                  (o\n\
			)  ___/#\\::`/ (O \"==._____   O, (O  /`\n\
		~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"

class ShrubberyCreationForm : public Form {
	private:
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(const std::string& name);
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

		int execute(Bureaucrat const& executor) const;
};