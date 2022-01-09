//https://www.interviewbit.com/problems/hotel-bookings-possible/
/*Problem Description

A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .



Input Format
First argument is an integer array A containing arrival time of booking.

Second argument is an integer array B containing departure time of booking.

Third argument is an integer C denoting the count of rooms.



Output Format
Return True if there are enough rooms for N bookings else return False.

Return 0/1 for C programs.



Example Input
Input 1:

 A = [1, 3, 5]
 B = [2, 6, 8]
 C = 1


Example Output
Output 1:

 0


Example Explanation
Explanation 1:

 At day = 5, there are 2 guests in the hotel. But I have only one room.*/
//Similar ques can be formed as - lines are drawn from absissas x1[i] to x2[i]
//  Return 1 if the maximum overlapping length of the lines drawn is less than k(int k passed as integer to the function)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool hotel(vector<int> &, vector<int> &, int);
};

void print_vector(vector<int> A){
    for(int i=0;i<A.size();i++) cout<<A[i]<<"\t";
    cout<<"\n";
}
//Wrong space complexity
/*int Solution::hotel(vector<int> &arrive, vector<int> &depart, int k) {
    int max=INT_MIN;
    for(int i=0;i<arrive.size();i++){
        if(depart[i]>max)    max=depart[i];
    }
    vector<int> count(max,0);
    int a_date,d_date;
    for(int i=0;i<arrive.size();i++){
        for(int j=arrive[i];j<depart[i];j++){
            count[j]++;
            cout<<"count[i] for i = "<<i<<" and j = "<< j<<" is "<<count[j]<<"\n";
            if(count[j]>k)  return 0;
        }

        //print_vector(count);
    }
    return 1;
}*/
//k=no of available rooms
//arrive.size()=no of rooms required
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    if(K == 0)
        return false;

    int N = arrive.size();
        
    vector<pair<int, int> > vec;
    //merging both arrival vector and departure vector in one and sorting them
    //arrival dates before then afterwards departure dates
    /*if arrival dates and departure dates are same they are sorted on the basis
      of 0 or 1 present in their respective pairs so arrive dates lead*/
    for(int i = 0; i < N; ++i) {
        vec.push_back(make_pair(arrive[i], 1));
        vec.push_back(make_pair(depart[i], 0));
    }         
    sort(vec.begin(), vec.end());
    int curActive = 0;                  //declaring cuurActive=0 
    int maxAns = 0;                     //declaring maxAns=0
    for (int i = 0; i < vec.size(); i++) {
       if (vec[i].second == 1)          //condition for arrival 
        {
            curActive++;
            maxAns = max(maxAns, curActive);
        }                               //for departure
        else    curActive--;
    }
    if (K >= maxAns) return true;
    return false;
}

int main(){
    vector<int> a={47, 4, 0, 12, 47, 31, 15, 49, 29, 33, 7, 22, 26, 24, 16};
    vector<int> d={95, 4, 26, 16, 51, 79, 43, 58, 32, 80, 30, 27, 29, 54, 16};
    Solution obj;
    bool m=obj.hotel(a,d,10);
    cout<<endl<<"ha hai"<<m;
    return 0;
}