#include<iostream>
using namespace std;

void heapify(int A[], int n, int i){
    int largest = i;
    int left_child = (2*i)+1;
    int right_child = (2*i)+2;

    if(left_child<n && A[left_child]>A[largest])
        largest = left_child;

    if(right_child<n && A[right_child]>A[largest])
        largest=right_child;

    if(largest!=i){
        swap(A[i],A[largest]);
        heapify(A,n,largest);
    }
}

void heap_sort(int A[], int n){
    for(int i=(n/2)-1;i>=0;i--)
        heapify(A,n,i);

    for(int i=n-1;i>=0;i--){
        swap(A[0],A[i]);
        heapify(A,i,0);
    }
}

int main(){
    int A[10]={7,9,5,44,89,88,62,3,596,12};
    int n=10;
    heap_sort(A,n);
    for(int i=0;i<10;i++){
        cout<<A[i]<<"\t";
    }
    return 0;
}