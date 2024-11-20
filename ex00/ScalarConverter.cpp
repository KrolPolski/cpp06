/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:39:48 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/20 15:36:21 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string str)
{
	enum e_type type;
	size_t *pos;
	//special cases of -inff and +inff and nanf
	if (str == "-inff")
	{
		type = FLOAT;
		float numf = -std::numeric_limits<float>::infinity();
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Float: " << numf << std::endl;
		double numd = -std::numeric_limits<double>::infinity();
		std::cout << "Double: " << numd << std::endl;
		return ;
	}
	else if (str == "+inff")
	{
		type = FLOAT;
		float numf = std::numeric_limits<float>::infinity();
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Float: " << numf << std::endl;
		double numd = std::numeric_limits<double>::infinity();
		std::cout << "Double: " << numd << std::endl;
		return ;
	}
	// else if (str == "nanf")
	
	//special cases of -inf, +inf and nan

	if (str == "-inf")
	{
		type = DOUBLE;
		double numd = -std::numeric_limits<double>::infinity();
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		float numf = -std::numeric_limits<float>::infinity();
		std::cout << "Float: " << numf << std::endl;
		std::cout << "Double: " << numd << std::endl;
		return ;
	}
	else if (str == "+inf")
	{
		type = DOUBLE;
		double numd = std::numeric_limits<double>::infinity();
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		float numf = std::numeric_limits<float>::infinity();
		std::cout << "Float: " << numf << std::endl;
		std::cout << "Double: " << numd << std::endl;
		return ;
	}
	// else if (str == "nan")
	
	//detect if str is a char
	if ((isalpha(str[0]) && str.length() == 1)
		|| (isalpha(str[1]) && str.length() == 3 && str[0] == '\'' && str[2] == '\''))
		type = CHAR;
	//detect if str is an int
	try
	{
		int scInt = std::stoi(str, nullptr, 10);
		type = INT;
	}
	catch (std::exception &invalid_argument)
	{
		
	}
	catch (std::exception &out_of_range)
	{
		
	}
	//detect if str is a float
	try
	{
		float scFloat = std::stof(str, pos);
	}
	catch (std::exception &invalid_argument)
	{
		
	}
	catch (std::exception &out_of_range)
	{
		
	}
	//detect if str is a double
	try
	{
		double scDouble = std::stod(str, pos);
	}
	catch (std::exception &invalid_argument)
	{
		
	}
	catch (std::exception &out_of_range)
	{
		
	}
}