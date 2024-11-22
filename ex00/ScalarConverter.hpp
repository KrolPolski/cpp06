/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:39:40 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/22 10:21:50 by rboudwin         ###   ########.fr       */
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
	enum e_type {CHAR, INT, FLOAT, DOUBLE};
	
public:
	ScalarConverter(ScalarConverter& other) = delete;
	ScalarConverter& operator=(ScalarConverter& other) = delete;
	~ScalarConverter();
	static void convert(std::string str);
};

