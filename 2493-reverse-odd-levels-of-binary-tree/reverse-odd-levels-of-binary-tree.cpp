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
    void func(TreeNode* node1, TreeNode* node2, int level)
    {
        if(!node1 || !node2) return ;

        if(level%2==1)
        {
            int value= node1->val;
            node1->val=node2->val;
            node2->val=value;

        }

        func(node1->left, node2->right, level+1);
        func(node1->right, node2->left, level+1);

    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level=1;


        func(root->left,root->right,level);
        return root;

    }
};