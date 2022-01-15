//https://www.interviewbit.com/problems/3-sum/
/*Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 

Return the sum of the three integers.

Assume that there will only be one solution

Example: 

given array S = {-1 2 1 -4}, 

and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int threeSumClosest(vector<int> &, int );
};

int Solution::threeSumClosest(vector<int> &a, int b) {
    sort(a.begin(),a.end());
    int n=a.size();
    for(int i=0;i<n;i++)    cout<<a[i]<<" ";
    cout<<"\n";
    int curr_sum,closest_sum=closest_sum=a[0]+a[1]+a[2];
    for(int i=1;i<n;i++){
        for(int j=0,k=n-1;j<i && k>i;){
            curr_sum=a[i]+a[j]+a[k];
            cout<<"i->"<<i <<" j->"<<j <<" k->"<< k<<"\t";
            cout<<"curr_sum->"<<curr_sum<<"\t" ;
            if(curr_sum == b)   return b;
            if(abs(curr_sum-b)<abs(closest_sum-b))  {closest_sum=curr_sum;  j++;}
            if(curr_sum<b)  j++;
            else    k--;
            cout<<"closest_sum->"<<closest_sum<<"\n" ;
        }
        cout<<"..................................................."<<"\n";
    }
    return closest_sum;
}

int main(){
    vector<int> a={-4, -8, -10, -9, -1, 1, -2, 0, -8, -2};
    int dif=0;
    Solution o;
    int res=o.threeSumClosest(a,dif); 
    cout<<res;
    return 0;
}