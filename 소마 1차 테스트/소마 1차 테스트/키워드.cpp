#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N{}, T{};
vector<string> vc{};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // 키워드 목록의 개수
    cin >> N;

    // 키워드 입력
    for (int i{}; i < N; i++) {
        string tmp{};
        cin >> tmp;
        vc.push_back(tmp);
    }

    // 입력 단어 개수
    cin >> T;

    // 입력 단어 입력
    for (int i{}; i < T; i++) {
        string tmp{};
        cin >> tmp;

        int num{};
        for (auto key : vc) {
            if (key == tmp)
                num++;
            else {
                if (key[0] == tmp[0]) {
                    bool flag = true;
                    for (int j = 1; j < (int)tmp.length(); j++)
                        if (key[j] != tmp[j]) {
                            flag = false;
                            break;
                        }
                    
                   if(flag)
                       num++;
                }
            }
        }
        cout << num;
    }

    return 0;
}