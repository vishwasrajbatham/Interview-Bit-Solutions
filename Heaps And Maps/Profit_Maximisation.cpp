#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int solve(vector<int> &, int);
};

void heapify(vector <int> &A, int n, int i)
{
    int largest = i;
    int left_child = (2*i)+1;
    int right_child = (2*i)+2;

    if(left_child<n && A[left_child]>A[largest])
        largest = left_child;

    if(right_child<n && A[right_child]>A[largest])
        largest=right_child;

    if(largest!=i)
    {
        swap(A[i],A[largest]);
        heapify(A,n,largest);
    }
}

void heap_sort(vector <int> &A, int n)
{ 
    for(int i=(n/2)-1; i>=0;i--)    //forming the heap
        heapify(A,n,i);

    for(int i=n-1; i>=0; i--)
    {
        swap(A[0],A[i]);
        heapify(A,i,0);
    }
}


int Solution::solve(vector<int> &A, int B) {
    int cost=0;
    int n=A.size();
    for(int i=0;i<B;i++){
        heap_sort(A,n);
        cost+=A[n-1];
        A[n-1]--;
    }
    return cost;
}

int main(){
    Solution obj;
    vector<int> Seats={2,3};
    cout<<obj.solve(Seats, 3);
    return 0;
}