/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:06:57 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/22 13:10:59 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
int main(void)
{
	Data *Tim = new Data("Tim", 1);
	Data *ptr {nullptr};
	uintptr_t num;
	std::cout << "Pointer value: " << Tim << std::endl;
	num = Serializer::serialize(Tim);
	std::cout << "uintptr_t value: " << num << std::endl;
	ptr = Serializer::deserialize(num);
	std::cout << "Deserialized pointer value: " << ptr << std::endl;
	delete Tim;
}