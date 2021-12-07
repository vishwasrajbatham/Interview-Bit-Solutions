/*Problem Description

Given a string A consisting of lowercase characters.

Check if characters of the given string can be rearranged to form a palindrome.

Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.



Problem Constraints
1 <= |A| <= 105

A consists only of lower-case characters.



Input Format
First argument is an string A.



Output Format
Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.



Example Input
Input 1:

 A = "abcde"
Input 2:

 A = "abbaee"


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 No possible rearrangement to make the string palindrome.
Explanation 2:

 Given string "abbaee" can be rearranged to "aebbea" to form a palindrome. */
#include<bits/stdc++.h>
using namespace std;
//If each letter occurs even no of times(except letter which can occur odd no of times in case the length is odd)
class Solution{
    public:
        int solve(string);
};
int Solution::solve(string a) {
    int l=a.size();
    unordered_map<char,int> occ_table;
    int odd_occurences = 0;
    for(int i=0;i<l;i++){
        if(occ_table.find(a[i])==occ_table.end()){
            occ_table[a[i]]=1;
            odd_occurences++;
        }
        else{
            occ_table[a[i]]++;
            if( (occ_table[a[i]] % 2) == 0 ) odd_occurences--;
            else odd_occurences++;
        }
    }
    cout<<"odd_occurences"<<odd_occurences<<endl;
    //till now we have created a table with frequency of each letter as value and we also how many letter have
    //odd frequencies
    if(l%2 == 0 && odd_occurences==0)   return 1;
    else if((l % 2 != 0) && odd_occurences==1)  return 1;
    else return 0;
}

int main(){
    Solution obj;
    string a="abcde";
    cout<<obj.solve(a);
    return 0;
}
