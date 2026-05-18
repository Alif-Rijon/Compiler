#include <iostream>

using namespace std;

int main() {
    char input[100];
    cout << "Enter a string: ";
    cin >> input;

    int i = 0;
    bool rejected = false;


    if (input[0] == '\0') {
        rejected = true;
    }

    while (input[i] != '\0') {
        char c = input[i];


        if (c == 'a' || c == 'b') {

        } else {

            rejected = true;
            break;
        }
        i++;
    }

    if (!rejected) {
        cout << ">>> ACCEPTED" << endl;
    } else {
        cout << ">>> REJECTED" << endl;
    }

    return 0;
}
