/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:39:40 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/20 15:29:23 by rboudwin         ###   ########.fr       */
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
public:
	enum e_type {CHAR, INT, FLOAT, DOUBLE};
	ScalarConverter(ScalarConverter& other) = delete;
	ScalarConverter& operator=(ScalarConverter& other) = delete;
	~ScalarConverter();
	static void convert(std::string str);
};
