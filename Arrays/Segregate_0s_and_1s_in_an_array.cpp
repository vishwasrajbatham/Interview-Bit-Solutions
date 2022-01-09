//https://www.interviewbit.com/problems/segregate-0s-and-1s-in-an-array
/*Problem Description
 
 


You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array [Basically you have to sort the array]. Traverse array only once. 



Problem Constraints
1<=|A|<=1e6


Input Format
First argument is array of integers consisting of 0's and 1's only.


Output Format
Return a sorted array.


Example Input
Input 1:
a=[0 1 0]
Input 2:

A=[1 1 0 ]


Example Output
Ouput 1:
[0 0 1]
Ouput 2:

[0 1 1]


Example Explanation
Explanation 1:
 above is sorted array.
Explanation 2:

sort the array.*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int>  solve(vector<int> &);
};
vector<int> Solution::solve(vector<int> &A) {
    int z=0;
    for(int i=0;i<A.size();i++) if(A[i]==0) z++;
    vector<int> ans(A.size(),1);
    for(int i=0;i<z;i++) ans[i]=0;
    return ans;
}

int main(){
    Solution obj;
    vector<int> a={18468, 6335, 26501, 19170, 15725, 11479, 29359, 26963, 24465, 5706, 28146, 23282, 16828, 9962, 492, 2996, 11943, 4828, 5437, 32392, 14605};
    vector<int> sum=obj.solve(a);
    return 0;
}