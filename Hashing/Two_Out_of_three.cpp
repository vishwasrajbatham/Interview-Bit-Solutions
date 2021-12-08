/*Problem Description

Given are Three arrays A, B and C.

Return the sorted list of numbers that are present in atleast 2 out of the 3 arrays.



Problem Constraints
1 <= |A|, |B|, |C| <= 100000

1 <= A[i], B[i], C[i] <= 100000

A, B, C may or may not have pairwise distinct elements.



Input Format
First argument is the array A.

First argument is the array B.

First argument is the array C.



Output Format
Return a sorted array of numbers.



Example Input
Input 1:

A = [1, 1, 2]
B = [2, 3]
C = [3]
Input 2:

A = [1, 2]
B = [1, 3]
C = [2, 3]


Example Output
Output 1:

[2, 3]
Output 2:

[1, 2, 3]


Example Explanation
Explanation 1:

1 is only present in A. 2 is present in A and B. 3 is present in B and C.
Explanation 2:

All numbers are pres*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> solve(vector<int> &,vector<int> &,vector<int> &);
};
vector<int> Solution::solve(vector<int> &a, vector<int> &b, vector<int> &c) {
    set<int> sa(a.begin(),a.end());
    set<int> sb(b.begin(),b.end());
    set<int> sc(c.begin(),c.end());
    set<int> :: iterator set_itr;
    unordered_map<int,int> frequency_table;
    vector<int> ans;

    for(set_itr=sa.begin();set_itr!=sa.end();set_itr++){
        if(frequency_table.find(*set_itr)==frequency_table.end()){
            frequency_table[*set_itr]=1;
        }
    }
    for(set_itr=sb.begin();set_itr!=sb.end();set_itr++){
        if(frequency_table.find(*set_itr) == frequency_table.end())
        {
            frequency_table[*set_itr]=1;
        }
        else
        {
            frequency_table[*set_itr]=2;
        }
    }
    for(set_itr=sc.begin();set_itr!=sc.end();set_itr++)
    {
        if(frequency_table.find(*set_itr) == frequency_table.end())
        {
            frequency_table[*set_itr]=1;
        }
        else
        {
            frequency_table[*set_itr]=2;
        }
    }
    unordered_map<int,int>:: iterator itr;
	for (itr = frequency_table.begin(); itr != frequency_table.end(); itr++)
	{
		if(itr->second == 2)    ans.push_back(itr->first);
	}
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int> a={2,9,8,7,6,4,5,9};
    set<int> sa(a.begin(),a.end());
    set<int> :: iterator itr;
    for(itr = sa.begin();itr != sa.end();itr++){
        cout<<*itr<<"\n";
    }
}