/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:37:22 by gyong-si          #+#    #+#             */
/*   Updated: 2025/05/21 10:50:09 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEDEQUE_HPP
#define PMERGEMEDEQUE_HPP

#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <climits>
#include <iomanip>
#include <set>

#include "../include/utils.hpp"

class PmergeMeDeque
{
	private:
		std::deque<unsigned int> v;
		std::deque<std::pair<unsigned int, unsigned int> > p;

	public:
		PmergeMeDeque();
		~PmergeMeDeque();
		PmergeMeDeque(const PmergeMeDeque &src);
		PmergeMeDeque &operator=(const PmergeMeDeque &src);
		size_t size() const;

		size_t	insertIntoContainer(int ac, char **av);
		void	printContainer();
		void	printPairs() const;

		void	fordJohnsonSort(std::deque<unsigned int> &v);
		double	getDequeDuration();
		void	getSortedPairs();
		void	mergeVectorPairs(int left, int mid, int right);
		void 	mergeSortPairs(int left, int right);
		std::deque<size_t> getJacobsthalIndices(std::deque<unsigned int> &pendSq);
		void	jacobsthalInsert(std::deque<unsigned int> &mainSq, std::deque<unsigned int> &pendSq);

};





#endif
