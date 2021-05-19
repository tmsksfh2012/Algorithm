#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 250 + 1;

int N;

string cache[MAX];


//long long �ڷ������ε� Ŀ�� �ȵǴ� ���ڴ� string���� ���� ����������Ѵ�

string bigNumAdd(string num1, string num2) {

	long long sum = 0;

	string result;

	//1�� �ڸ����� ���ϱ� �����Ѵ�

	while (!num1.empty() || !num2.empty() || sum) {

		if (!num1.empty()) {

			sum += num1.back() - '0';
			num1.pop_back();

		}

		if (!num2.empty()) {

			sum += num2.back() - '0';
			num2.pop_back();
		}

		//�ٽ� string ���·� ����� push_back

		result.push_back((sum % 10) + '0');

		sum /= 10;

	}

	//1�� �ڸ����� result�� �־����Ƿ� ����������Ѵ�

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

	//�ƹ��͵� ���ϴ� �͵� �ϳ��� ���, �غ��� 1�� �簢��(1*2) �� ����

	cache[0] = cache[1] = '1';

	//�غ��� 2�� �簢��(2*2, 2*1) �� ����, �غ��� 1�� �簢��(1*2) �� ����

	for (int i = 2; i <= 250; i++) {
		//cache[i] = bigNumAdd(bigNumAdd(cache[i - 2], cache[i - 2]), cache[i - 1]);
		cache[i] = getAn(cache[i - 1], cache[i - 2]);
	}

	while (~scanf("%d", &N)){
		cout << cache[N] << endl;
	}

	return 0;

}