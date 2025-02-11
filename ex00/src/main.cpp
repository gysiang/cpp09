/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:13:33 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/11 09:27:57 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main()
{

	std::string file = "data.csv";
	Bitcoin_Exchange a;

	try
	{
		a.loadDatabase(file);
		a.printDataBase();
	}
	catch (const Bitcoin_Exchange::BitcoinException &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
