#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
        TreeNode* getSuccessor(TreeNode* , int );
};

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode *t=A;
    TreeNode *ans=NULL;
    while(t!=NULL)
    {
        if(t->val<=B)    t=t->right;
        else
        {
            ans=t;
            t=t->left;
        }
    }
    return ans;
}

int main(){
    Solution obj;
}