#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next, *prev;
}*head,*tail;


struct data_table{
    map<int, node *ptr> data_address;
    int cap; 
    node l_list;
};

/*class LRUCache{
    LRUCache(int capacity); 
    public:
        int get(int);
        void set(int, int);
};

LRUCache::LRUCache(int capacity) {
    data_table man;
    man.cap=capacity;
    man.l_list->head=NULL;
    man.l_list->tail=NULL;
};

int LRUCache::get(int key) {
    return (man.data_address[key])->value;
}

void LRUCache::set(int key, int value) {

}*/

int main(){

}