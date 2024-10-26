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
    unordered_map<int, int> treeDict; // Store heights in a dictionary

    int calcHeight(TreeNode* node, int height) {
        if (!node) return height - 1;
        
        int leftH = calcHeight(node->left, height + 1);
        int rightH = calcHeight(node->right, height + 1);
        
        if (node->left) {
            treeDict[node->left->val] = rightH;
        }
        if (node->right) {
            treeDict[node->right->val] = leftH;
        }
        
        return max(leftH, rightH);
    }

    void updateTreeDict(TreeNode* node, int maxheight) {
        if (!node) return;
        
        if (treeDict[node->val] > maxheight) {
            maxheight = treeDict[node->val];
        }
        
        if (node->left && maxheight > treeDict[node->left->val]) {
            treeDict[node->left->val] = maxheight;
        }
        if (node->right && maxheight > treeDict[node->right->val]) {
            treeDict[node->right->val] = maxheight;
        }
        
        updateTreeDict(node->left, maxheight);
        updateTreeDict(node->right, maxheight);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        calcHeight(root, 0);
        updateTreeDict(root, -2);
        
        vector<int> result;
        for (int q : queries) {
            result.push_back(treeDict[q]);
        }
        return result;
    }
};