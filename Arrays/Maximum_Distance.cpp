//https://www.interviewbit.com/problems/max-distance/
/*Problem Description

Given an array A of integers, find the maximum of j - i 
where A[i] <= A[j].

Input Format-:
First and only argument is an integer array A.

Output Format-:
Return an integer denoting the maximum value of j - i;

Input 1:

 A = [3, 5, 4, 2]

Output 1:

 2

Explanation-:
 Maximum value occurs for pair (3, 4)
 */
 #include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maximumGap(const vector<int> &);
};
//O(n^2)
/*int Solution::maximumGap(const vector<int> &A) {
    int n=A.size();
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[j]>=A[i] && j-i>max)   max=j-i;
        }
    }
    
    if(max<=0)  return 0;
    return max;
}*/

/*int Solution::maximumGap(const vector<int> &A) 
    int n=A.size();
    vector<pair<int,int>> a;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        a.push_back(make_pair(A[i],i));
    }
    sort(a.begin(),a.end());
    vector<int> sort_vector;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)  sort_vector.push_back(a[j].second);
        sort(sort_vector.begin(),sort_vector.end());
        if(max<sort_vector[n-i-1]-sort_vector[0])   
            max=sort_vector[n-i-1]-sort_vector[0];
        sort_vector.clear();
    }
    return max;
}*/

//Best Time Complexity
int Solution:: maximumGap(const vector<int> &num) {
         
            if (num.size() == 0) return -1;
            if (num.size() == 1) return 0;
            vector<pair<int, int> > toSort; 
            for (int i = 0; i < num.size(); i++) {
                toSort.push_back(make_pair(num[i], i));
            }
            sort(toSort.begin(), toSort.end());
            int len = toSort.size();
            int maxIndex = toSort[len - 1].second;
            int ans = 0;

            for (int i = len - 2; i>= 0; i--) {
                ans = max(ans, maxIndex - toSort[i].second);
                maxIndex = max(maxIndex, toSort[i].second);
            }

        return ans;
    }



int main(){
    vector<int> A={3, 5, 4, 2};
    Solution o;
    cout<<o.maximumGap(A);
    return 0;
}