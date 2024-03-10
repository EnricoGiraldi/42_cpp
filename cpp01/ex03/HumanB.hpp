/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engirald <engirald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:17:46 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/20 16:25:10 by engirald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon& bWeapon;

	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon* bWeapon);
		~HumanB();
		void setWeapon(Weapon &newWeapon);
		void attack();
};

#endif
