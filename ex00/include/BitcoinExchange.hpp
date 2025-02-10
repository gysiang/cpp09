/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:12:39 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/10 14:45:35 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

class Bitcoin_Exchange
{
	private:
		std::map<std::string, double> _priceData;

		bool isValidDate(const std::string &date) const;
		bool isValidValue(const std::string &value) const;
		std::string findPreviousDate(const std::string &date) const;

	public:
		Bitcoin_Exchange();
		~Bitcoin_Exchange();

		// load the database
		void loadDatabase(const std::string &filename);
		// process text file
		void processInput(const std::string &filename);
		// get the closest earlier date price
		double getClosestPrice(const std::string &date) const;

		class BitcoinException : public std::exception
		{
			private:
				std::string _message;
			public:
				explicit BitcoinException(const std::string &msg) : _message(msg) {}
				virtual const char* what() const throw() { return _message.c_str(); }
		};

};

#endif
