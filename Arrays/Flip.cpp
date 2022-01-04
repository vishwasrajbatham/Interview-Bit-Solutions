/*Problem Description

You are given a binary string A(i.e. with characters 0 and 1) consisting of characters A1, A2, ..., AN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters AL, AL+1, ..., AR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised.

If you don't want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

NOTE: Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.



Input Format
First and only argument is a string A.



Output Format
Return an array of integers denoting the answer.



Example Input
Input 1:

A = "010"
Input 2:

A = "111"


Example Output
Output 1:

[1, 1]
Output 2:

[]


Example Explanation
Explanation 1:

A = "010"


Pair of [L, R] | Final string
____________|__________
[1 1]          | "110"
[1 2]          | "100"
[1 3]          | "101"
[2 2]          | "000"
[2 3]          | "001"



We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].

Explanation 2:

No operation can give us more than three 1s in final string. So, we return empty array [].*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> flip(string);
};
//MY SOLUTION
/*vector<int> Solution::flip(string A) {
    int l=0,r=0,max_sum=INT_MIN,curr_sum=0;
    int s=A.size();
    vector<int> arr;
    for(int i=0;i<s;i++){
        if(A[i]=='0') arr.push_back(1);
        else arr.push_back(-1);
    }

    for(int i=0;i<s;i++)
    {
        curr_sum+=arr[i];
        cout<<"max_sum->"<<max_sum<<"\t"<<"curr_sum->"<<curr_sum<<"\n";
        if(max_sum<curr_sum)   
        {   
            max_sum=curr_sum;
            r=i;
        }
        if(curr_sum<0 && i!=s)
        {
            curr_sum=0;
            l=r=i+1;
        }   
        cout<<"i->"<<i<<"\t"<<"l->"<<l<<"\t"<<"r->"<<r<<"\n";
    }
    vector<int> res;
    if(l<s&&r<s){
    res.push_back(l+1);
    res.push_back(r+1);}
    return res;
}
*/

vector<int> Solution::flip(string A) {
    vector<int> ZeroOrOne(A.size()); 
    vector<int> ans;
    
    //converting string to vector of -1s and 1s;
    for(int i = 0; i<A.size(); i++)
    {
        if(A[i]=='0')   ZeroOrOne[i] = 1;
        else    ZeroOrOne[i] = -1;
    }
    //............................................................
    int cumulative=0, left=0, right=0, maxSum=INT_MIN;
    int leftAns=0, rightAns=0;
    
    for(int i=0; i<A.size(); i++){
        cumulative+=ZeroOrOne[i];
        
        if(cumulative<0)
        {
            left=i+1;
            cumulative=0;
        }
        
        else if(cumulative>maxSum)
        {
            leftAns = left;
            rightAns = i;
            maxSum=cumulative;
        }
    }
    
    if(maxSum<=0)   return ans;
    
    else{
        ans.push_back(leftAns+1);
        ans.push_back(rightAns+1);
    }
    
    return ans;
}

int main(){
    Solution obj;
    string A="011";
    vector<int> result;
    result=obj.flip(A);
    cout<<result[0]<<"\t"<<result[1];
    return 0;
}