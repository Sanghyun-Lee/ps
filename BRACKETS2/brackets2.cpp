#include <iostream>
#include <stack>

using namespace std;

bool brackets2(const string& formula) {
    const string OPENING("({["), CLOSING(")}]");
    stack<char> openStack;

    for (int i = 0; i < formula.size(); i++) {
        if (OPENING.find(formula[i]) != -1)
            openStack.push(formula[i]);
        else {
            if (openStack.empty())
                return false;

            if (OPENING.find(openStack.top()) != CLOSING.find(formula[i]))
                return false;
            
            openStack.pop();
        }
    }

    return openStack.empty();
}

int main() {
    int testCase = 0;
    cin >> testCase;

    while (testCase--) {
        string str;
        cin >> str;
        bool ret = brackets2(str);

        if (ret)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
	}

    return 0;
}