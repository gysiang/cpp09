/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:13:02 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/14 13:57:20 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN() {};

RPN::~RPN() {};

RPN::RPN(const RPN &src)
{
	this->v = src.v;
}

RPN &RPN::operator=(const RPN &src)
{
	this->v = src.v;
	return (*this);
}

// used when operator is found
// pop the two numbers before the operation to calculate result
// push the result back into the stack
std::stack<int> RPN::calculateExpression(const std::string &token, std::stack<int> &stack)
{
	if (stack.size() < 2)
	{
		std::cerr << "Error: Not enough operands for operation " << token << std::endl;
		return (stack);
	}
	int num2 = stack.top();
	stack.pop();
	int num1 = stack.top();
	stack.pop();
	int result = 0;

	if (token == "+")
		result = num1 + num2;
	else if (token == "-")
		result = num1 - num2;
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

bool isValidNumber(const std::string &token)
{
	if (token.empty()) return false;

	size_t i = 0;
	if (token[0] == '-' && token[1])
		i = 1;

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

void RPN::processInput(const std::string &input)
{
	std::stringstream ss(input);
	std::string token;
	std::stack<int> stack = this->v;

	while (ss >> token)
	{
		//std::cout << "Processing token: " << token << std::endl;
		try
		{
			if (isValidNumber(token))
			{
				stack.push(stringToInt(token));
			}
			else if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				if (stack.size() < 2)
				{
					std::cerr << "Error: Not enough operands for operator '" << token << "'" << std::endl;
					return;
				}
				stack = calculateExpression(token, stack);
			}
			else
			{
				std::cerr << "Error" << std::endl;
				return;
			}
		}
		catch (const std::invalid_argument &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return;
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << "Error: Number out of range" << std::endl;
			return;
		}
	}
	if (stack.size() == 1)
		std::cout << "Result: " << stack.top() << std::endl;
	else
		std::cerr << "Error: Stack has more than one result" << std::endl;
}
