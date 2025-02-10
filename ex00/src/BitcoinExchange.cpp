/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:13:43 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/10 15:02:20 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"


Bitcoin_Exchange::Bitcoin_Exchange() {};

Bitcoin_Exchange::~Bitcoin_Exchange() {};

void Bitcoin_Exchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		throw BitcoinException("Error: Could not open datafile file.");
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, priceStr;

		// read the date and price
		if (!std::getline(ss, date, ',') || !std::getline(ss, priceStr))
		{
			throw BitcoinException("Error: Invalid line format in database.");
		}
		// check if the date is valid
		if (!isValidDate(date))
		{
			throw BitcoinException("Error: Invalid date format in database: " + date);
		}
		// convert the type of the price to a double to save to our struct
		char *endPtr;
		double price;

		price = std::strtod(priceStr.c_str(), &endPtr);
		if (*endPtr != '\0' || price < 0)
		{
			throw BitcoinException("Error: Invalid price value in database: " + priceStr);
		}
		_priceData[date] = price;
	}
}
