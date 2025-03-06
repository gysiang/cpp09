/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:25:02 by gyong-si          #+#    #+#             */
/*   Updated: 2025/03/06 15:08:56 by gyong-si         ###   ########.fr       */
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

	public:
		PmergeMeVector();
		~PmergeMeVector();
		PmergeMeVector(const PmergeMeVector &src);
		PmergeMeVector &operator=(const PmergeMeVector &src);
		size_t size() const;

		size_t	insertIntoContainer(int ac, char **av);
		void	printContainer();

		/***
		void	insertionSort(int start, int end);
		void 	mergeInsert(int start, int end);
		void	mergeVector(int start, int mid, int end);
		**/

		void	fordJohnsonSort(std::vector<unsigned int> &v);
		double	getVectorDuration();
};

#endif
