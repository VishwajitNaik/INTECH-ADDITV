#include <stdio.h>
#include <string.h>

void removeOneDigit(char number[]) {
    int n = strlen(number);

    for (int i = 0; i < n - 1; i++) {
        // If the current digit is smaller than the next digit, remove it
        if (number[i] < number[i + 1]) {
            // Move all digits after the removed digit one position left
            for (int j = i; j < n - 1; j++) {
                number[j] = number[j + 1];
            }
            // Set the last digit to null character to shorten the string
            number[n - 1] = '\0';
            return;  // Stop after removing one digit
        }
    }

    // If no removal occurred, remove the last digit
    number[n - 1] = '\0';
}

int main() {
    char number[] = "9273";
    
    printf("Original number: %s\n", number);
    
    removeOneDigit(number);
    
    printf("Largest number after removing one digit: %s\n", number);

    return 0;
}
