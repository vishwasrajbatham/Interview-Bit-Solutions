// C++ program to demonstrate functionality of unordered_map
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

/*
at(): This function in C++ unordered_map returns the reference to the value with the element as key k.

begin(): Returns an iterator pointing to the first element in the container in the unordered_map container

end(): Returns an iterator pointing to the position past the last element in the container in the unordered_map 
       container

bucket(): Returns the bucket number where the element with the key k is located in the map.

bucket_count: bucket_count is used to count the total no. of buckets in the unordered_map. No parameter is required 
              to pass into this function.

bucket_size: Returns the number of elements in each bucket of the unordered_map.

count(): Count the number of elements present in an unordered_map with a given key.

equal_range: Return the bounds of a range that includes all the elements in the container with a key that compares 
             equal to k.*/