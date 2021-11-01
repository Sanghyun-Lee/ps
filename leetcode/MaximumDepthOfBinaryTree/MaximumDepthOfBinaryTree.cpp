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
    int preOrder(TreeNode* root, int level, int max) {
        if(root == NULL) {
            if(level - 1 > max)
                max = level - 1;
            return max;
        }
        
        int left = preOrder(root->left, level + 1, max);
        int right = preOrder(root->right, level + 1, max);
        
        if (left > max)
            max = left;
        
        if (right > max)
            max = right;
        
        return max;
    }

    int maxDepth(TreeNode* root) {
        return preOrder(root, 1, INT_MIN);;
    }
};