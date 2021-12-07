/*Problem Description

Given are Three arrays A, B and C.

Return the sorted list of numbers that are present in atleast 2 out of the 3 arrays.



Problem Constraints
1 <= |A|, |B|, |C| <= 100000

1 <= A[i], B[i], C[i] <= 100000

A, B, C may or may not have pairwise distinct elements.



Input Format
First argument is the array A.

First argument is the array B.

First argument is the array C.



Output Format
Return a sorted array of numbers.



Example Input
Input 1:

A = [1, 1, 2]
B = [2, 3]
C = [3]
Input 2:

A = [1, 2]
B = [1, 3]
C = [2, 3]


Example Output
Output 1:

[2, 3]
Output 2:

[1, 2, 3]


Example Explanation
Explanation 1:

1 is only present in A. 2 is present in A and B. 3 is present in B and C.
Explanation 2:

All numbers are pres*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> solve(vector<int> &,vector<int> &,vector<int> &);
};
vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_map<int,int> frequency_table;
    vector<int> ans;
    for(int i=0;i<A.size();i++){
        if(frequency_table.find(A[i])==frequency_table.end()){
            frequency_table[A[i]]=1;
        }
    }
    for(int i=0;i<B.size();i++){
        if(frequency_table.find(B[i]) == frequency_table.end())
        {
            frequency_table[B[i]]=1;
        }
        else
        {
            frequency_table[B[i]]=2;
        }
    }
    for(int i=0;i<C.size();i++)
    {
        if(frequency_table.find(C[i]) == frequency_table.end())
        {
            frequency_table[C[i]]=1;
        }
        else
        {
            frequency_table[C[i]]=2;
        }
    }
    unordered_map<int,int>:: iterator itr;
	for (itr = frequency_table.begin(); itr != frequency_table.end(); itr++)
	{
		if(itr->second == 2)    ans.push_back(itr->first);
	}
    sort(ans.begin(),ans.end());
    return ans;
}