#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 250 + 1;

int N;

string cache[MAX];


//long long 자료형으로도 커버 안되는 숫자는 string으로 직접 구현해줘야한다

string bigNumAdd(string num1, string num2) {

	long long sum = 0;

	string result;

	//1의 자리부터 더하기 시작한다

	while (!num1.empty() || !num2.empty() || sum) {

		if (!num1.empty()) {

			sum += num1.back() - '0';
			num1.pop_back();

		}

		if (!num2.empty()) {

			sum += num2.back() - '0';
			num2.pop_back();
		}

		//다시 string 형태로 만들어 push_back

		result.push_back((sum % 10) + '0');

		sum /= 10;

	}

	//1의 자리부터 result에 넣었으므로 뒤집어줘야한다

	reverse(result.begin(), result.end());

	return result;

}

string getAn(string num1, string num2) {
	string result;
	long long sum = 0;
	long long numberOne = 0;
	long long numberTwo = 0;

	while (!num1.empty()) {
		numberOne += num1.back() - '0';
		num1.pop_back();
	}
	while (!num2.empty()) {
		numberTwo += num2.back() - '0';
		num2.pop_back();
	}

	sum = numberOne + numberTwo * 2;
	while (!num1.empty() || !num2.empty() || sum) {
		result.push_back(sum % 10 + '0');
		
		sum /= 10;
	}

	return result;
}

int main(void){

	//아무것도 안하는 것도 하나의 방법, 밑변이 1인 사각형(1*2) 한 가지

	cache[0] = cache[1] = '1';

	//밑변이 2인 사각형(2*2, 2*1) 두 가지, 밑변이 1인 사각형(1*2) 한 가지

	for (int i = 2; i <= 250; i++) {
		//cache[i] = bigNumAdd(bigNumAdd(cache[i - 2], cache[i - 2]), cache[i - 1]);
		cache[i] = getAn(cache[i - 1], cache[i - 2]);
	}

	while (~scanf("%d", &N)){
		cout << cache[N] << endl;
	}

	return 0;

}