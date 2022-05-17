#include<bits/stdc++.h>
using namespace std;
void printvec(vector<int> v){
	for(auto it: v)	cout<<it<<" ";
    cout<<"\n";
}
// Function to calculate maximum triplet sum
int solve(vector<int> &A) {
    int ans=0;
    int n=A.size();
    vector<int> right(n, 0);
    for(int i=n-2; i>=0; i--) 
    {
        int mx = max(right[i+1], A[i+1]);
        if(mx>A[i]) right[i]=mx;
    }
    set<int> s;
    s.insert(A[0]);
    for(int i=1; i<n-1; i++) {
        s.insert(A[i]);
        if(right[i]!=0) 
        {
            auto itr = s.find(A[i]);
            if(itr!=s.begin())    ans = max(ans, (A[i]+(*(--itr))+right[i]));
        }
    }
    return ans;
}
 
int main()
{
    vector<int> arr = { 2, 5, 3, 1, 4, 9 };
    cout << solve(arr);
    return 0;
}
