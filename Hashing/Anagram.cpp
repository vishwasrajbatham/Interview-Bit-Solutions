/*Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp'

Note:  All inputs will be in lower-case.

Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4. 

dog and god are another set of anagrams which correspond to index 2 and 3.

The indices are 1 based ( the first element has index 1 instead of index 0).

Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int> > anagrams();
};

vector<vector<int> > Solution::anagrams() {
    const vector<string> A={"cat", "dog", "god", "tca"};
    vector<vector<int> > result;
    vector<string> sorted_strings;
    for(int i=0; i<A.size(); i++){
        sorted_strings.push_back(A[i]);
        sort(sorted_strings[i].begin(),sorted_strings[i].end());
    }
    unordered_map<string, vector<int> > data_table;
    for(int i=0; i<A.size(); i++){
        data_table[sorted_strings[i]].push_back(i+1);
    }
    unordered_map<string, vector<int> >:: iterator itr;
    for(itr=data_table.begin(); itr!=data_table.end(); itr++){
        if((itr->first).size()>=1)   
            result.push_back(itr->second);
    }
    return result;
}

int main()
{
    Solution obj;
    vector<vector<int> > result = obj.anagrams();
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}