//https://www.interviewbit.com/problems/permutations/
/*Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]

NOTE-:

No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the 
collection are unique.
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.

Example : next_permutations in C++ / itertools.permutations in python.

If you do, we will disqualify your submission retroactively and give 
you penalty points.
*/

#include<bits/stdc++.h>
using namespace std;
string max_string="";

class Solution {
public:
    void permute(vector<int> &A, int start, vector<vector<int> > &result) {
        if (start == A.size() - 1) {
            result.push_back(A);
            return;
        } 
        for (int i = start; i < A.size(); i++) {
            swap(A[start], A[i]);
            permute(A, start + 1, result);
            swap(A[start], A[i]);
        }
    }

    vector<vector<int> > permute(vector<int> &A) {
        vector<vector<int> > result;
        if (A.size() == 0)
            return result;
        sort(A.begin(), A.end());
        permute(A, 0, result);
        return result;
    }
};

int main(){
    Solution obj;
    vector<int> a={2,9,8,7,5,9,8,5,6,4,2,3,5,8,9,8,4,23,89,96,45,17};
    vector< vector<int> > result = obj.permute(a);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[0].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}