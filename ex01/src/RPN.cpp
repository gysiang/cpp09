/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:13:02 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/12 11:25:56 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

void processInput(const std::string &input)
{
	std::stringstream ss(input);
	std::string token;
	std::stack<int> stack;

	while (ss >> token)
	{
		if (isdigit(token[0]))
			stack.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
			std::cout << "Operator found: " << token << std::endl;
		else
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
	}
	// For debugging, print the stack content
	std::cout << "Stack content after processing: ";
	while (!stack.empty())
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;
}
