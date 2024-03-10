/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engirald <engirald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:56:35 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/20 16:20:50 by engirald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string brian = "HI THIS IS BRAIN";
	std::string* strignPTR = &brian;
	std::string& stringREF = brian;

	std::cout << &brian << std::endl;
	std::cout << &strignPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << brian << std::endl;
	std::cout << *strignPTR << std::endl;
	std::cout << stringREF << std::endl;

}
