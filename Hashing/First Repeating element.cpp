/*Problem Description

Given an integer array A of size N, find the first repeating element in it.

We need to find the element that occurs more than once and whose index of first occurrence is smallest.

If there is no repeating element, return -1.



Problem Constraints
1 <= N <= 105

1 <= A[i] <= 109



Input Format
First and only argument is an integer array A of size N.



Output Format
Return an integer denoting the first repeating element.



Example Input
Input 1:

 A = [10, 5, 3, 4, 3, 5, 6]
Input 2:

 A = [6, 10, 5, 4, 9, 120]


Example Output
Output 1:

 5
Output 2:

 -1


Example Explanation
Explanation 1:

 5 is the first element that repeats
Explanation 2:

 There */

//Input:  A = [10, 5, 3, 4, 3, 5, 6]
//Outpu: 5
#include<bits/stdc++.h>
using namespace std;

int solve() {
    vector<int> a = { 8, 15, 1, 10, 5, 19, 19, 3, 5, 6, 6, 2, 8, 2, 12, 16, 3 };
    int n = a.size();
    unordered_map<int,int> index_table;
    int final_index = INT_MAX ;
    for(int i=0;i<n;i++){
        if( index_table.find(a[i]) == index_table.end() )
        {
            index_table[a[i]]=i;
        }
        else
        {
            if(index_table[a[i]] < final_index)
            {
                cout<<"Since "<<index_table[a[i]] <<"<"<< final_index<<endl;
                cout<<"changing final_index from "<<final_index<<" to "<<index_table[a[i]]<<endl;
                final_index = index_table[a[i]];
            }
        }
    }
    if(final_index == INT_MAX)
    return -1;

    return a[final_index];
}

int main(){
    cout<<solve();
    return 0;
}