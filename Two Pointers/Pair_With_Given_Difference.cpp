/*https://www.interviewbit.com/problems/pair-with-given-difference/*/
/*Problem Description

Given an one-dimensional unsorted array A containing N integers.

You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.

Return 1 if any such pair exists else return 0.



Problem Constraints
1 <= N <= 105
-103 <= A[i] <= 103
-105 <= B <= 105


Input Format
First argument is an integer array A of size N.

Second argument is an integer B.



Output Format
Return 1 if any such pair exists else return 0.



Example Input
Input 1:

 A = [5, 10, 3, 2, 50, 80]
 B = 78
Input 2:

 A = [-10, 20]
 B = 30


Example Output
Output 1:

 1
Output 2:

 1


Example Explanation
Explanation 1:

 Pair (80, 2) gives a difference of 78.
Explanation 2:

 Pair (20, -10) gives a difference of 30 i.e 20 - (-10) => 20 + 10 => 30

*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        pair<int,int> solve(vector<int> &a, int dif);
};

pair<int,int> Solution::solve(vector<int> &a, int dif) {
    int n=a.size();
    for(int i=0,j=n-1;i<n && j>i;){
        if(a[j]-a[i]==dif && i!=j)  return (make_pair(a[i],a[j]));
        else if(a[j]-a[i]>dif)  i++;
        else j++;
    }
    return (make_pair(-1,-1));
}

int main(){
    vector<int> a={1,2,3,4,5,6,7,8,9,66,5,8,77,44,11,31};
    int dif=33;
    Solution o;
    sort(a.begin(),a.end());
    pair<int,int> res=o.solve(a,dif);
    cout<<res.first<<"\t"<<res.second;
    return 0;
}