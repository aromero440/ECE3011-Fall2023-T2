#include <iostream>
#include "globals.h"
#include "genProblem.h"

using namespace std;

void testGenProblem() {
    cout << "Kindergarden: \n";
    for (int i = 0; i < 5; i++) {
        cout << (probToString(generateProblem(Kindergarden)));
        cout << "\n";
    }
    cout << "\n";

    cout << "First: \n";
    for (int i = 0; i < 5; i++) {
        cout << (probToString(generateProblem(First)));
        cout << "\n";
    }
    cout << "\n";

    cout << "Second: \n";
    for (int i = 0; i < 5; i++) {
        cout << (probToString(generateProblem(Second)));
        cout << "\n";
    }
    cout << "\n";

    cout << "Third: \n";
    for (int i = 0; i < 5; i++) {
        cout << (probToString(generateProblem(Third)));
        cout << "\n";
    }
    cout << "\n";
}