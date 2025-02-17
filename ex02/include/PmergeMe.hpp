/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:20:08 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/17 11:05:35 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <cstdlib>

template <typename Container>
class PmergeMe
{
	private:
		Container v;
		Container mainSeq;
		Container pendSeq;

	public:
		PmergeMe() {};
		~PmergeMe() {};
		PmergeMe(const PmergeMe &src) : v(src.v), mainSeq(src.mainSeq), pendSeq(src.pendSeq) {}
		PmergeMe &operator=(const PmergeMe &src)
		{
			if (this != &src)
			{
				v = src.v;
				mainSeq = src.mainSeq;
				pendSeq = src.pendSeq;
			}
			return *this;
		}
		size_t	insertIntoContainer(int ac, char **av);
		bool	isValidNumber(const std::string &token);
		void	printContainer();
		void	splitIntoSeq();
		size_t	binarySeachInsertPos(const Container &s, unsigned int num);
		void 	binaryInsert();
	};

template <typename Container>
bool PmergeMe<Container>::isValidNumber(const std::string &token)
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

template <typename Container>
size_t PmergeMe<Container>::insertIntoContainer(int ac, char **av)
{
	for (size_t i = 1; i < ac; ++i)
	{
		std::string arg(av[i]);
		{
			if (isValidNumber(arg))
			{
				unsigned int num = strtoul(arg.c_str(), NULL, 10);
				v.push_back(num);
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

template <typename Container>
void PmergeMe<Container>::printContainer()
{
	typename Container::const_iterator it = v.begin();
	typename Container::const_iterator it_end = v.end();

	std::cout << "Printing out the contents" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	while (it != it_end)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template <typename Container>
void PmergeMe<Container>::splitIntoSeq()
{
	mainSeq.clear();
	pendSeq.clear();

	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		unsigned int first = v[i];
		unsigned int second = v[i+1];

		if (first > second)
			std::swap(first, second);

		mainSeq.push_back(first);
		pendSeq.push_back(second);
	}
	if (v.size() % 2 != 0)
	{
		unsigned int last = v.back();
		pendSeq.push_back(last);
	}
	std::cout << "Main Sequence: ";
	for (size_t i = 0; i < mainSeq.size(); i++)
		std::cout << mainSeq[i] << " ";
	std::cout << std::endl;

	std::cout << "Pending Sequence: ";
	for (size_t i = 0; i < pendSeq.size(); i++)
		std::cout << pendSeq[i] << " ";
	std::cout << std::endl;
}

template <typename Container>
size_t PmergeMe<Container>::binarySeachInsertPos(const Container &s, unsigned int num)
{
	size_t left;
	size_t right;

	left = 0;
	right = s.size();

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (s[mid] < num)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}





#endif
