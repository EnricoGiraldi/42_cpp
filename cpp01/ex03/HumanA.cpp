/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:27:33 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/20 15:13:17 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& aWeapon): name(name), aWeapon(aWeapon)
{}

HumanA::~HumanA()
{
	std::cout << "The Human left the battle" <<std::endl;
}

void HumanA::attack()
{
	std::cout << this->name;
	std::cout <<" Attacked with: " << this->aWeapon.getType() << std::endl;
}
