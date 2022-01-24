#include<bits/stdc++.h>
using namespace std;

void print2d(vector<vector<int>> ans){  //Print 2d vector
    for(int i=0;i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++)   cout<<ans[i][j]<<"\t";
        cout<<"\n";
    }
}
void print1d(vector<int> ans){  //Print 1d vector
    for(int i=0;i<ans.size(); i++)   cout<<ans[i]<<"\t";
    cout<<"\n";
}
class Solution {
public:
    vector<vector<int> > combine(int , int );
};

void fc(vector<vector<int> > &ans, int n, int k, int count, vector<int> ds){
    if(count==k)    {
        sort(ds.begin(),ds.end());
        ans.push_back(ds);
        print1d(ds);
    }
    else if(n==0)   return;
    else{
        ds.push_back(n);
        fc(ans, n-1, k, count+1, ds);
        ds.pop_back();
        fc(ans, n-1, k, count, ds);
    }
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int> > ans;
    int count=0; 
    vector<int> ds;
    fc(ans, n, k, count, ds);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    Solution o;
    vector<int> ds;
    vector<vector<int>> ans={};
    ans=o.combine(1,1);
    print2d(ans);
}