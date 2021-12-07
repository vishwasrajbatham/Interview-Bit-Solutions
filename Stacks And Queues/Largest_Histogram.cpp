#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &a) 
{
        int m= a.size(), ans=0;
        stack<int> s;
        for(int j=0; j<m; j++) 
        {
            if(s.empty() || a[s.top()]<a[j]) 
                s.push(j);
            else 
            {
                while(!s.empty() && a[s.top()]>=a[j]) 
                {
                    int ht= a[s.top()]; 
                    s.pop();
                    if(!s.empty()) 
                        ans= max(ans, (j-s.top()-1)*ht);
                    else 
                        ans= max(ans, j*ht);
                }
                s.push(j);
            }
        }
        while(!s.empty()) 
        {
            int ht= a[s.top()]; 
            s.pop();
            if(!s.empty())
                ans= max(ans, (m-s.top()-1)*ht);
            else 
                ans= max(ans, m*ht);
        }
    return ans;
}

int main()
{
   vector<int> A={ 90, 58, 69, 70, 82, 100, 13, 57, 47, 18};
   cout<<largestRectangleArea(A);
   return 0;
}