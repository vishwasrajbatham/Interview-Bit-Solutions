//https://www.interviewbit.com/problems/maximal-string/
/*Problem Description

Given a string A and integer B, what is maximal lexicographical stringthat can be made from A if you do atmost 
B swaps.

Problem Constraints
1 <= |A| <= 9

A contains only digits from 0 to 9.

1 <= B <= 5

Input Format-:

First argument is string A. Second argument is integer B.

Output Format-:

Return a string, the naswer to the problem.

Example I/O-:

Input 1:

A = "254"
B = 1

Output 1:

 524

Input 2:

A = "254'
B = 2

Output 2:

 542

Example Explanation

Explanation 1:

 Swap 2 and 5.

Explanation 2:

Swap 2 and 5 then swap 4 and 2.
*/
/*
1) Create a global variable which will store the maximum string or number.
2) Define a recursive function that takes the string as number and value of k
3) Run a nested loop, the outer loop from 0 to length of string -1 and inner loop from i+1 to end of string.
4) Swap the ith and jth character and check if the string is now maximum and update the maximum string.
5) Call the function recursively with parameters: string and k-1.
6) Now again swap back the ith and jth character.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        string solve(string, int);
};
/*string Solution::solve(string A, int max_swaps){
    int n=A.size();
    if(max_swaps==0 || n<2)    return A;
    int max_alpha;
    for(int i=0;i<n;i++){
        max_alpha=i;
        for(int j=i+1;j<n;j++){
            if(A[j]>A[max_alpha])   max_alpha=j;
        }
        if(max_alpha!=i)    {swap(A[i],A[max_alpha]);   max_swaps--;}
        cout<<"A->"<<A<<"\t"<<max_swaps<<"\n";
        if(max_swaps==0)    return A;    
    }
}*/

string max_string="";

string Solution::solve(string A, int B) {
    for(int i=0;i<A.size()-1;i++){
        for(int j=i+1;j<A.size();j++){
            swap(A[i],A[j]);
            if(max_string<A){
                max_string=A;
            }
            solve(A,B-1);
            swap(A[i],A[j]);
        }
    }
}

int main()
{
    string A="129814999";
    Solution obj;
    string max_string=obj.solve(A,4);
    cout<<max_string;
    return 0;
}