/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:59:53 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/22 13:03:16 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	_name = "TheManWithNoName";
	_id = 0;
}

Data::Data(std::string name, int id)
{
	_name = name;
	_id = id;
}

Data::Data(const Data& other)
{
	_name = other._name;
	_id = other._id;
}

Data& Data::operator=(const Data& other)
{
	_name = other._name;
	_id = other._id;
	return (*this);
}

Data::~Data()
{
	
}