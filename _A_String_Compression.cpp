#include <iostream>
#include <string>
using namespace std;

string compress(const string& s) {
    int num = s.length(); // calculating length of the string
    string compressed;

    int i = 0;
    while (i < num) {
        // Counting the repetitions of each character
        int repetition = 1;
        while (s[i] == s[i + 1] && i < num - 1) {
            repetition++;
            i++;
        }

        // Append character and its count to the compressed string (skip if count is 1)
        if (repetition > 1) {
            compressed += s[i] + to_string(repetition);
        } else {
            compressed += s[i];
        }

        i++;
    }

    return compressed;
}

int main() {
    string str = "aabbcddddd";
    string compressedStr = compress(str);
    cout << compressedStr << endl;

    // Bonus 1: Compress further
    string compressedStr2 = compress(compressedStr);
    cout << compressedStr2 << endl;

    // Bonus 2: Decompress
    // Decompress the second compressed string
    string decompressedStr = "";
    int index = 0;
    while (index < compressedStr2.length()) {
        char c = compressedStr2[index++];
        string countStr = "";
        while (index < compressedStr2.length() && isdigit(compressedStr2[index])) {
            countStr += compressedStr2[index++];
        }
        int count = (countStr.empty()) ? 1 : stoi(countStr);
        decompressedStr += string(count, c);
    }

    cout << decompressedStr << endl;

    return 0;
}
