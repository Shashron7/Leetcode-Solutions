/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void func(TreeNode* root, int maxm, int& count)
    {
        if(!root) return ; 

        int originalMaxm=maxm;
        if(root->val >= maxm) count++;
        maxm=max(maxm,root->val);
        //take the new max value
        func(root->left,maxm,count);
        func(root->right,maxm,count); 
        maxm=originalMaxm; //revert back to old max value
        return ; 
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        int maxm=INT_MIN;
        func(root,maxm,count);

        return count;
    }
};