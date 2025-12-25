#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HighestAltitude {
public:
    int findMaxAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int maxAltitude = 0;

        for (int i = 0; i < gain.size(); i++) {
            currentAltitude += gain[i];
            maxAltitude = max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
};

int main() {
    HighestAltitude h;
    vector<int> gain = {-5, 3, 2, 5}; // Altitude gains

    int result = h.findMaxAltitude(gain);
    cout << "Max altitude: " << result << endl;

    return 0;
}