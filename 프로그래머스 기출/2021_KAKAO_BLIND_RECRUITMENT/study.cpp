#include <string>
#include <vector>
#include <sstream>
using namespace std;

/*2022.01.04*/

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> applicant[3][2][2][2];
    for (int i = 0; i < info.size(); i++) {
        string s = info[i], t;
        stringstream ss(s);
        vector<string> v;
        while (getline(ss, t, ' ')) {
            v.push_back(t);
        }

    }
    return answer;
}