/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:20:08 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/14 14:02:59 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <cstdlib>

class PmergeMe
{
	private:
		std::vector<int> v;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		int insertIntoVec(std::vector<unsigned int> &s, int ac, char **av);
		bool isValidNumber(const std::string &token);
		void printVector(std::vector<unsigned int> s);
};


#endif
