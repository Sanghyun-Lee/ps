#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> split(string input, char delimiter) {
    vector<int> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(atoi(temp.c_str()));
    }
 
    return answer;
}

vector<int> slice(const vector<int>& v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
    const int N = preorder.size();
    cout << "preorder size = " << preorder.size() << " inorder size = " << inorder.size() << endl;
    if (preorder.empty())
        return;

    for (int i = 0; i < preorder.size(); i++)
        cout << preorder[i] << " ";
    
    cout << endl << "inorder " << endl;

    for (int i = 0; i < inorder.size(); i++)
        cout << inorder[i] << " ";

    cout << endl;
    const int root = preorder[0];
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    const int R = N - L - 1;

    printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
    printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));

    cout << root << ' ';
}

int main() {
    int testCase = 0;
    cin >> testCase;

    while (testCase--) {
        int node;
        cin >> node;

        string strInput;
        vector<int> preorder;
        vector<int> inorder;

        cin.ignore();
        getline(cin, strInput);
        preorder = split(strInput, ' ');

        strInput = "";
        getline(cin, strInput);
        inorder = split(strInput, ' ');

        printPostOrder(preorder, inorder);
    }
    return 0;
}