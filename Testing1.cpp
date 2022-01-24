#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry=0,sum=0;
		ListNode *head,*tail,*newnode;
		tail=NULL;
		head=NULL;
		while(l1 != NULL || l2 != NULL ){
			newnode = new ListNode();

			if(tail != NULL)	tail->next=newnode;

			if(head==NULL)	head = newnode;

			if(l1 !=NULL && l2 !=NULL){
				sum=carry+l1->val+l2->val;
				carry=sum%10;
			}
			else if(l1 ==NULL && l2 !=NULL){
				sum=carry+l2->val;
				carry=sum%10;
			}
			else{
				sum=carry+l2->val;
				carry=sum%10;
			}
			newnode->val=sum%10;
			tail=newnode;
		}
		if(carry!=0){
			ListNode *newnode;
			newnode = new ListNode();
			tail->next=newnode;
			newnode->val=carry;
		}
		return head;
	}
};

int main()
{	
	cout<<"Abhi";
	return 0;
}