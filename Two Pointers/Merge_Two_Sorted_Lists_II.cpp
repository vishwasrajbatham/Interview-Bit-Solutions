//https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
/*Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.

TIP: C users, please malloc the result into a new array and return the result.

If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void merge(vector<int> &, vector<int> &);
};

void Solution::merge(vector<int> &A, vector<int> &B){
    vector<int> result;
    int na=A.size(),nb=B.size();
    int a=0,b=0;
    
    while(a<na && b<nb){
        if(A[a]<B[b]){
            result.push_back(A[a]);
            a++;
        }
        else if(A[a]>B[b]){
            result.push_back(B[b]);
            b++;
        }
        else{
            result.push_back(A[a]);
            a++;
            result.push_back(B[b]);
            b++;
        }
    }
    if(a<na){
        for(;a<na;a++)  result.push_back(A[a]);
    }
    else{
        for(;b<nb;b++)  result.push_back(B[b]);
    }
    A.clear();
    for(int i=0;i<result.size();i++){
        A.push_back(result[i]);
    }
}