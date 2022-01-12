#include <string>
#include <vector>
using namespace std;

/*2022.01.11
풀이 방식은 맞았지만 구현 과정에서 어려움이 있었다.
밑의 코드는 인터넷에서 본 것인데 이 코드가 나랑 결은 비슷하지만
훨씬 더 나아보인다. 결국 if문이 많아질수록 코드의 질은 떨어지기에..
그래서인지 푸는 데 시간이 좀 오래걸렸다..*/

int f(int len, string s) {
    string tmp = s.substr(0, len);
    int res = 0, cnt = 1, remain = s.size() % len, i = len;
    bool chk = false;
    while (true) {
        if (chk && i >= s.size()) {
            if (tmp.size() < len) 
                break;
            if (cnt != 1)
                res += to_string(cnt).size() + len;
            else
                res += len;
            break;
        }
        if (tmp == s.substr(i, len))
            cnt++;
        else {
            if (cnt != 1)
                res += to_string(cnt).size() + len;
            else
                res += len;
            cnt = 1;
            tmp = s.substr(i, len);
        }
        chk = true;
        i += len;
    }
    res += remain;
    return res;
}
int solution(string s) {
    if (s.size() == 1)
        return 1;
    int answer = 2000;
    int n = s.size() / 2;
    for (int i = 1; i <= n; i++) {
        int k = f(i, s);
        if (answer > k)
            answer = k;
    }
    cout << '\n';
    return answer;
}
/*for(int i=1;i<=s.size()/2;i++){
        string convert,temp;

        int cnt=1;
        temp=s.substr(0,i);

        for(int j=i;j<s.size();j+=i){
        if(temp==s.substr(j,i)) cnt++;
        else{
            if(cnt>1) convert+=to_string(cnt);
            convert+=temp;
            temp=s.substr(j,i);
            cnt=1;
            }
        }

        if(cnt>1) convert+=to_string(cnt);

        convert+=temp;
        answer=max(answer,convert.size());
    }*/