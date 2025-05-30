/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:12:39 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/13 15:26:28 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <algorithm>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <stdexcept>
#include <iomanip>
#include <iostream>

class Bitcoin_Exchange
{
	private:
		std::map<std::string, double> _priceData;
		std::map<std::string, double> _inputData;

		bool isValidDate(const std::string &date) const;
		double isValidValue(const std::string &value) const;
		double isValidExValue(const std::string &value) const;
		bool isLeapYear(int year) const;
		bool validateInput(const std::string &date, double exchangeRate) const;

	public:
		Bitcoin_Exchange();
		~Bitcoin_Exchange();
		Bitcoin_Exchange(const Bitcoin_Exchange &src);
		Bitcoin_Exchange &operator=(const Bitcoin_Exchange &src);

		// load the database
		void loadDatabase(const std::string &filename);
		// process text file
		void processInput(const std::string &filename);
		void printDataBase();
		void printInput();
		void calculateAndPrint() const;

		class BitcoinException : public std::exception
		{
			private:
				std::string _message;
			public:
				explicit BitcoinException(const std::string &msg) : _message(msg) {}
				virtual const char* what() const throw() { return _message.c_str(); }
				virtual ~BitcoinException() throw() {};
		};

};

std::string trim(const std::string &str);

#endif
