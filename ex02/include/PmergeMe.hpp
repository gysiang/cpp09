/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:20:08 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/14 15:24:50 by gyong-si         ###   ########.fr       */
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
		std::vector<unsigned int> v;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		int insertIntoVec(int ac, char **av);
		bool isValidNumber(const std::string &token);
		void printVec();
};


#endif
