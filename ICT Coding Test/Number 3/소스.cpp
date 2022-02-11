#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

void superStack(vector <string> operations) {

    int k{};
    for (auto str : operations) {
        stringstream strin(str);

        int n = operations.size();

        vector<int> a(n), b(n);

        string oper;
        strin >> oper;
        if (oper == "push") {
            int x;
            strin >> x;
            a[k++] = x;
        }
        if (oper == "pop") {
            if (--k)
                b[k - 1] += b[k];
            b[k] = 0;
        }
        if (oper == "inc") {
            int x, y;
            strin >> x >> y;
            b[x - 1] += y;
        }

        if (not k) {
            cout << "EMPTY";
        }
        else {
            cout << a[k - 1] + b[k - 1];
        }
        cout << "\n";
    }
}

int main() {
    vector<string> operations = 
    { "push 4", "pop", "push 3", "push 5", "push 2", "inc 3 1", "pop", "push 1", "inc 2 2", "push 4", "pop", "pop" };
    superStack(operations);
    return 0;
}