/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeVector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:38:57 by gyong-si          #+#    #+#             */
/*   Updated: 2025/05/20 22:39:41 by gyong-si         ###   ########.fr       */
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
	std::vector<unsigned int>::const_iterator  it = v.begin();
	std::vector<unsigned int>::const_iterator it_end = v.end();
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

void PmergeMeVector::mergeVectorPairs(int left, int mid, int right)
{
	int left_size = mid - left + 1;
	int right_size = right - mid;

	std::vector<std::pair<unsigned int, unsigned int> > lvec(left_size);
	std::vector<std::pair<unsigned int, unsigned int> > rvec(right_size);

	// this will split the vector into l and r
	int i = 0;
	while (i < left_size)
	{
		lvec[i] = p[left+i];
		i++;
	}
	int j = 0;
	while (j < right_size)
	{
		rvec[j] = p[mid+1+j];
		j++;
	}

	j = 0;
	i = 0;
	int idx = left;
	while (i < left_size && j < right_size)
	{
		if (lvec[i] <= rvec[j])
		{
			p[idx] = lvec[i];
			i++;
		}
		else
		{
			p[idx] = rvec[j];
			j++;
		}
		idx++;
	}

	while (i < left_size)
	{
		p[idx] = lvec[i];
		i++;
		idx++;
	}
	while (j < right_size)
	{
		p[idx] = rvec[j];
		j++;
		idx++;
	}
}


void PmergeMeVector::mergeSortPairs(int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSortPairs(left, mid);
		mergeSortPairs(mid+1, right);
		//mergeVectorPairs(left, mid, right);
		std::inplace_merge(p.begin() + left, p.begin() + mid + 1, p.begin() + right + 1);
	}
}


size_t	binarySearchPosRange(std::vector<unsigned int> &mainSq, unsigned int num, size_t left, size_t right)
{
	size_t	mid;

	if (mainSq.empty())
		return (0);
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (mainSq[mid] < num)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

size_t	binarySearchPos(std::vector<unsigned int> &mainSq, unsigned int num)
{
	size_t	mid;
	size_t	left = 0;
	size_t	right = mainSq.size();

	if (mainSq.empty())
		return (0);
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (mainSq[mid] < num)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

void	PmergeMeVector::getSortedPairs()
{
	std::vector<unsigned int>::iterator it = v.begin();

	while (it != v.end())
	{
		unsigned int first = *it;
		it++;
		if (it != v.end())
		{
			unsigned int second = *it;
			it++;
			if (first > second)
			{
				std::swap(first, second);
			}
			p.push_back(std::make_pair(first, second));
		}
	}
}

void PmergeMeVector::printPairs() const
{
    for (size_t i = 0; i < p.size(); i++)
    {
        std::cout << "(" << p[i].first << ", " << p[i].second << ") ";
    }
    std::cout << std::endl;
}

void PmergeMeVector::insertWithJacobsthal(std::vector<unsigned int> &mainSq, std::vector<unsigned int> &pendSq)
{
	size_t k = 2;
	size_t lastInsertPos = 0;
	while (pendSq.size() != 0)
	{
		size_t batchSize = Jacobsthal(k) - Jacobsthal(k-1);
		batchSize = std::min(batchSize, pendSq.size());
		//std::cout << "batchSize: " << batchSize << std::endl;

		size_t pivotPos = pendSq.size() / 2;
		size_t startPos = (pivotPos >= batchSize / 2) ? pivotPos - batchSize / 2 : 0;
		startPos = std::min(startPos, pendSq.size() - batchSize);

		for (size_t i = 0; i < batchSize; ++i)
		{
			if (pendSq.empty())
				break;

			size_t left = 0;
			size_t right = mainSq.size();
			unsigned int num = pendSq[startPos + i];

			if (lastInsertPos > 0 && num > mainSq[lastInsertPos - 1])
				left = lastInsertPos;
			else if (!mainSq.empty() && num < mainSq[0])
				right = 1;

			size_t pos = binarySearchPosRange(mainSq, num, left, right);
			//std::cout << "Inserting " << num << " at position " << pos << std::endl;
			mainSq.insert(mainSq.begin() + pos, num);
		}
		pendSq.erase(pendSq.begin() + startPos, pendSq.begin() + startPos + batchSize);
		k++;
	}
}

std::vector<size_t> PmergeMeVector::getJacobsthalIndices(std::vector<unsigned int> &pendSq)
{
	std::vector<size_t> jacobsthal_indices;
	std::set<size_t>	all_indices;
	int					k = 1;

	while (Jacobsthal(++k) < pendSq.size())
	{
		jacobsthal_indices.push_back(Jacobsthal(k));
	}
	for (size_t i = 0; i < pendSq.size(); ++i)
		all_indices.insert(i);
	for (size_t i = 0; i < jacobsthal_indices.size(); ++i)
	{
		all_indices.erase(jacobsthal_indices[i]);
	}
	jacobsthal_indices.insert(jacobsthal_indices.end(), all_indices.begin(), all_indices.end());
	/** *
	std::cout << "Printing Jacobsthal Number" << std::endl;
	for (size_t i = 0; i < jacobsthal_indices.size(); ++i)
		std::cout << jacobsthal_indices[i] << " ";
	std::cout << std::endl;
	**/
	return (jacobsthal_indices);
}


void PmergeMeVector::jacobsthalInsert(std::vector<unsigned int> &mainSq, std::vector<unsigned int> &pendSq)
{
	std::vector<size_t> jacobsthal_indices = getJacobsthalIndices(pendSq);

	for (size_t i = 0; i < jacobsthal_indices.size(); ++i)
	{
		unsigned int idx = jacobsthal_indices[i];
		size_t pos = binarySearchPos(mainSq, pendSq[idx]);
		mainSq.insert(mainSq.begin() + pos, pendSq[idx]);
	}
}


void	PmergeMeVector::fordJohnsonSort(std::vector<unsigned int> &v)
{
	std::vector<unsigned int>	mainSq;
	std::vector<unsigned int>	pendSq;
	bool						hasOdd;
	unsigned int				oddEle;

	if (v.size() <= 1)
		return ;
	hasOdd = (v.size() % 2 != 0);
	oddEle = hasOdd ? v.back() : 0;
	if (hasOdd)
		v.pop_back();

	getSortedPairs();
	/** *
	std::cout << "After getSortedPairs" << std::endl;
	printPairs();

	std::cout << "After mergeSortPairs" << std::endl;
	**/
	mergeSortPairs(0, p.size() -1);
	//printPairs();

	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = p.begin(); it != p.end(); it++)
	{
		mainSq.push_back(it->first);
		pendSq.push_back(it->second);
	}
	/** *
	std::cout << "Main Sq:" << std::endl;
	for (std::vector<unsigned int>::iterator it = mainSq.begin(); it != mainSq.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Pend Sq:" << std::endl;
	for (std::vector<unsigned int>::iterator it = pendSq.begin(); it != pendSq.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	**/
	//insertWithJacobsthal(mainSq, pendSq);
	jacobsthalInsert(mainSq, pendSq);
	if (hasOdd)
	{
		size_t pos = binarySearchPos(mainSq, oddEle);
		//std::cout << "Inserting " << oddEle << " at position " << pos << std::endl;
		mainSq.insert(mainSq.begin() + pos, oddEle);
	}
	v = mainSq;
}


double PmergeMeVector::getVectorDuration()
{
	clock_t start = clock();
	fordJohnsonSort(v);
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	return (elapsed);
}
