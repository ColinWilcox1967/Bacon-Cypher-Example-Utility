#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Baconian cipher mapping (A-Z)
string baconMap[26] = {
    "AAAAA", "AAAAB", "AAABA", "AAABB", "AABAA",
    "AABAB", "AABBA", "AABBB", "ABAAA", "ABAAB",
    "ABABA", "ABABB", "ABBAA", "ABBAB", "ABBBA",
    "ABBBB", "BAAAA", "BAAAB", "BAABA", "BAABB",
    "BABAA", "BABAB", "BABBA", "BABBB", "BBAAA",
    "BBAAB"
};

// Encode function
string encodeBacon(string text) {
    string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            result += baconMap[c - 'A'] + " ";
        } else {
            result += c; // keep spaces/punctuation
        }
    }

    return result;
}

// Decode function
string decodeBacon(string text) {
    string result = "";
    string buffer = "";

    for (char c : text) {
        if (c == 'A' || c == 'B') {
            buffer += c;

            // When we have 5 characters, decode
            if (buffer.length() == 5) {
                bool found = false;
                for (int i = 0; i < 26; i++) {
                    if (baconMap[i] == buffer) {
                        result += char('A' + i);
                        found = true;
                        break;
                    }
                }
                if (!found) result += '?'; // unknown pattern
                buffer = "";
            }
        } else if (isspace(c)) {
            // Keep spacing between words
            if (!buffer.empty()) {
                result += '?';
                buffer = "";
            }
            result += ' ';
        }
    }

    return result;
}

int main() {
    int choice;
    string input;

    cout << "Baconian Cipher\n";
    cout << "1. Encode\n2. Decode\nChoose option: ";
    cin >> choice;
    cin.ignore(); // clear newline

    cout << "Enter text: ";
    getline(cin, input);

    if (choice == 1) {
        cout << "\nEncoded:\n" << encodeBacon(input) << endl;
    } else if (choice == 2) {
        cout << "\nDecoded:\n" << decodeBacon(input) << endl;
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
