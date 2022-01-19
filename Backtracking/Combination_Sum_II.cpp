//https://www.interviewbit.com/problems/combination-sum-ii/
/*Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int> > combinationSum(vector<int> &, int );
};

void ret(int index, vector<int> ds, vector<int> a, int target,vector<vector<int> > & result){
    if(target==0)   result.push_back(ds);
    else if(index==a.size() || target<0) return;
    else{
        //taking
        ds.push_back(a[index]);
        ret(index, ds, a, target-a[index], result);
        ds.pop_back();
        //not take
        ret(index+1, ds, a, target, result);
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &a, int target) {
    set<int> test;
    vector<int> v;
    for(int i=0;i<a.size();i++){
        test.insert(a[i]);
    }
    set<int>::iterator itr;
	for (itr = test.begin(); itr != test.end(); itr++) {
		v.push_back(*itr);
	}
    sort(v.begin(),v.end());
    vector<int> ds={};
    vector<vector<int> > result;
    ret(0, ds, v, target, result);
    sort(result.begin(),result.end());
    return result;
}

int main(){
    
}