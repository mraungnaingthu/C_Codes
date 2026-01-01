#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string decodeSingleLevel(const string& s) {
        string result = "";
        int i = 0;

        while (i < s.length()) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                if (i < s.length() && s[i] == '[') {
                    i++;

                    string insideStr = "";
                    while (i < s.length() && s[i] != ']') {
                        insideStr += s[i];
                        i++;
                    }

                    i++;

                    for (int j = 0; j < num; j++) {
                        result += insideStr;
                    }
                }
            }
            else {
                result += s[i];
                i++;
            }
        }

        return result;
    }

public:
    void decode(const string& str) {
        if (str.empty()) {
            cout << "Empty string" << endl;
        } else {
            string decoded = decodeSingleLevel(str);
            cout << "Input: " << str << endl;
            cout << "Output: " << decoded << endl;
            cout << endl;
        }
    }
};

int main() {
    Solution s;

    string tests[] = {
        "2[a]3[c]e",       // "aacccce"
        "10[a]",           // "aaaaaaaaaa"
        "abc",             // "abc"
        "2[ab]3[cd]",      // "ababcdcdcd"
    };

    for (const auto& test : tests) {
        s.decode(test);
    }

    return 0;
}