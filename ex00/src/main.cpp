/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:13:33 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/11 16:04:08 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return (0);
	}
	else
	{
		std::string db = "data.csv";
		std::string input = av[1];

		Bitcoin_Exchange a;

		try
		{
			a.loadDatabase(db);
			//a.printDataBase();
			a.processInput(input);
			//a.printInput();
			// handle the input file by saving it in a map
			a.calculateAndPrint();
		}
		catch (const Bitcoin_Exchange::BitcoinException &e)
		{
			std::cerr << e.what() << std::endl;
			return (1);
		}
	}
}
