#include "header.h"
#include "Pawn.h"

int main() {

    vector<int> nums = { 2, 9, 29, 72 };

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    
    Pawn one;

    one.symbol = "P";

    cout << one.symbol;

    return 0;
}
