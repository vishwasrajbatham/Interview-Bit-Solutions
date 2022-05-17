//https://www.interviewbit.com/problems/profit-maximisation/
/*Problem Description

 Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.

Problem Constraints
1 <= |A| <= 100000

1 <= B <= 1000000

Input Format
First argument is the array A.

Second argument is integer B.

Output Format
Return one integer, the answer to the problem.

Example Input
Input 1:

A = [2, 3]
B = 3
Input 2:

A = [1, 4]
B = 2

Example Output

Output 1:
7

Output 2:
7

Example Explanation
Explanation 1:

 First you serve the seat with number = 3. Then with 2 and then with 2. hence answer = 3 + 2 + 2 = 7.
Explanation 2:

 You give bith tickets from the row with 4 seats. 4 + 3 = 7.
 */
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
/*int solve(vector<int> &A, int B) {
    int cost=0;
    int n=A.size();
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        q.push(A[i]);
    }
    for(int i=0;i<B;i++){
        cost+=q.top();
        q.push(q.top()-1);
        q.pop();
    }
    return cost;
}*/

int main(){
    Solution obj;
    vector<int> Seats={2,3};
    cout<<obj.solve(Seats, 3);
    return 0;
}