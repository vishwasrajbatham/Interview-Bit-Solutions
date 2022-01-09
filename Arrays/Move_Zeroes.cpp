//https://www.interviewbit.com/courses/programming/topics/arrays
/*Problem Description

Given an integer array A, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Problem Constraints
1 <= |A| <= 105

Input Format
First argument is array of integers A.

Output Format
Return an array of integers which satisfies above property.

Example Input
Input 1:
A = [0, 1, 0, 3, 12]
Input 2:

A = [0]

Example Output
Ouput 1:
[1, 3, 12, 0, 0]
Ouput 2:

[0]

Example Explanation
Explanation 1:
Shift all zeroes to the end.
Explanation 2:

There is only one zero so no need of shifting.*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int>  solve(vector<int> &);
};
vector<int> Solution::solve(vector<int> &A) {
    int z=0;
    vector<int> ans;
    for(int i=0;i<A.size();i++) 
    {   
        if(A[i]==0) z++;
        else    ans.push_back(A[i]);
    }
    for(int i=0;i<z;i++)    ans.push_back(0);
    
    return ans;
}

int main(){
    Solution obj;
    vector<int> a={18468, 6335, 26501, 19170, 15725, 11479, 29359, 26963, 24465, 5706, 28146, 23282, 16828, 9962, 492, 2996, 11943, 4828, 5437, 32392, 14605};
    vector<int> sum=obj.solve(a);
    return 0;
}