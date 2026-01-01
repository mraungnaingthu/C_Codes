#include <iostream>
#include <queue>
using namespace std;

class RecentCallLog {
public:
    virtual int ping(int t) = 0;
    virtual ~RecentCallLog() {}
};

class SimpleRecentCounter : public RecentCallLog {
private:
    queue<int> requests;

public:
    int ping(int t) override {
        requests.push(t);

        printQueue("Total requests: ");

        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }
        printQueue("Filtering out the requests within 3000ms: ");


        return requests.size();
    }

    ~SimpleRecentCounter() override {
        // Queue automatically cleans up
    }

    void printQueue(const string& message) const
    {
        cout << message << ": ";
        if (requests.empty())
        {
            cout << "Empty queue." << endl;
        }

        queue<int> temp = requests;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    RecentCallLog* logger = new SimpleRecentCounter();

    for (int i = 1; i <= 40000; i *= 20) {
        int result = logger->ping(i);
        cout << endl;
    }

    delete logger;


    return 0;
}