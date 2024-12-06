/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:45:43 by rboudwin          #+#    #+#             */
/*   Updated: 2024/12/06 13:41:06 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	srand(static_cast<unsigned int>(time(0)));
	std::cout << "Start with random case " << std::endl;
	Base *ptr1 = Base::generate();
	Base::identify(ptr1);
	Base::identify(*ptr1);
	delete ptr1;
	std::cout << "Now let's do three explicit checks for A B and C" << std::endl;
	A a;
	B b;
	C c;
	Base::identify(&a);
	Base::identify(a);
	Base::identify(&b);
	Base::identify(b);
	Base::identify(&c);
	Base::identify(c);

	std::cout << "Null check: " << std::endl;
	Base::identify(nullptr);
}