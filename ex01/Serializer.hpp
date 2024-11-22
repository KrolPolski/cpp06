/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:54 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/22 13:09:07 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Data.hpp"
#include <cstdint>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other) = delete;
		Serializer& operator=(const Serializer& other) = delete;
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


