#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int LONGEST;
int N, Y[100], X[100], R[100];

struct TreeNode {
    vector<TreeNode*> children;
};

int sqr(int x) {
    return x * x;
}

int getDist(int a, int b) {
    return sqr(Y[a] - Y[b]) + sqr(X[a] - X[b]);
}

bool encloses(int a, int b) {
    return R[a] > R[b] && getDist(a, b) < sqr(R[a] - R[b]);
}

int height(TreeNode* root) {
    vector<int> heights;

    for (int i = 0; i < root->children.size(); i++) {
        heights.push_back(height(root->children[i]));
    }

    if (heights.empty())
        return 0;

    sort(heights.begin(), heights.end());

    if (heights.size() >= 2) {
        LONGEST = max(LONGEST, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
    }

    return heights.back() + 1;
}

int solve(TreeNode* root) {
    LONGEST = 0;
    int h = height(root);

    return max(h, LONGEST);
}

bool isChild(int parent, int child) {
    if (!encloses(parent, child))
        return false;
    
    for (int i = 0; i < N; i++) {
        if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
            return false;
    }
    return true;
}

TreeNode* getTree(int root) {
    TreeNode* ret = new TreeNode();
    for (int ch = 0; ch < N; ch++) {
        if (isChild(root, ch)) {
            ret->children.push_back(getTree(ch));
        }
    }
    return ret;
}

int main() {
    int testCase = 0;
    cin >> testCase;

    while (testCase--) {
        cin >> N;
        cin.ignore();

        for (int i = 0; i < N; i++) {
            cin >> X[i] >> Y[i] >> R[i];
        }

        cout << solve(getTree(0)) << endl;
    }
    return 0;
}