/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:25:11 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/22 14:15:30 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdlib.h>
#include <iostream>
class Base
{
	public:
		Base() = default;
		static Base *generate(void);
		static void identify(Base* p);
		static void identify(Base& p);
		virtual ~Base() = default;
};
