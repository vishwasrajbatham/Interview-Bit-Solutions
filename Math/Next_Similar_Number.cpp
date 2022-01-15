 //https://www.interviewbit.com/problems/next-similar-number/
/*Problem Description

Given a number A in a form of string.

You have to find the smallest number that has 
same set of digits as A and is greater than A.

If A is the greatest possible number with its set 
of digits, then return -1.

Problem Constraints
 1 <= A <= 10100000

 A doesn't contain leading zeroes.

Input Format
First and only argument is an numeric string 
denoting the number A.

Output Format
Return a string denoting the smallest number greater
than A with same set of digits , if A is the largest
 possible then return -1.

Example Input
Input 1:

 A = "218765"
Input 2:

 A = "4321"

Example Output
Output 1:

 "251678"
Output 2:

 "-1"

Example Explanation
Explanation 1:

 The smallest number greater then 218765 with same
 set of digits is 251678.
Explanation 2:

 The given number is the largest possible number 
 with given set of digits so we will return -1.*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        string solve(string );
};

string Solution::solve(string A) {
    string copied=A;
    int n=A.size(),tofind;
    int index_i=-1;
    for(int i=n-1;i>0;i--){
        if(A[i]>A[i-1]) {index_i=i-1;break;}
    }    
    cout<<"Index_i:"<<index_i<<"\n";
    if(index_i==-1) return ("-1");
    int min=INT_MAX;
    int min_index;
    for(int j=index_i;j<n;j++){
        if(A[j]>A[index_i] && A[j]<=min){
            min_index=j;
            min=A[j];
        }    
    }
    cout<<"Min_index:"<<min_index<<"\n";
    cout<<"Min_val"<<"\n";
    swap(A[index_i],A[min_index]);
    cout<<"A after swapping"<<A<<"\n";
    sort(A.begin()+index_i+1,A.end());
    return A;
}

int main(){
    string A;
    cin>>A;
    Solution o;
    cout<<"Ans->"<<o.solve(A);
}