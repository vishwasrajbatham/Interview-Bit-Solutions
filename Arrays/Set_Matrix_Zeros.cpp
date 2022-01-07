//https://www.interviewbit.com/problems/set-matrix-zeros/
/*
Problem Description

Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.

Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]


Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]



Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]



Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void setZeroes(vector<vector<int> > &A);
};

void Solution::setZeroes(vector<vector<int> > &A) {
    set<int> rows,cols;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]==0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    set<int>::iterator itr;
    int m=A.size();
    int n=A[0].size();
    for(itr=rows.begin();itr!=rows.end();itr++){
        for(int j=0;j<n;j++){
            A[*itr][j]=0;
        }
    }
    for(itr=cols.begin();itr!=cols.end();itr++){
        for(int i=0;i<m;i++){
            A[i][*itr]=0;
        }
    }
}


int main(){
    Solution o;;
    vector<vector<int> > m={{1,2,3},{4,5,6},{7,8,9}};
    o.setZeroes(m);
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            cout<<m[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;  
}