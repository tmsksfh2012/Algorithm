#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s{};

	cin >> s;

    // groups
    vector<int> groups;
    // 몇 번이나 연속되는지 저장
    // s의 최소 길이는 1이므로, 초기값을 1로 설정
    int countSeq = 1;
    // 정답
    int result = 0;

    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] != s[i - 1])
        {
            groups.push_back(countSeq);
            countSeq = 1;
        }
        else
        {
            ++countSeq;
        }
    }
    // s의 끝부분은 if문으로 걸러낼 수 없기 때문에 따로 삽입
    groups.push_back(countSeq);

    for (int i = 1; i < groups.size(); ++i)
    {
        result += min(groups[i - 1], groups[i]);
    }
    cout << result;

}