//https://www.interviewbit.com/problems/anti-diagonals/
/*Problem Description

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
Example:

Input:

1 2 3
4 5 6
7 8 9
Return the following:
[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input: 
1 2
3 4
Return the following: 
[
  [1],
  [2, 3],
  [4]
]*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int> > diagonal(vector<vector<int> > &);
};

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int> > matrix;
    int mid=A.size()-1;
    int n,initial,final;

    for(n=0; n<=mid; n++)
    {
        initial=0,final=n;
        vector<int> oneD;
    
        for(int i=initial, j=final;i<=n;i++,j--){
            oneD.push_back(A[i][j]);
        }
    
        matrix.push_back(oneD);
    
    }

    for(;n<=mid*2;n++)
    {
        initial=n-mid,final=mid;
        vector<int> oneD;
    
        for(int i=initial, j=final;i<=mid;i++,j--){
            oneD.push_back(A[i][j]);
        }
    
        matrix.push_back(oneD);
    
    }
    
    return matrix;

}

int main(){
    Solution o;
    vector<vector<int> > matrix;
    vector<vector<int> > m={{1,2,3},{4,5,6},{7,8,9}};
    matrix=o.diagonal(m);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;  
}