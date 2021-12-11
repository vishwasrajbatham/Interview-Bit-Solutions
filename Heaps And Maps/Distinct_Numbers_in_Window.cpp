#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> dNums(vector<int> &, int);
};

vector<int> Solution::dNums(vector<int> &a, int b) {
    vector<int> result;
    int n=a.size();
    if(b>n) return result;
    unordered_map<int,int> data_table;
    for(int i=0;i<b;i++){
        if(data_table.find(a[i])==data_table.end()) data_table[a[i]]=1;
        else    data_table[a[i]]++;
    }
    result.push_back(data_table.size());
    for(int i=b; i<n; i++){
        if(data_table.find(a[i])==data_table.end()) data_table[a[i]]=1;
        else    data_table[a[i]]++;
        data_table[a[i-b]]--; 
        if (data_table[a[i-b]]==0) data_table.erase(a[i-b]);
        result.push_back(data_table.size());
    }
    return result;
}

int main(){

}