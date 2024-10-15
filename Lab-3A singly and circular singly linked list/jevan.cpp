#include <iostream>
using namespace std;

int correctInput(int faultyInput) {
    int correctedInput = 0;  // To store the corrected number
    int multiplier = 1;      // To help in constructing the number
    bool previousNine = false;  // To track if the previous digit was '9'

    while (faultyInput > 0) {
        int digit = faultyInput % 10;  // Get the last digit
        faultyInput /= 10;  // Remove the last digit from the number

        if (digit == 0 && previousNine) {
            // If current digit is '0' and previous digit was '9', skip this '0'
            previousNine = false;  // Reset the flag after skipping '0'
            continue;
        }

        // Add the digit to the corrected number
        correctedInput = correctedInput + (digit * multiplier);
        multiplier *= 10;  // Move to the next digit place

        // Check if the current digit is '9'
        if (digit == 9) {
            previousNine = true;  // Set the flag if the current digit is '9'
        } else {
            previousNine = false;  // Reset the flag if the current digit is not '9'
        }
    }

    return correctedInput;
}

int main() {
    int faultyInput;
    cout << "Enter the number: ";
    cin >> faultyInput;

    int correctedNumber = correctInput(faultyInput);

    cout << "Corrected number is: " << correctedNumber << endl;

    return 0;
}
