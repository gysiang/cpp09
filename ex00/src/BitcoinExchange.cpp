/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:13:43 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/10 16:46:22 by gyong-si         ###   ########.fr       */
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
		double price = isValidValue(priceStr);
		_priceData[date] = price;
	}
}

bool Bitcoin_Exchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Bitcoin_Exchange::isValidDate(const std::string &date) const
{
	// split the string into yyyy, mm and dd
	std::stringstream ss(date);
	std::string d1, d2, d3;

	if (!std::getline(ss, d1, '-') || !std::getline(ss, d2, '-') || !std::getline(ss, d3))
		return (false);

	int year = std::atoi(d1.c_str());
	int month = std::atoi(d2.c_str());
	int day = std::atoi(d3.c_str());

	if (year < 1980 || year > 2050)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2 && Bitcoin_Exchange::isLeapYear(year))
	{
		daysInMonth[1] = 29;
	}
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return (true);
}


double Bitcoin_Exchange::isValidValue(const std::string &value) const
{
	char *endPtr;
	double p;

	p = std::strtod(value.c_str(), &endPtr);
	if (*endPtr != '\0' || p < 0)
	{
		throw BitcoinException("Error: Invalid price value in database: " + value);
	}
	return (p);
}

std::string Bitcoin_Exchange::findPreviousDate(const std::string &date) const
{

}
