/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:20:17 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/13 13:45:28 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main(int ac, char **av)
{
	std::vector<unsigned int> v;

	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << "positive numbers here" << std::endl;
		return (1);
	}
	else
	{
		// insert the numbers into the vector
		insertIntoVector(v, ac, av);
		// print the number to check
		printVector(v);
	}

	return (0);
}

/*
Pairwise Sorting
1. Group the elements into pairs
2. Sort each pair - smaller one the left, larger on the right
3. Split the pair into two seperate sequence - one for the left, one for the right

Example
[8, 3, 7, 1, 5, 2, 6, 4]

1.Group into paris
(8,3), (7,1), (5,2), (6,4)

2. Sort each pair
(3,8), (1,7), (2,5), (4,6)

3. Split into sequence
Smaller num seq - [3, 1, 2, 4]
Larger num seq - [8, 7, 5, 6]

Insertion
1. Use Binary Search to insert into the right positions

How binary search works
1. Find the middle index n/2
2. See if the value is lesser or bigger then the middle index
3. loop through this part to find which position to insert

Finding Position: O(logN)
Inserting : O(N)

*/
