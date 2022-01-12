#include <string>
#include <vector>
#include <stack>
using namespace std;

/*2022.01.11
어렵지 않은 문제.*/

bool isRight(string s) {
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ')') {
            if (st.top() == '(')
                st.pop();
            else
                return false;
        }
        else 
            st.push(s[i]);
    }
    if (!st.empty()) return false;
    return true;
}
string make(string s) {
    if (s.empty())
        return s;
    string u, v;
    int left = 0, right = 0, spliceIdx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') left++;
        else right++;
        if (left != 0 && left == right) {
            spliceIdx = i;
            break;
        }
    }
    u = s.substr(0, spliceIdx + 1);
    v = s.substr(spliceIdx + 1);
    if (isRight(u))
        return u + make(v);
    else {
        string res = "";
        res += '(' + make(v) + ')';
        u.pop_back();
        for (int i = 1; i < u.size(); i++)
            res += (u[i] == '(') ? ')' : '(';
        return res;
    }
}
string solution(string p) {
    string answer = "";
    answer = make(p);
    return answer;
}