/* CPP program to demonstrate various functions of Set in C++ STL
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main()
{
	// empty set container
	set<int, greater<int> > s1;

	// insert elements in random order
	s1.insert(40);
	s1.insert(30);
	s1.insert(60);
	s1.insert(20);
	s1.insert(50);

	// only one 50 will be added to the set
	s1.insert(50);
	s1.insert(10);

	// printing set s1
	set<int, greater<int> >::iterator itr;
	cout << "\nThe set s1 is : \n";
	for (itr = s1.begin(); itr != s1.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	// assigning the elements from s1 to s2
	set<int> s2(s1.begin(), s1.end());

	// print all elements of the set s2
	cout << "\nThe set s2 after assign from s1 is : \n";
	for (itr = s2.begin(); itr != s2.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	// remove all elements up to 30 in s2
	cout << "\ns2 after removal of elements less than 30 "
			":\n";
	s2.erase(s2.begin(), s2.find(30));
	for (itr = s2.begin(); itr != s2.end(); itr++) {
		cout << *itr << " ";
	}

	// remove element with value 50 in s2
	int num;
	num = s2.erase(50);
	cout << "\ns2.erase(50) : ";
	cout << num << " removed\n";
	for (itr = s2.begin(); itr != s2.end(); itr++) {
		cout << *itr << " ";
	}

	cout << endl;

	// lower bound and upper bound for set s1
	cout << "s1.lower_bound(40) : \n"
		<< *s1.lower_bound(40) << endl;
	cout << "s1.upper_bound(40) : \n"
		<< *s1.upper_bound(40) << endl;

	// lower bound and upper bound for set s2
	cout << "s2.lower_bound(40) :\n"
		<< *s2.lower_bound(40) << endl;
	cout << "s2.upper_bound(40) : \n"
		<< *s2.upper_bound(40) << endl;

	return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> Solution::solve(vector<vector<int> > &);
};

#define pi pair< int, pair<int, int> >
vector<int> Solution::solve(vector<vector<int> > &a) {
    priority_queue<pi, vector<pi>, greater<pi>> minHeap;
    int k = a.size(), n = a[0].size();
    for ( int i = 0; i < k; ++i ) {
        minHeap.push( {a[i][0], {i, 0} } );
    }
    vector<int> ans;
    while ( !minHeap.empty() ) {
        pi x = minHeap.top();
        minHeap.pop();
        ans.push_back( x.first );
        int arr = x.second.first;
        int ind = x.second.second;
        ++ind;
        if ( ind < n ) {
            minHeap.push( { a[arr][ind], { arr, ind } } );
        }
    }
    return ans;
}

int main()
{
	vector<vector<int> > A = {{1, 2, 3},{2, 4, 6},{0, 9, 10},{8,6,4}};
	int k=A.size();
	int n=A[0].size();
	//cout<<k<<"\t"<<n<<endl;
	sort(A.begin(),A.end());
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cout<<A[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<A[2][0];
	return 0;
}*/
#include <string>
#include<iostream>

using namespace std;

char intTochar(int i)
{
    return 'a'+i-1;
}

int charToint(char c)
{
    return c-'0';
}

int getCodes(string ip, string op[10000]) 
{
   if(ip.length()==1)
   {
       op[0]=ip[0]+'0';
       return 1;
   } 
   string op1[5000],op2[5000]="";
   int s1=getCodes(ip.substr(1),op1);
   int s2=0;
   for(int i=0;i<s1;i++)
   {
       int y=charToint(ip[0]);
       char c=intTochar(y);
       op[i]=c+op1[i];
   }

   int x=(charToint(ip[0])*10+charToint(ip[1]));

   if(ip.length()>2)
       if(x>=10&&x<=26)
       s2=getCodes(ip.substr(2),op2);

	if(ip.length()==2)
	{ char c=intTochar(x);
		if(x>=10&&x<=26)
	op[s1]=c+op2[1];
	s2++;

	}

    for(int i=0;i<s2;i++)
       {
           char c=intTochar(x);
           op[i+s1]=c+op2[i];
           
       }

	return s1+s2;

}

int main()
{
    string ip;
    cin>>ip;
	string *op=new string[1000];
  
    int len=getCodes(ip,op);

    for(int i=0;i<len;i++)    cout<<op[i]<<endl;
	return 0;
}
