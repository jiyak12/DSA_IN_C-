//asteroids collision problem
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;  // Stack to simulate collisions

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                // Right-moving asteroid; push to stack
                st.push_back(asteroids[i]);
            } else {
                // Left-moving asteroid; handle collisions
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back();  // Right-moving asteroid gets destroyed
                }
                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    // Both asteroids are the same size; destroy both
                    st.pop_back();
                } else if (st.empty() || st.back() < 0) {
                    // No right-moving asteroid to collide with
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = sol.asteroidCollision(asteroids);

    // Print result
    cout << "Remaining asteroids after collisions: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
