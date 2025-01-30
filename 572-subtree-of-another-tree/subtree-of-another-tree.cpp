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
    void check(TreeNode* root, TreeNode* sub, bool& ans)
    {
        if(!root) return ;

        bool curr=func(root,sub);
        if(curr) ans=true;

        check(root->left,sub,ans);
        check(root->right,sub,ans);
         
    }
    bool func(TreeNode* p , TreeNode* q)
    {
        if(!p && !q) return true;
        if((!p && q) || (!q && p) || (p->val!=q->val)) return false;

        bool l=func(p->left,q->left);
        bool r=func(p->right,q->right);

        return l&r;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        bool ans=false;
        check(root,subRoot,ans);
        return ans;
    }
};