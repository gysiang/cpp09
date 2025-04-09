/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:57:21 by gyong-si          #+#    #+#             */
/*   Updated: 2025/04/08 14:08:17 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.hpp"

bool isValidNumber(const std::string &token)
{
	if (token.empty())
		return (false);

	size_t i = 0;
	if (token[0] == '-' && token.size() > 1)
		return (false);

	for (; i < token.size(); i++)
	{
		if (!isdigit(token[i]))
			return (false);
	}
	unsigned int num = strtoul(token.c_str(), NULL, 10);
	if (num > UINT_MAX)
		return (false);
	return (true);
}

int runChecks(int ac, char **av)
{
	std::set<unsigned int> uniqueNumbers;

	for (int i = 1; i < ac; ++i)
	{
		std::string arg(av[i]);
		// check if arg is a valid number and lesser than MAXINT
		if (!isValidNumber(arg))
		{
			std::cerr << "Error: '" << arg << "'  is not a valid positive integer." << std::endl;
			exit(EXIT_FAILURE);
		}
		unsigned int num = strtoul(arg.c_str(), NULL, 10);
		if (uniqueNumbers.find(num) != uniqueNumbers.end())
		{
			std::cerr << "Error: Duplicate number detected : " << num << std::endl;
			exit(EXIT_FAILURE);
		}
		uniqueNumbers.insert(num);
	}
	return (0);
}

// Returns the k-th Jacobsthal number (J_k)
size_t Jacobsthal(size_t k)
{
	if (k == 0)
		return (0);
	if (k == 1)
		return (1);
	if (k > 20)
		return (0);
	return (Jacobsthal(k - 1) + 2 * Jacobsthal(k - 2));
}
