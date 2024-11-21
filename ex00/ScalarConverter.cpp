/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:39:48 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/21 16:19:18 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

static bool isChar(std::string str)
{
	if ((isalpha(str[0]) && str.length() == 1)
		|| (isalpha(str[1]) && str.length() == 3 && str[0] == '\'' && str[2] == '\''))
		return true;
	else
		return false;
}

static bool isInt(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}
static bool isFloat(std::string str)
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

static bool isDouble(std::string str)
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

static void printFloat(float numf)
{
	std::cout << "float: " << numf << "f" << std::endl;
}

static void printDouble(double numd)
{
	std::cout << "double: " << std::fixed << numd << std::endl;
}
void ScalarConverter::convert(std::string str)
{
	enum e_type	type;
	char		c;
	int			num;
	long		numl;
	float		numf;
	double		numd;
	
	//special cases of -inff and +inff and nanf
	if (str == "-inff")
	{
		type = FLOAT;
		numf = -std::numeric_limits<float>::infinity();
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Float: " << numf << std::endl;
		numd = -std::numeric_limits<double>::infinity();
		std::cout << "Double: " << numd << std::endl;
		return ;
	}
	else if (str == "+inff")
	{
		type = FLOAT;
		numf = std::numeric_limits<float>::infinity();
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Float: " << numf << std::endl;
		numd = std::numeric_limits<double>::infinity();
		std::cout << "Double: " << numd << std::endl;
		return ;
	}
	// else if (str == "nanf")
	
	//special cases of -inf, +inf and nan

	else if (str == "-inf")
	{
		type = DOUBLE;
		numd = -std::numeric_limits<double>::infinity();
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		numf = -std::numeric_limits<float>::infinity();
		std::cout << "Float: " << numf << std::endl;
		std::cout << "Double: " << numd << std::endl;
		return ;
	}
	else if (str == "+inf")
	{
		type = DOUBLE;
		numd = std::numeric_limits<double>::infinity();
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		numf = std::numeric_limits<float>::infinity();
		std::cout << "Float: " << numf << std::endl;
		std::cout << "Double: " << numd << std::endl;
		return ;
	}
	// else if (str == "nan")
	
	//detect if str is a char
	else if (isChar(str))
	{
		type = CHAR;
		if (str.length() == 3)
			c = str[1];
		else
			c = str[0];
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
		std::cerr << "Error: Unable to determine type" << std::endl;
		return ;
	}
	try
	{
		switch (type)
		{
			case CHAR:
			{
				if (!std::isprint(c))
					std::cout << "char: non-displayable" << std::endl;
				else
					std::cout << "char: " << c << std::endl;
				num = static_cast<int>(c);
				numf = static_cast<float>(c);
				numd = static_cast<float>(c);
				std::cout << "int:" << num << std::endl;
				printFloat(numf);
				printDouble(numd);
				break;
			}
			
			case INT:
			{
				numl = std::stol(str);
				numf = static_cast<float>(numl);
				numd = static_cast<double>(numl);
				if (numl > std::numeric_limits<int>::max() || numl < std::numeric_limits<int>::min())
				{
					std::cout << "char: impossible" << std::endl;
					std::cout << "int: impossible" << std::endl;
					printFloat(numf);
					printDouble(numd);
					return ;
				}
				num = static_cast<int>(numl);
				if (num < -128 || num > 127)
					std::cout << "char: impossible" << std::endl;
				else if (!std::isprint(num))
					std::cout << "char: non-displayable" << std::endl;
				else
				{
					std::cout << "char: " << static_cast<char>(num) << std::endl;
				}
				std::cout << "int: " << num << std::endl;
				printFloat(numf);
				printDouble(numd);
				break;
			}
			
			case FLOAT:
			{
				numf = std::stof(str);
				numl = static_cast<long>(numf);
				if (numl > std::numeric_limits<int>::max() || numl < std::numeric_limits<int>::min())
				{
					std::cout << "char: impossible" << std::endl;
					std::cout << "int: impossible" << std::endl;
				}
				else if (numl < -128 || numl > 127)
					std::cout << "char: impossible" << std::endl;
				else if (!std::isprint(numl))
					std::cout << "char: non-displayable" << std::endl;
				else
				{
					std::cout << "char: " << static_cast<char>(numl) << std::endl;
				}
				num = static_cast<int>(numf);
				numd = static_cast<double>(numf);
				std::cout << "int: " << num << std::endl;
				printFloat(numf);
				printDouble(numd);
				break;
			}
			case DOUBLE:
			{
				numd = std::stod(str);
				numl = static_cast<long>(numd);
				if (numl > std::numeric_limits<int>::max() || numl < std::numeric_limits<int>::min())
				{
					std::cout << "char: impossible" << std::endl;
					std::cout << "int: impossible" << std::endl;
				}
				num = static_cast<int>(numd);
				numf = static_cast<float>(numd);
				if (num < -128 || num > 127)
					std::cout << "char: impossible" << std::endl;
				else if (!std::isprint(num))
					std::cout << "char: non-displayable" << std::endl;
				else
					std::cout << "char: " << static_cast<char>(num) << std::endl;
				std::cout << "int: " << num << std::endl;
				printFloat(numf);
				printDouble(numd);
				break;
			}
			default:
			{
				std::cerr << "Error: no valid type detected" << std::endl;
				break;
			}
		}
	}

	catch(const std::out_of_range& e)
	{
		std::cerr << "Error: Out of range for conversion" << std::endl;
	}
}
