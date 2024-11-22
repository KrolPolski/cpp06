/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:55:10 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/22 13:00:51 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
class Data
{
	private:
		std::string _name;
		int			_id;
	public:
		Data();
		Data(std::string name, int id);
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();
};

