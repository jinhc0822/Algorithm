#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

/*2022.01.24
kmp 구현을 알고 있고 #이 달린 음들을 소문자로 대체해서 풀 경우 쉬운 문제.*/

struct Music {
	int playTime;
	int idx;
	string name;
	string melody;
};
vector<int> table;

string replaceSharp(string s) {
	string res = "";
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i + 1] == '#') {
			res += (s[i] + 32);
			i++;
		}
		else 
			res += s[i];
	}
	if (s.back() != '#')
		res += s.back();
	return res;
}
bool comp(Music a, Music b) {
	if (a.playTime != b.playTime)
		return a.playTime > b.playTime;
	else
		return a.idx < b.idx;
}void lps(string pat) {
	int p = pat.size();
	for (int i = 1, j = 0; i < p; i++) {
		while (j > 0 && pat[i] != pat[j])
			j = table[j - 1];
		if (pat[i] == pat[j])
			table[i] = ++j;
	}
}
bool kmp(string wh, string pat) {
	int w = wh.size();
	int p = pat.size();
	for (int i = 0, j = 0; i < w; i++) {
		while (j > 0 && wh[i] != pat[j])
			j = table[j - 1];
		if (wh[i] == pat[j]) {
			if (j == p - 1)
				return true;
			else
				j++;
		}
	}
	return false;
}
string solution(string m, vector<string> musicinfos) {
	vector<Music> radio;
	m = replaceSharp(m);
	for (int i = 0; i < musicinfos.size(); i++) {
		vector<string> v;
		string t, res = "";
		stringstream ss(musicinfos[i]);
		while (getline(ss, t, ','))
			v.push_back(t);
		int pt = (stoi(v[1].substr(0, 2)) * 60 + stoi(v[1].substr(3))) - 
			(stoi(v[0].substr(0, 2)) * 60 + stoi(v[0].substr(3)));
		v[3] = replaceSharp(v[3]);
		for (int j = 0, k = 0; j < pt; j++, k++) {
			if (k == v[3].size())
				k = 0;
			res += v[3][k];
		}
		radio.push_back({ pt, i, v[2], res });
	}
	sort(radio.begin(), radio.end(), comp);
	table.resize(m.size());
	lps(m);
	for (int i = 0; i < radio.size(); i++)
		if (kmp(radio[i].melody, m))
			return radio[i].name;
	return "(None)";
}