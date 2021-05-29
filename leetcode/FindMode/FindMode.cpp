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
    vector<int> ans;
    int count = 0;
    int curr = INT_MIN;
    int max = 0;
public:
    vector<int> findMode(TreeNode* root) {
        searchBST(root);
        return ans;
    }
    
    void searchBST(TreeNode* root) {
        TreeNode* ret = root;
        if(ret == NULL)
            return;
        
        searchBST(root->left);
        
        if (root->val == curr) {
            count++;
        } else {
            count = 1;
            curr = root->val;
        }
        
        if (count > max) {
            max = count;
            ans = {root->val};
        } else if (count == max) {
            ans.push_back(root->val);
        }
        
        searchBST(root->right);
    }
};