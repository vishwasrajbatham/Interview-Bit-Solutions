//https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
/*

Problem Description

Given an index k, return the kth row of the Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Input : k = 3


Return : [1,3,3,1]

Note: k is 0 based. k = 0, corresponds to the row [1]. 

Note: Could you optimize your algorithm to use only O(k) extra space?
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> getRow(int );
};
/* I Approach

long long findFact(int num)
{
    int i=1, fact=1;
    while(i<=num)
    {
        fact = i*fact;
        i++;
    }
    return fact;
}
int findNPR(int n, int r)
{
    long long numerator, denominator;
    numerator = findFact(n);
    denominator = findFact(n-r);
    return (numerator/denominator);
}
int findNCR(int n, int r)
{
    int npr, ncr;
    npr = findNPR(n, r);
    ncr = npr/findFact(r);
    return ncr;
}
vector<int> Solution::getRow(int A) {   vector<int> result;
    for(int i=0;i<=A+1;i++){
        result.push_back(findNCR(A+1,i));
    }
    return result;
}*/

//II approach
vector<int> Solution::getRow(int k) {
    vector<int>res(k+1,0);
    res[0]=1;

    for(int i=1;i<=k;i++){
        for(int j=min(k,i);j>=0;j--){
            res[j]=res[j]+res[j-1];
        }
        /*cout<<i;
        for(int m=0;m<=k;m++)   cout<<res[m]<<"\t";
        cout<<"\n";*/
    }
    return res;
}

int main(){
    Solution obj;
    int k=5;
    vector<int> res=obj.getRow(k);
    for(int m=0;m<=k;m++)   cout<<res[m]<<"\t";
    return 0;
}