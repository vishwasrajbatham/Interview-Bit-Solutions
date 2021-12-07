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