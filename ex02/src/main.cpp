/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:20:17 by gyong-si          #+#    #+#             */
/*   Updated: 2025/02/24 14:38:26 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMeVector.hpp"
#include "../include/PmergeMeDeque.hpp"

int main(int ac, char **av)
{
	PmergeMeVector	a;
	PmergeMeDeque	b;
	double	vec_time;
	double	deq_time;

	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " insert positive numbers here" << std::endl;
		return (1);
	}
	else
	{
		runChecks(ac, av);
		a.insertIntoContainer(ac, av);
		b.insertIntoContainer(ac, av);
		std::cout << "Before: " << std::endl;
		a.printContainer();
		vec_time = a.getVectorDuration();
		deq_time = b.getDequeDuration();
		std::cout << "After: " << std::endl;
		a.printContainer();
		std::cout << std::fixed << std::setprecision(6);
		std::cout << "Time to process a range of " << a.size()
		<< " elements with std::vector: " << vec_time << " us" << std::endl;
		std::cout << "Time to process a range of " << b.size()
		<< " elements with std::deque: " << deq_time << " us" << std::endl;
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
