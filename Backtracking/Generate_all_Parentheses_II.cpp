#include<bits/stdc++.h>
using namespace std;
void print1d(vector<string> ans){  //Print 1d vector
    for(int i=0;i<ans.size(); i++)   cout<<ans[i]<<"\n";
    cout<<"\n";
}
class Solution{
    public:
        vector<string> generateParenthesis(int );
};
void fc(int closed, int open, string ds, vector<string> &ans, int n){
    if(open+closed==2*n){
        ans.push_back(ds);
        return;
    }
    if(open>closed && open<n){ 
        fc(closed, open+1, ds+'(', ans, n);
        fc(closed+1, open, ds+')', ans, n);
    }
    if(open==closed && open<n){ 
        fc(closed, open+1, ds+'(', ans, n);
    }
    if(open==n){
        fc(closed+1, open, ds+')', ans, n);
    }
    return;
}
vector<string> Solution::generateParenthesis(int n) {
    vector<string> ans;
    string ds;
    fc(0, 0, ds, ans, n);
    return ans;
}

int main(){
    vector<string> ans;
    Solution o;
    ans=o.generateParenthesis(3);
    sort(ans.begin(),ans.end());
    print1d(ans);
    return 0;
}