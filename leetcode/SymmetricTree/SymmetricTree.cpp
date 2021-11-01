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
        if(v.size() < level) {
            vector<int> temp;
            v.push_back(temp);
        }

        if(root == NULL) {
            v[level - 1].push_back(-999);
            return;
        }
        
        v[level - 1].push_back(root->val);

        preOrder(root->left, v, level + 1);
        preOrder(root->right, v, level + 1);
    }

    bool isSymmetric(TreeNode* root) {
        vector<vector<int>> l;
        vector<vector<int>> r;
        
        preOrder(root->left, l, 1);
        preOrder(root->right, r, 1);
        
        if(l.size() != r.size())
            return false;
        
        for(int i = 0; i < l.size(); i++) {
            int l_size = l[i].size();
            int r_size = r[i].size();
            if(l_size != r_size)
                return false;

            for(int j = 0; j < l_size; j++) {
                if(l[i][l_size - j - 1] != r[i][j])
                    return false;
            }
        }

        return true;
    }
};