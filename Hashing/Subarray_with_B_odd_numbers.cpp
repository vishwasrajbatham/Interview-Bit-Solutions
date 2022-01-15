//https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/
/*Problem Description

Given an array of integers A and an integer B.

Find the total number of subarrays having exactly B odd numbers.



Problem Constraints
1 <= length of the array <= 105

1 <= A[i] <= 109

0 <= B <= A



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the total number of subarrays having exactly B odd numbers.



Example Input
Input 1:

 A = [4, 3, 2, 3, 4]
 B = 2
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 3


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

 The subarrays having exactly B odd numbers are:
 [4, 3, 2, 3], [4, 3, 2, 3, 4], [3, 2, 3], [3, 2, 3, 4]
Explanation 2:

 The subarrays having exactly B odd numbers is [5, 6, 7, 8, 9]
 */
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int solve(vector<int> &, int );
};

int Solution::solve(vector<int> &a, int m) {
    int n=a.size();
    int count = 0;
    int prefix[n + 1] = { 0 };
    int odd = 0;
 
    // traverse in the array
    for (int i = 0; i < n; i++)
    {
 
        prefix[odd]++;
 
        // if array element is odd
        if (a[i] & 1)
            odd++;
 
        // when number of odd elements>=M
        if (odd >= m)
            count += prefix[odd - m];
    }
 
    return count;
}

int main(){

}