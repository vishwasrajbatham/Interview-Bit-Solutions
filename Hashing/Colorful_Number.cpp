//https://www.interviewbit.com/problems/colorful-number/
/*For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1*/
#include<bits/stdc++.h>
using namespace std;

int colorful(int A) 
{  
    string a = to_string( A);
    int len = a.length();
    unordered_map<long long, bool> data_table;

        for(int i = 0; i < len; i++) {      //checks for ordered substrings beginning with a[len-i] of all lengths.
            long long product = 1;
            for(int j = i; j < len; j++) 
            {   
                cout<<a[j]<<"\t";
                product = product * (long long)(a[j] - '0');
                
                if(data_table.find(product) != data_table.end())   // when data_table does'nt contain the key er are 
                    return 0;                                       //trying to find it returns the end iterator
                       
                data_table[product] = true;                          // else store the product in data_table with key=product and value=Bool(true)
            }
            cout<<"\n";
        }
        return 1;
}

int main(){
    int no;
    cin>>no;
    cout<<colorful(no);
    return 0;
}