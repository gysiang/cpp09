/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:15:46 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/14 13:53:30 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int main(int ac, char **av)
{
	RPN a;

	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " \"<RPN expression>\"" << std::endl;
		return (1);
	}
	a.processInput(av[1]);
	return (0);
}
