/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:39:40 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/22 10:49:32 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <limits>
#include <iostream>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter& other) = delete;
		ScalarConverter& operator=(ScalarConverter& other) = delete;
		~ScalarConverter();
		enum e_type {CHAR, INT, FLOAT, DOUBLE};
		static bool isChar(std::string str);
		static bool isDouble(std::string str);
		static bool isFloat(std::string str);
		static bool isInt(std::string str);
		static void printChar(int num);
		static void printDouble(double numd, std::string str);
		static void printFloat(float numf, std::string str);
		
	public:
		static void convert(std::string str);
};

