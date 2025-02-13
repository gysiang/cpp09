/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:54:02 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/13 13:54:18 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"


bool isValidNumber(const std::string &token)
{
	if (token.empty()) return false;  // Reject empty strings

	size_t i = 0;
	if (token[0] == '-' && token.size() > 1)  // Do Not allow negative numbers
		return (false);

	for (; i < token.size(); i++)
	{
		if (!isdigit(token[i]))
			return false;
	}
	return true;
}

int insertIntoVector(std::vector<unsigned int> &s, int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		std::string arg(av[i]);
		{
			if (isValidNumber(arg))
			{
				unsigned int num = strtoul(arg.c_str(), NULL, 10);
				s.push_back(num);
			}
			else
			{
				std::cerr << "Error: '" << arg << "'  is not a valid positive integer." << std::endl;
				return (1);
			}
		}
	}
	return (0);
}


void printVector(std::vector<unsigned int> s)
{
	std::vector<unsigned int>::const_iterator it = s.begin();
	std::vector<unsigned int>::const_iterator it_end = s.end();

	std::cout << "Printing out the contents of vector" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	while (it != it_end)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
