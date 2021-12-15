//
//  17478 재귀함수가 뭔가요?.cpp
//  12.14.2021
//
//  Created by 김택현 on 2021/12/14.
//

#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

int N{};

string str[4] ={"\"재귀함수가 뭔가요?\"",
                "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
                "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
                "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
                };

void f(int cnt) {
    if(cnt == N) {
        for(int i{}; i < cnt; i++)
            cout << "____";
        cout << str[0] << endl;
        
        for(int i{}; i < cnt; i++)
            cout << "____";
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
    }
    else {
        for(auto tmp : str) {
            for(int i{}; i < cnt; i++)
                cout << "____";
            cout << tmp << endl;
        }
        f(cnt + 1);
    }
    for(int i{}; i < cnt; i++) {
        cout << "____";
    }
    cout << "라고 답변하였지." << endl;
}

int main() {
    cin >> N;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
    f(0);
}
