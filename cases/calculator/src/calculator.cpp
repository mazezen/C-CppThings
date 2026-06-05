#include <iostream>

using namespace std;

int main() {

    double num1, num2, result;
    char op;

    cout << "Enter 1st number: ";
    cin >> num1;
    
    cout << "Choose a operation + - * /: ";
    cin >> op;

    cout << "Enter 2st number: ";
    cin >> num2;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Divsion it not possible with 0";
                break;
            }
            result = num1 / num2;
            break;
    }

    cout << "result = " << result << endl;

    return 0;
}
