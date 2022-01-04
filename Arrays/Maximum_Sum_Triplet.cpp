/*Problem Description

Given an array A containing N integers.

You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

If no such triplet exist return 0.



Problem Constraints
3 <= N <= 105.

1 <= A[i] <= 108.



Input Format
First argument is an integer array A.



Output Format
Return a single integer denoting the maximum sum of triplet as described in the question.



Example Input
Input 1:

 A = [2, 5, 3, 1, 4, 9]
Input 2:

 A = [1, 2, 3]


Example Output
Output 1:

 16
Output 2:

 6


Example Explanation
Explanation 1:

 All possible triplets are:-
    2 3 4 => sum = 9
    2 5 9 => sum = 16
    2 3 9 => sum = 14
    3 4 9 => sum = 16
    1 4 9 => sum = 14
  Maximum sum = 16
Explanation 2:

 All possible triplets are:-
    1 2 3 => sum = 6
 Maximum sum = 6
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int solve(vector<int> &);
};

int Solution::solve(vector<int> &A) {
    vector<int> triplet(3,INT_MIN);
    for(int i=0;i<A.size();i++){
        cout<<"    i->"<<i<<"    A[i]->"<<A[i]<<endl;
        if(A[i]>triplet[0]){
            triplet[0]=A[i];
            sort(triplet.begin(),triplet.end());
        }
        cout<<"     triplet[0]->"<<triplet[0]<<"    triplet[1]->"<<triplet[1]<<"    triplet[2]->"<<triplet[2]<<endl<<endl;
    }
    return triplet[0]+triplet[1]+triplet[2];
}

int main(){
    Solution obj;
    vector<int> a={18468, 6335, 26501, 19170, 15725, 11479, 29359, 26963, 24465, 5706, 28146, 23282, 16828, 9962, 492, 2996, 11943, 4828, 5437, 32392, 14605};
    int sum=obj.solve(a);
    cout<<sum;
}