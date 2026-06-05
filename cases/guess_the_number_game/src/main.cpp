#include <iostream>
#include <random>

using namespace std;


int main() {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    int guess_number;
    while (true) {
        int random_number = dis(gen);
        cout << "GUESS THE NUMBER GAME PLAY" << endl;
        cout << endl;

        cout << "Input your guess number: ";
        cin >> guess_number;

        if (guess_number == random_number) {
            cout << "Congratulations" << endl;
            cout << endl;
            break;
        } else {
            if (guess_number > random_number) {
                cout << "Was too higth with the guess" << endl;
            } else {
                cout << "Wait too lower with the guess" << endl;
            }
            cout << endl;
            continue;
        }

    }

    return 0;
}
