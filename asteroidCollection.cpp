#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;

    for (int ast : asteroids) {
      while (!result.empty() && result.back() > 0 && ast < 0) {
        if (result.back() < -ast) {
          result.pop_back();
          continue;
        }
        else if (result.back() == -ast) {
          result.pop_back();
        }
        ast = 0;
        break;
      }

      // If current asteroid survived, add it to result
      if (ast != 0) {
        result.push_back(ast);
      }
    }

    return result;
  }
};

int main() {
  Solution s;

  // Test cases
  vector<int> test1 = {5, 10, -5};
  vector<int> result1 = s.asteroidCollision(test1);
  cout << "Test 1 [5, 10, -5]: ";
  for (int num : result1) cout << num << " ";
  cout << endl;


  return 0;
}