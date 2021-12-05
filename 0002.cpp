Simple Approach is to traverse for every triplet with three nested ‘for loops’ and find update the sum of
 all triplets one by one. Time complexity of this approach is O(N3) which is not sufficient for larger value 
of ‘N’.


Better approach is to make further optimization in above approach.

Instead of traversing through every triplets with three nested loops, we can traverse through two nested 
loops.

While traversing through each number(assume as middle element(Aj)), find maximum number(Ai) smaller 
than Aj preceding it and maximum number(Ak) greater than Aj beyond it.

Now after that, update the maximum answer with calculated sum of Ai + Aj + Ak.

Time complexity: O(N2)
Auxiliary space: O(1)

This approach is also that much efficient we are looking for.


Best Approach:

Best and efficient approach is use the concept of maximum suffix-array and binary search.

For finding maximum number greater than given number beyond it, we can maintain a maximum suffix-array 
array such that for any number(suffix[i]) it would contain maximum number from index i, i+1, … N-1. Suffix 
array can be calculated in O(N) time.

For finding maximum number smaller than the given number preceding it, we can maintain a sorted list 
of numbers before a given number such we can simply perform a binary search to find a number which is just 
smaller than the given number. In C++ language, we can perform this by using set associative container of 
STL library.

Time complexity: O(NlogN)
Auxiliary space: O(N)


............................................................................................................................................................................................................
An Efficient Solution can solve this problem in O(N) time using O(N) extra space. Below is detailed solution.

Create two arrays leftMax[] and rightMin[].

Traverse input array from left to right and fill leftMax[] such that leftMax[i] contains maximum 
element from 0 to i-1 in input array.

Traverse input array from right to left and fill rightMin[] such that rightMin[i] contains minimum element 
from N-1 to i+1 in input array.

Traverse input array. For every element A[i], check if A[i] is greater than leftMax[i] and smaller than 
rightMin[i]. If yes, return 1.

If loops exits and no such element found return 0

A Further Optimization to the above approach is to use only one extra array and traverse input array only 
twice.

The first traversal is the same as above and fills leftMax[]. Next traversal traverses from the right and 
keeps track of the minimum. The second traversal also finds the required element.

Time Complexity: O(N)
Auxiliary Space: O(N)