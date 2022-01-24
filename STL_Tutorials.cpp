//Illustrate the working of pairs
//Example1
/*class Solution {
    public:
    
    bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
        
        if(K == 0)
                return false;

        int N = arrive.size();
        
        vector<pair<int, int> > vec;
        for(int i = 0; i < N; ++i) {
            vec.push_back(make_pair(arrive[i], 1));
            vec.push_back(make_pair(depart[i], 0));
        }
         
        sort(vec.begin(), vec.end());
        
        int curActive = 0;
        int maxAns = 0;
        for (int i = 0; i < vec.size(); i++) {
           if (vec[i].second == 1) { // arrival
               curActive++;
               maxAns = max(maxAns, curActive);
            } else {
                curActive--;
            }
        }

        if (K >= maxAns) return true;
        return false;
    }
};
*/

//Working of maps  
//ordered maps->sorted data || unordered maps->unsorted random data 
/*Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have same key values.

Some basic functions associated with Map:
begin() – Returns an iterator to the first element in the map
end() – Returns an iterator to the theoretical element that follows last element in the map
size() – Returns the number of elements in the map
max_size() – Returns the maximum number of elements that the map can hold
empty() – Returns whether the map is empty
pair insert(keyvalue, mapvalue) – Adds a new element to the map
erase(iterator position) – Removes the element at the position pointed by the iterator
erase(const g)– Removes the key value ‘g’ from the map
clear() – Removes all the elements from the map

#include <iostream>
#include <iterator>
#include <map>
  
using namespace std;
  
int main()
{
  
    // empty map container
    map<int, int> gquiz1;
  
    // insert elements in random order
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(4, 20));
    gquiz1.insert(pair<int, int>(5, 50));
    gquiz1.insert(pair<int, int>(6, 50));
    gquiz1.insert(pair<int, int>(7, 10));
  
    // printing map gquiz1
    map<int, int>::iterator itr;
    cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;
  
    // assigning the elements from gquiz1 to gquiz2
    map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());
  
    // print all elements of the map gquiz2
    cout << "\nThe map gquiz2 after"
         << " assign from gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;
  
    // remove all elements up to
    // element with key=3 in gquiz2
    cout << "\ngquiz2 after removal of"
            " elements less than key=3 : \n";
    cout << "\tKEY\tELEMENT\n";
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
  
    // remove all elements with key = 4
    int num;
    num = gquiz2.erase(4);
    cout << "\ngquiz2.erase(4) : ";
    cout << num << " removed \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
  
    cout << endl;
  
    // lower bound and upper bound for map gquiz1 key = 5
    cout << "gquiz1.lower_bound(5) : "
         << "\tKEY = ";
    cout << gquiz1.lower_bound(5)->first << '\t';
    cout << "\tELEMENT = "
         << gquiz1.lower_bound(5)->second << endl;
    cout << "gquiz1.upper_bound(5) : "
         << "\tKEY = ";
    cout << gquiz1.upper_bound(5)->first << '\t';
    cout << "\tELEMENT = "
         << gquiz1.upper_bound(5)->second << endl;
  
    return 0;
}

Output:
The map gquiz1 is : 
    KEY    ELEMENT
    1    40
    2    30
    3    60
    4    20
    5    50
    6    50
    7    10


The map gquiz2 after assign from gquiz1 is : 
    KEY    ELEMENT
    1    40
    2    30
    3    60
    4    20
    5    50
    6    50
    7    10


gquiz2 after removal of elements less than key=3 : 
    KEY    ELEMENT
    3    60
    4    20
    5    50
    6    50
    7    10

gquiz2.erase(4) : 1 removed 
    KEY    ELEMENT
    3    60
    5    50
    6    50
    7    10

gquiz1.lower_bound(5) :     KEY = 5        ELEMENT = 50
gquiz1.upper_bound(5) :     KEY = 6        ELEMENT = 50
 

List of all functions of Map:

map insert() in C++ STL– Insert elements with a particular key in the map container. .
map count() function in C++ STL– Returns the number of matches to element with key value ‘g’ in the map.
map equal_range() in C++ STL– Returns an iterator of pairs. The pair refers to the bounds of a range that includes all the elements in the container which have a key equivalent to k.
map erase() function in C++ STL– Used to erase element from the container.
map rend() function in C++ STL– Returns a reverse iterator pointing to the theoretical element right before the first key-value pair in the map(which is considered its reverse end).
map rbegin() function in C++ STL– Returns a reverse iterator which points to the last element of the map.
map find() function in C++ STL– Returns an iterator to the element with key value ‘g’ in the map if found, else returns the iterator to end.
map crbegin() and crend() function in C++ STL– crbegin() returns a constant reverse iterator referring to the last element in the map container. crend() returns a constant reverse iterator pointing to the theoretical element before the first element in the map.
map cbegin() and cend() function in C++ STL– cbegin() returns a constant iterator referring to the first element in the map container. cend() returns a constant iterator pointing to the theoretical element that follows last element in the multimap.
map emplace() in C++ STL– Inserts the key and its element in the map container.
map max_size() in C++ STL– Returns the maximum number of elements a map container can hold.
map upper_bound() function in C++ STL– Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’ or definitely will go after the element with key value ‘g’ in the map
map operator= in C++ STL– Assigns contents of a container to a different container, replacing its current content.
map lower_bound() function in C++ STL– Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’ or definitely will not go before the element with key value ‘g’ in the map.
map emplace_hint() function in C++ STL– Inserts the key and its element in the map container with a given hint.
map value_comp() in C++ STL– Returns the object that determines how the elements in the map are ordered (‘<' by default).
map key_comp() function in C++ STL– Returns the object that determines how the elements in the map are ordered (‘<' by default).
map::size() in C++ STL– Returns the number of elements in the map.
map::empty() in C++ STL– Returns whether the map is empty.
map::begin() and end() in C++ STL– begin() returns an iterator to the first element in the map. end() returns an iterator to the theoretical element that follows last element in the map
map::operator[] in C++ STL– This operator is used to reference the element present at position given inside the operator.
map::clear() in C++ STL– Removes all the elements from the map.
map::at() and map::swap() in C++ STL– at() function is used to return the reference to the element associated with the key k. swap() function is used to exchange the contents of two maps but the maps must be of same type, although sizes may differ.
*/
//Working of unordered maps
//Example1
/*
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	// Declaring umap to be of <string, int> type
	// key will be of string type and mapped value will
	// be of int type
	unordered_map<string, int> umap;

	// inserting values by using [] operator
	umap["GeeksforGeeks"] = 10;
	umap["Practice"] = 20;
	umap["Contribute"] = 30;

	// Traversing an unordered map
	for (auto x : umap)
	cout << x.first << " " << x.second << endl;

}
*/
//Example 2
/*
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	// Declaring umap to be of <string, double> type
	// key will be of string type and mapped value will
	// be of double type
	unordered_map<string, double> umap;

	// inserting values by using [] operator
	umap["PI"] = 3.14;
	umap["root2"] = 1.414;
	umap["root3"] = 1.732;
	umap["log10"] = 2.302;
	umap["loge"] = 1.0;

	// inserting value by insert function
	umap.insert(make_pair("e", 2.718));

	string key = "PI";

	// If key not found in map iterator to end is returned
	if (umap.find(key) == umap.end())
		cout << key << " not found\n\n";

	// If key found then iterator to that key is returned
	else
		cout << "Found " << key << "\n\n";

	key = "lambda";
	if (umap.find(key) == umap.end())
		cout << key << " not found\n";
	else
		cout << "Found " << key << endl;

	// iterating over all value of umap
	unordered_map<string, double>:: iterator itr;
	cout << "\nAll Elements : \n";
	for (itr = umap.begin(); itr != umap.end(); itr++)
	{
		// itr works as a pointer to pair<string, double>
		// type itr->first stores the key part and
		// itr->second stores the value part
		cout << itr->first << " " << itr->second << endl;
	}
}
*/

//Illustrate the working of Sets
//Example1  
/*
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
}
// CPP program to demonstrate various functions of priority queue and pair in C++ STL
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

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<pair<int,int>> cp; 
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            cp.push_back(make_pair(nums[i],i));
        }
        sort(cp.begin(),cp.end());
        int i=0,j=cp.size();
        while(true){
            if(cp[i].first+cp[j].first==target)
            {
                ans.push_back(cp[i].second);
                ans.push_back(cp[j].second);
                return ans;
            }
            else if(nums[i]+nums[j]>target) j--;
            else    i++;
        }
        return ans;
    }
};

int main(){
    vector<int> a={2,7,9,11},b;
    int target=9;
    Solution o;
    b=o.twoSum(a,target);
    cout<<b[0]<<" "<<b[1];
    return 0;
}