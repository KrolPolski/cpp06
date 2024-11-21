/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:39:48 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/21 14:10:09 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::isChar(std::string str)
{
	if ((isalpha(str[0]) && str.length() == 1)
		|| (isalpha(str[1]) && str.length() == 3 && str[0] == '\'' && str[2] == '\''))
		return true;
	else
		return false;
}

bool ScalarConverter::isInt(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}
bool ScalarConverter::isFloat(std::string str)
{
	bool decimalFound {false};
	for (size_t i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == '.' && !decimalFound)
		{
			decimalFound = true;
			continue;
		}
		if (str[i] == '.' && decimalFound)
			return false;
		if (!isdigit(str[i]))
			return false;
	}
	if (str[str.length() - 1] == 'f')
		return true;
	else
		return false;
}

bool ScalarConverter::isDouble(std::string str)
{
	bool decimalFound {false};
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.' && !decimalFound)
		{
			decimalFound = true;
			continue;
		}
		if (str[i] == '.' && decimalFound)
			return false;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void ScalarConverter::convert(std::string str)
{
	enum e_type type;
	size_t *pos = nullptr;
	
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

	else if (str == "-inf")
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
	else if (isChar(str))
	{
		type = CHAR;
		std::cout << "this is a char" << std::endl;
	}
	//detect if str is an int
	else if (isInt(str))
	{
		type = INT;
		std::cout << "This is an int" << std::endl;
	}
	else if (isFloat(str))
	{
		type = FLOAT;
		std::cout << "This is a float" << std::endl;
	}
	else if (isDouble(str))
	{
		type = DOUBLE;
		std::cout << "This is a double" << std::endl;
	}
	else
	{
		std::cout << "Unable to determine type" << std::endl;
	}
// 	try
// 	{
// 		int scInt = std::stoi(str, nullptr, 10);
// 		type = INT;
// 	}
// 	catch (std::exception &invalid_argument)
// 	{
		
// 	}
// 	catch (std::exception &out_of_range)
// 	{
		
// 	}
// 	//detect if str is a float
// 	try
// 	{
// 		float scFloat = std::stof(str, pos);
// 	}
// 	catch (std::exception &invalid_argument)
// 	{
		
// 	}
// 	catch (std::exception &out_of_range)
// 	{
		
// 	}
// 	//detect if str is a double
// 	try
// 	{
// 		double scDouble = std::stod(str, pos);
// 	}
// 	catch (std::exception &invalid_argument)
// 	{
		
// 	}
// 	catch (std::exception &out_of_range)
// 	{
		
// 	}
}