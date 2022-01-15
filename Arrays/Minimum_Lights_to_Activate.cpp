//https://www.interviewbit.com/problems/minimum-lights-to-activate/
/*Problem Description
There is a corridor in a Jail which is N units long. Given an array A of size N. The ith index of this array is
0 if the light at ith position is faulty otherwise it is 1.
All the lights are of specific power B which if is placed at position X, it can light the corridor from 
[ X-B+1, X+B-1].Initially all lights are off.
Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor 
cannot be lighted.

Problem Constraints
1 <= N <= 1000

1 <= B <= 1000

Input Format

First argument is an integer array A where A[i] is either 0 or 1.Second argument is an integer B.

Output Format
Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.

Example Input
Input 1:

A = [ 0, 0, 1, 1, 1, 0, 0, 1].
B = 3

Input 2:

A = [ 0, 0, 0, 1, 0].
B = 3

Example Output
Output 1:

2

Output 2:

-1

Example Explanation
Explanation 1:

In the first configuration, Turn on the lights at 3rd and 8th index.
Light at 3rd index covers from [ 1, 5] and light at 8th index covers [ 6, 8].
Explanation 2:

In the second configuration, there is no light which can light the first corridor.*/#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int solve(vector<int> &, int ); 
        /*{   
            int prev_bulb=-1,min_bulb=0,c=prev_bulb+B;
            int n=A.size();
            while(c<=n){
                if(A[c]==1){
                    min_bulb++;
                    prev_bulb=c;
                    c=prev_bulb+B;
                }
                else if(c==prev_bulb){
                    return -1;
                }
                else{
                    c--;
                }
            }
            return -1;
        }*/
};
int Solution::solve(vector<int> &A, int B) {

}
int main(){
    //main program for passing vectors;
    
}