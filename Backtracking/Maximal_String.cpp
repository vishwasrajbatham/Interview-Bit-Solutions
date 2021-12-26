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
string max_string="";
class Solution{
    public:
        string solve(string, int);
};
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
    string A="254";
    Solution obj;
    obj.solve(A,2);
    cout<<max_string;
    return 0;
}