/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeVector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:38:57 by gyong-si          #+#    #+#             */
/*   Updated: 2025/03/06 15:14:49 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMeVector.hpp"

PmergeMeVector::PmergeMeVector() {};

PmergeMeVector::~PmergeMeVector() {};

PmergeMeVector::PmergeMeVector(const PmergeMeVector &src) : v(src.v) {};

PmergeMeVector &PmergeMeVector::operator=(const PmergeMeVector &src)
{
	if (this != &src)
	{
		v = src.v;
	}
	return *this;
}

size_t PmergeMeVector::size() const
{
	return v.size();
}

size_t PmergeMeVector::insertIntoContainer(int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		std::string arg(av[i]);
		{
			unsigned int num = strtoul(arg.c_str(), NULL, 10);
			v.push_back(num);
		}
	}
	return (0);
}

void PmergeMeVector::printContainer()
{
	typename std::vector<unsigned int>::const_iterator  it = v.begin();
	typename std::vector<unsigned int>::const_iterator it_end = v.end();
	int n = 0;

	while (it != it_end && n < 5)
	{
		std::cout << *it << " ";
		it++;
		n++;
	}
	if (v.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

/** *
void PmergeMeVector::insertionSort(int left, int right)
{
	for (int i = left+1; i <= right; i++)
	{
		unsigned int key = v[i];
		int j = i - 1;
		while (j >= left && v[j] > key)
		{
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = key;
	}
}

void PmergeMeVector::mergeVector(int left, int mid, int right)
{
	int left_size = mid - left + 1;
	int right_size = right - mid;

	std::vector<unsigned int> lvec(left_size);
	std::vector<unsigned int> rvec(right_size);

	// this will split the vector into l and r
	int i = 0;
	while (i < left_size)
	{
		lvec[i] = v[left+i];
		i++;
	}
	int j = 0;
	while (j < right_size)
	{
		rvec[j] = v[mid+1+j];
		j++;
	}

	j = 0;
	i = 0;
	int idx = left;
	while (i < left_size && j < right_size)
	{
		if (lvec[i] <= rvec[j])
		{
			v[idx] = lvec[i];
			i++;
		}
		else
		{
			v[idx] = rvec[j];
			j++;
		}
		idx++;
	}

	while (i < left_size)
	{
		v[idx] = lvec[i];
		i++;
		idx++;
	}
	while (j < right_size)
	{
		v[idx] = rvec[j];
		j++;
		idx++;
	}
}


void PmergeMeVector::mergeInsert(int left, int right)
{
	if (left < right)
	{
		if (right - left <= 10)
			insertionSort(left, right);
		else
		{
			int mid = left + (right - left) / 2;
			//std::cout << mid << std::endl;
			mergeInsert(left, mid);
			mergeInsert(mid+1, right);
			mergeVector(left, mid, right);
		}
	}
}
**/

size_t	binarySearchPos(std::vector<unsigned int> &mainSq, unsigned int num)
{
	size_t	left;
	size_t	right;
	size_t	mid;

	left = 0;
	right = mainSq.size();
	mid = 0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (mainSq[mid] < num)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return (left);
}

void	PmergeMeVector::fordJohnsonSort(std::vector<unsigned int> &v)
{
	std::vector<unsigned int>	mainSq;
	std::vector<unsigned int>	pendSq;
	bool						hasOdd;

	if (v.size() <= 1)
		return ;

	hasOdd = (v.size() % 2 != 0); // returns true if odd
	// Pair and sort each pair
	for (size_t i = 0; i + 1 < v.size(); i+=2)
	{
		if (v[i] < v[i + 1])
		{
			mainSq.push_back(v[i]);
			pendSq.push_back(v[i+1]);
		}
		else
		{
			mainSq.push_back(v[i+1]);
			pendSq.push_back(v[i]);
		}
	}
	// deal with the odd element if any
	if (hasOdd)
	{
		pendSq.push_back(v.back());
	}
	// recursively sort mainSq
	fordJohnsonSort(mainSq);
	// use binarysort
	for (size_t i = 0; i < pendSq.size(); i++)
	{
		unsigned int num = pendSq[i];
		size_t pos = binarySearchPos(mainSq , num);
		mainSq.insert(mainSq.begin() + pos, num);
	}
	v = mainSq;
}


double PmergeMeVector::getVectorDuration()
{
	clock_t start = clock();
	//mergeInsert(0, v.size()-1);
	fordJohnsonSort(v);
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	return (elapsed);
}
