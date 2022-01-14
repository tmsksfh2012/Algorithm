//
//  11057 오르막 수.cpp
//  12.21.2021
//
//  Created by 김택현 on 2021/12/21.
//

#include <iostream>
#define Moduler 10007
using namespace std;

int N{};
int DP[1001][10]{};

void dp() {
    for (int i = 0; i < 10; i++)
    {
        DP[1][i] = 1;
    }
 
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                DP[i][j] = DP[i][j] + DP[i - 1][k];
                DP[i][j] = DP[i][j] % Moduler;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    dp();
    
    int Answer = 0;
    for (int i = 0; i < 10; i++)
    {
        Answer = Answer + DP[N][i];
    }
    Answer = Answer % Moduler;
 
    cout << Answer;
}
