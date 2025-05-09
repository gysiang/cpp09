# Explaination of Ford Johnson Algorithm

**Example Input**
[4, 2, 8, 1, 3]

## Step 1 ##
If there is a odd number of elements, save it and remove it from the list.

In this case - 3

## Step 2 ##
My function - Get Sorted Pairs and mergeSortPair
Sort the rest of the numbers in the list into this form

Get sorted Pairs 
(pair up the number and make the smaller number infront)
[2, 4] [1, 8]

mergeSortPair (
move the pairs into a sorted list)
[1, 8] [2, 4]

## Step 3 ##
Push the first element (smaller number) into main sequence
Push the second element (larger number) into pending sequence

Main Sequence
[1, 2]

Pending Sequence
[8, 4]

## Step 4 ##
My function - insertWithJacobsthal
Using the Jacobsthal sequence to calculate the batch size.
Then based on the batch size, insert the numbers from the pending sequence into the main sequence using binary search to determine the exact position to insert the number intot he main sequence.

## Step 5 ##
Don't forget the odd number
Using binary search, insert the odd number 3 back into the main sequence.

## Result ##
After inserting the final odd number the main sequence is sorted.
[1, 2, 3, 4, 8]


