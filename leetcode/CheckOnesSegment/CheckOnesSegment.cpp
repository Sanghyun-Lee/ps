class Solution {
public:
    bool checkOnesSegment(string s) {
        // 찾는 문자열이 없으면 npos return
        return s.find("01") == string::npos;
    }
};