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
    void preOrder(TreeNode* root, vector<vector<int>>& v, int level) {
        if(root == NULL)
            return;

        if(v.size() < level) {
            vector<int> temp;
            v.push_back(temp);
        }
            
        v[level - 1].push_back(root->val);

        preOrder(root->left, v, level + 1);
        preOrder(root->right, v, level + 1);

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        preOrder(root, ret, 1);

        return ret;
    }
};