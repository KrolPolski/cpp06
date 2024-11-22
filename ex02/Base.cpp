/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:34:53 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/22 14:16:48 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base * Base::generate(void)
{
	int num = rand() % 3;
	
	switch (num)
	{
	case 0:
		return new A();
	
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		return nullptr;
	}
}

void Base::identify(Base* p)
{
	A *Aptr;
	B *Bptr;
	C *Cptr;

	Aptr = dynamic_cast<A*>(p);
	if (Aptr)
	{
		std::cout << "Object type: A" << std::endl;
		return ;
	}
	Bptr = dynamic_cast<B*>(p);
	if (Bptr)
	{
		std::cout << "Object type: B" << std::endl;
		return ;
	}
	Cptr = dynamic_cast<C*>(p);
	if (Cptr)
	{
		std::cout << "Object type: C" << std::endl;
		return ;
	}	
	std::cout << "Object type: Unknown" << std::endl;
}

void Base::identify(Base& p)
{
	A a;
	B b;
	C c;
try
{
	a = dynamic_cast<A&>(p);
	{
		std::cout << "Object type: A" << std::endl;
		return ;
	}
}
catch(const std::bad_cast& e)
{
}

try
{
	b = dynamic_cast<B&>(p);
	{
		std::cout << "Object type: B" << std::endl;
		return ;
	}
}

catch(const std::bad_cast& e)
{
}

try
{
	c = dynamic_cast<C&>(p);
	{
		std::cout << "Object type: C" << std::endl;
		return ;
	}
}

catch(const std::bad_cast& e)
{
}	
	std::cout << "Object type: Unknown" << std::endl;
}
