//https://www.interviewbit.com/problems/find-nth-fibonacci/
/*Problem Description

Given an integer A you need to find the Ath fibonacci number modulo 109 + 7.

The first fibonacci number F1 = 1

The first fibonacci number F2 = 1

The nth fibonacci number Fn = Fn-1 + Fn-2 (n > 2)

Problem Constraints
1 <= A <= 109.

Input Format
First argument is an integer A.

Output Format
Return a single integer denoting Ath fibonacci number modulo 109 + 7.

Example Input
Input 1:

 A = 4
Input 2:

 A = 3

Example Output
Output 1:

 3
Output 2:

 2

Example Explanation
Explanation 1:

 F3 = F2 + F1 = 1 + 1 = 2
 F4 = F3 + F2 = 2 + 1 = 3
Explanation 2:

 F3 = F2 + F1 = 1 + 1 = 2
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int solve(int );
};

int Solution::solve(int n) {
    n=n-2;
    long long int f1=1,f2=1,temp;
    int m=(pow(10,9)+7);
    for(int i=0;i<n;i++){
        temp=f2;
        f2+=f1;
        f1=temp;
        cout<<"i->"<<i<<" f2->"<<f2<<"\n";
    }
    cout<<"f2->"<<f2<<"\n";
    cout<<"m->"<<m<<"\n";
    return f2%m;
}

int main(){
    int n;
    cin>>n;
    Solution o;
    cout<<"Ans->"<<o.solve(n);
}