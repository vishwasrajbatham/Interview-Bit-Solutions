#include<bits/stdc++.h>
using namespace std;

void heapify(vector <int> &A, int n, int i)
{
    int smallest = i;
    int left_child = (2*i)+1;
    int right_child = (2*i)+2;

    if(left_child<n && A[left_child]<A[smallest])
        smallest = left_child;

    if(right_child<n && A[right_child]<A[smallest])
        smallest=right_child;

    if(smallest!=i)
    {
        swap(A[i],A[smallest]);
        heapify(A,n,smallest);
    }
}

void heap_sort(vector <int> &A, int n)
{ 
    for(int i=(n/2)-1; i>=0;i--)
        heapify(A,n,i);

    for(int i=n-1; i>=0; i--)
    {
        swap(A[0],A[i]);
        heapify(A,i,0);
    }
}

int main(){
    vector<int> A={468,335,569};
    int n=A.size();
    heap_sort(A,n);
    vector<int> reslt;
    //cout<<A[1]<<"\t"<<A[0]<<"\t";
    for(int i=0;i<n;i++){
        cout<<A[i]<<"\t";
    }
    return 0;
}