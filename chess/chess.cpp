#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myFavoriteNumbers = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < myFavoriteNumbers.size(); i++) {
        cout << myFavoriteNumbers[i] << endl;
    }

    cout << "This is a test" << endl;

    return 0;
}