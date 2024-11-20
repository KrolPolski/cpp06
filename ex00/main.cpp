/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:43:47 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/20 14:50:54 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	std::string str;

	if (argc != 2)
	{
		std::cout << "Invalid number of arguments. Try: ./convert <str>" << std::endl;
		return (EXIT_FAILURE);
	}
	str = argv[1];
	ScalarConverter::convert(str);
}