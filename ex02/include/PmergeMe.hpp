/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:20:08 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/17 14:23:57 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <cstdlib>
#include <algorithm>

template <typename Container>
class PmergeMe
{
	private:
		Container v;

	public:
		PmergeMe() {};
		~PmergeMe() {};
		PmergeMe(const PmergeMe &src) : v(src.v) {};
		PmergeMe &operator=(const PmergeMe &src)
		{
			if (this != &src)
			{
				v = src.v;
			}
			return *this;
		}
		size_t	insertIntoContainer(int ac, char **av);
		bool	isValidNumber(const std::string &token);
		void	printContainer(const Container &a);
		void	splitIntoSeq(Container &a, Container &b);
		size_t	binarySeachInsertPos(Container &s, unsigned int num);
		void 	mergeInsert(int ac, char **av);
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
	for (int i = 1; i < ac; ++i)
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
void PmergeMe<Container>::printContainer(const Container &a)
{
	typename Container::const_iterator it = a.begin();
	typename Container::const_iterator it_end = a.end();

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
void PmergeMe<Container>::splitIntoSeq(Container &mainSeq, Container &pendSeq)
{
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
}

template <typename Container>
size_t PmergeMe<Container>::binarySeachInsertPos(Container &s, unsigned int num)
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

template <typename Container>
void PmergeMe<Container>::mergeInsert(int ac, char **av)
{
	Container pendingSequence;
	Container mainSequence;

	insertIntoContainer(ac, av);
	splitIntoSeq(mainSequence, pendingSequence);

	std::sort(mainSequence.begin(), mainSequence.end());

	for (size_t i = 0; i < pendingSequence.size(); i++)
	{
		unsigned int num = pendingSequence[i];
		// find the pos of the num in the main sequence
		size_t pos = binarySeachInsertPos(mainSequence, num);
		// insert the number into the main sequence
		mainSequence.insert(mainSequence.begin() + pos, num);
	}
	// print result
	printContainer(mainSequence);
}


#endif
