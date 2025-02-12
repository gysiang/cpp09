/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:13:02 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/12 17:38:41 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

// used when operator is found
// pop the two numbers before the operation to calculate result
// push the result back into the stack
std::stack<int> calculateExpression(const std::string &token, std::stack<int> &stack)
{
	if (stack.size() < 2)
	{
		std::cerr << "Error: Not enough operands for operation " << token << std::endl;
		return (stack);
	}
	int num1 = stack.top();
	stack.pop();
	int num2 = stack.top();
	stack.pop();
	int result = 0;

	if (token == "+")
		result = num1 + num2;
	else if (token == "-")
		result = num1 + num2;
	else if (token == "*")
		result = num1 * num2;
	else if (token == "/")
	{
		if (num2 == 0)
		{
			std::cerr << "Error: Division by zero" << std::endl;
			return (stack);
		}
		result = num1 / num2;
	}
	stack.push(result);
	return (stack);
}

bool isValidNumber(const std::string& token)
{
	if (token.empty()) return false;

	size_t i = 0;
	if (token[i] == '-') i++;

	for (; i < token.size(); i++)
	{
		if (!isdigit(token[i]))
			return false;
	}
	return true;
}

int stringToInt(const std::string& str)
{
	std::stringstream ss(str);
	int num;
	ss >> num;

	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("Invalid number");
	return num;
}


void processInput(const std::string &input)
{
	std::stringstream ss(input);
	std::string token;
	std::stack<int> stack;

	while (ss >> token)
	{
		if (isValidNumber(token))
			stack.push(stringToInt(token));
		else if (token == "+" || token == "-" || token == "*" || token == "/")
			stack = calculateExpression(token, stack);
		else
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
	}
	// For debugging, print the stack content
	std::cout << "Result after processing: ";
	while (!stack.empty())
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;
}
