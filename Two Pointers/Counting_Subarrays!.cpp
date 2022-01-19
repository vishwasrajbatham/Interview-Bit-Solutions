//https://www.interviewbit.com/problems/counting-subarrays/
/*Problem Description

Given an array A of N non-negative numbers and you are also given non-negative number B.

You need to find the number of subarrays in A having sum less than B. We may assume that there is no overflow.

Problem Constraints
1 <= N <= 104

1 <= A[i] <= 100

1 <= B <= 108

Input Format
First argument is an integer array A.

Second argument is an integer B.

Output Format
Return an integer denoting the number of subarrays in A having sum less than B.

Example Input
Input 1:

 A = [2, 5, 6]
 B = 10
Input 2:

 A = [1, 11, 2, 3, 15]
 B = 10

Example Output
Output 1:

 4
Output 2:

 4

Example Explanation
Explanation 1:

 The subarrays with sum less than B are {2}, {5}, {6} and {2, 5},
Explanation 2:

 The subarrays with sum less than B are {1}, {2}, {3} and {2, 3}
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int solve(vector<int> &, int);
};
/*
int Solution::solve(vector<int> &a, int b) {
    int sum=a[0],cnt=0,begin=0,end=0;
    cout<<sum;
    while(end<=a.size()){
        if(sum<b){
            cnt+=end-begin+1;
            end++;
            sum+=a[end];
        }
        else{    
            sum=sum-a[begin];
            begin++;
        }
    }
    return cnt;
}*/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), begin= 0, end= 0, res = 0, sum = A[0];
    while(begin< n && end< n)
    {
        if(sum < B)
        {
            end++;
            if(end>=begin)
                res += (end-begin);
            if(end< n)
                sum += A[end];
        }
        else
        {
            sum -= A[begin];
           begin++;
        }
    }
    return res;
}

int main(){
    vector<int> a={8, 5, 1, 10, 5, 9, 9, 3, 5, 6, 6, 2, 8, 2, 2, 6, 3, 8, 7, 2, 5, 3, 4, 3, 3, 2, 7, 9, 6, 8, 7, 2, 9, 10, 3, 8, 10, 6, 5, 4, 2, 3, 4, 4, 5, 2, 2, 4, 9, 8, 5}; 
    int b=32;
    Solution o;
    cout<<o.solve(a,b);
    return 0;
}