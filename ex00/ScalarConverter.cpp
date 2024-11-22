/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:39:48 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/22 10:50:54 by rboudwin         ###   ########.fr       */
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

void ScalarConverter::printFloat(float numf, std::string str)
{
	unsigned int precision {1};
	unsigned int len;

	len = str.length();
	if (str[len - 1] == 'f')
		len--;
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] == '.')
		{	
			precision = len - i - 1;
		}
	}
	
	std::cout << "float: " << std::fixed << std::setprecision(precision) << numf << "f" << std::endl;
}

void ScalarConverter::printDouble(double numd, std::string str)
{
	unsigned int precision {1};
	unsigned int len;

	len = str.length();
	if (str[len - 1] == 'f')
		len--;
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] == '.')
		{	
			precision = len - i - 1;
		}
	}
	std::cout << "double: " << std::fixed << numd << std::endl;
}

void ScalarConverter::printChar(int num)
{
	if (num < -128 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(num))
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;	
}

void ScalarConverter::convert(std::string str)
{
	enum e_type	type;
	char		c;
	int			num;
	long		numl;
	float		numf;
	double		numd;
	
	if (str == "-inff")
	{
		type = FLOAT;
		numf = -std::numeric_limits<float>::infinity();
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << numf << std::endl;
		numd = -std::numeric_limits<double>::infinity();
		std::cout << "double: " << numd << std::endl;
		return ;
	}
	else if (str == "+inff")
	{
		type = FLOAT;
		numf = std::numeric_limits<float>::infinity();
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << numf << std::endl;
		numd = std::numeric_limits<double>::infinity();
		std::cout << "double: " << numd << std::endl;
		return ;
	}
	else if (str == "nanf" || str == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		numf = std::numeric_limits<float>::has_quiet_NaN;
		numd = std::numeric_limits<double>::has_quiet_NaN;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}

	else if (str == "-inf")
	{
		type = DOUBLE;
		numd = -std::numeric_limits<double>::infinity();
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		numf = -std::numeric_limits<float>::infinity();
		std::cout << "float: " << numf << std::endl;
		std::cout << "double: " << numd << std::endl;
		return ;
	}
	else if (str == "+inf")
	{
		type = DOUBLE;
		numd = std::numeric_limits<double>::infinity();
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		numf = std::numeric_limits<float>::infinity();
		std::cout << "float: " << numf << std::endl;
		std::cout << "double: " << numd << std::endl;
		return ;
	}
	
	else if (isChar(str))
	{
		type = CHAR;
		if (str.length() == 3)
			c = str[1];
		else
			c = str[0];
	}
	else if (isInt(str))
	{
		type = INT;
	}
	else if (isFloat(str))
	{
		type = FLOAT;
	}
	else if (isDouble(str))
	{
		type = DOUBLE;
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
				numd = static_cast<double>(c);
				std::cout << "int:" << num << std::endl;
				printFloat(numf, str);
				printDouble(numd, str);
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
					printFloat(numf, str);
					printDouble(numd, str);
					return ;
				}
				num = static_cast<int>(numl);
				printChar(num);
				std::cout << "int: " << num << std::endl;
				printFloat(numf, str);
				printDouble(numd, str);
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
				num = static_cast<int>(numf);
				printChar(num);
				numd = static_cast<double>(numf);
				std::cout << "int: " << num << std::endl;
				printFloat(numf, str);
				printDouble(numd, str);
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
				printChar(num);
				std::cout << "int: " << num << std::endl;
				printFloat(numf, str);
				printDouble(numd, str);
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
