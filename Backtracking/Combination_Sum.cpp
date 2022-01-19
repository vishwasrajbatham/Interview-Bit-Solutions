//https://www.interviewbit.com/problems/combination-sum/
/*Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 

Given candidate set 2,3,6,7 and target 7,

A solution set is:

[2, 2, 3]
[7]
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