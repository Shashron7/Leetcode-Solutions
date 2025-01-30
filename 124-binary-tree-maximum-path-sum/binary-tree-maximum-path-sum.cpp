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
    int func(TreeNode* root, int& maxm)
    {
        if(!root) return 0;

        int l=func(root->left,maxm);
        int r=func(root->right,maxm);

        l=max(l,0);
        r=max(r,0);

        maxm=max(maxm,root->val+l+r);
        return root->val+max(l,r);

    }
    int maxPathSum(TreeNode* root) {
        int maxm=INT_MIN;
        
        int ans=func(root,maxm);
        return maxm;
    }
};