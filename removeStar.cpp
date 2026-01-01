//
// Created by Aung Naing Thu on 12/28/2025.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string result;
    string removeStar(string s) {
      string result;
      for (char c : s)
      {
        if (c == '*')
        {
          if (!result.empty())
          {
            result.pop_back();
          }
        }
        else
        {
          result.push_back(c);
        }
      }
      return result;
    }
};


int main() {
  Solution s;
  string str = "hel*lo*to**theStar*";
  cout << "The original String = " << str << endl;

  cout << "The string after removing one char at every one star found = ";
  string result = s.removeStar(str);
  cout << result << endl;

}