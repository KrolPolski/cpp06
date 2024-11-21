/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:39:40 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/21 13:49:07 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <limits>
#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	enum e_type {CHAR, INT, FLOAT, DOUBLE};
	static bool isChar(std::string str);
	static bool isInt(std::string str);
	static bool isFloat(std::string str);
	static bool isDouble(std::string str);
	// static void convChar(char c);
	// static void convInt(int num);
	// static void convFloat(float numf);
	// static void printDouble()
	
public:
	
	ScalarConverter(ScalarConverter& other) = delete;
	ScalarConverter& operator=(ScalarConverter& other) = delete;
	~ScalarConverter();
	static void convert(std::string str);
};

