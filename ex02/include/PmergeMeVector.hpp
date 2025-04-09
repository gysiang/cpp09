/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:25:02 by gyong-si          #+#    #+#             */
/*   Updated: 2025/04/09 13:49:51 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEVECTOR_HPP
#define PMERGEMEVECTOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <climits>
#include <iomanip>
#include <set>

#include "../include/utils.hpp"

class PmergeMeVector
{
	private:
		std::vector<unsigned int> v;
		std::vector<std::pair<unsigned int, unsigned int> > p;

	public:
		PmergeMeVector();
		~PmergeMeVector();
		PmergeMeVector(const PmergeMeVector &src);
		PmergeMeVector &operator=(const PmergeMeVector &src);
		size_t size() const;

		size_t	insertIntoContainer(int ac, char **av);
		void	printContainer();
		void	getSortedPairs();
		void	fordJohnsonSort(std::vector<unsigned int> &v);
		double	getVectorDuration();
		void	printPairs() const;

		void	mergeSortPairs(int left, int right);
		void	mergeVectorPairs(int left, int mid, int right);
		void	insertWithJacobsthal(std::vector<unsigned int> &mainSq, std::vector<unsigned int> &pendSq);

};

#endif
