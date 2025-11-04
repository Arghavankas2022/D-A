//Algorithm for finding max number of line segments intersecting 
// either using two lists or using one list with all the event points labelled
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Using two lists in parallel
int max_intersect_segment(vector<int> S, vector<int> E) {
    sort(S.begin(), S.end());
    sort(E.begin(), E.end());

    int n = S.size();
    int counter = 0;
    int max_overlap = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (S[i] < E[j]) {
            ++counter;
            max_overlap = max(max_overlap, counter); 
            ++i;
        } else {
            --counter;
            ++j;
        }
    }

    return max_overlap;
}

// Using a single list of events
int max_intersect_segment_alt(const vector<int>& S, const vector<int>& E) {
    vector<pair<int,int>> events;
    int n = S.size();

    for (int i = 0; i < n; ++i) { 
        events.push_back({S[i], +1}); // start point
        events.push_back({E[i], -1}); // end point
    }

    // Sort by coordinate, if equal end point first
    sort(events.begin(), events.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    int counter = 0;
    int max_overlap = 0;

    for (auto &e : events) {
        counter += e.second;
        max_overlap = max(max_overlap, counter);
    }

    return max_overlap;
}

int main() {
    vector<int> S = {1, 2, 9, 5, 5};
    vector<int> E = {4, 5, 12, 9, 12};

    cout << "Max overlap (two lists): " << max_intersect_segment(S, E) << endl;
    cout << "Max overlap (event points): " << max_intersect_segment_alt(S, E) << endl;
}

