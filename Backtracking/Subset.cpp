//https://www.interviewbit.com/problems/subset/
/*Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int> > subsets(vector<int> & );
};

void print2d(vector<vector<int>> ans){
    for(int i=0;i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++)   cout<<ans[i][j]<<"\t";
        cout<<"\n";
    }
}
void print1d(vector<int> ans){
    for(int i=0;i<ans.size(); i++)   cout<<ans[i]<<"\t";
    cout<<"\n";
}

void solve(int i, vector<vector<int> > &ans, vector<int> &a, vector<int> &ds ){
    if(i>=a.size())  ans.push_back(ds);
    else{
        //choose
        ds.push_back(a[i]);
        solve(i+1, ans, a, ds);
        ds.pop_back();
        //don't
        solve(i+1, ans, a, ds);
    }
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<int> a;
    //print1d(A);
    for(vector<int>::iterator itr=A.begin();itr!=A.end();itr++)    a.push_back(*itr);
    //print1d(a);
    sort(a.begin(),a.end());
    //print1d(a);
    Solution o;
    vector<vector<int> > ans;
    vector<int> ds={};
    solve(0, ans, a, ds);
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int> A={12,13};
    Solution o;
    vector<vector<int>> ans = o.subsets(A);
    print2d(ans);
    return 0;
}