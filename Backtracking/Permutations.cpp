#include<bits/stdc++.h>
using namespace std;
string max_string="";
class Solution{
    public:
        vector<vector<int> > permute(vector<int> &);
};

vector<vector<int> > Solution::permute(vector<int> &A) {

}

int main(){
    Solution obj;
    vector<int> a={2,9,8,7,5};
    vector< vector<int> > result = obj.permute(a);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[0].size(); j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<"\n";
    }
}