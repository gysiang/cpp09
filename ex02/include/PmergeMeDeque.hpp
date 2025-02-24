/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:37:22 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/23 10:56:33 by gyong-si         ###   ########.fr       */
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

	public:
		PmergeMeDeque();
		~PmergeMeDeque();
		PmergeMeDeque(const PmergeMeDeque &src);
		PmergeMeDeque &operator=(const PmergeMeDeque &src);
		size_t size() const;

		size_t	insertIntoContainer(int ac, char **av);
		void	printContainer();

		void	insertionSort(int left, int right);
		void	mergeDeque(int left, int mid, int right);
		void	mergeInsert(int left, int right);
		double	getDequeDuration();
};





#endif
