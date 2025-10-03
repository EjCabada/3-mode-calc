#include "History.h"

using namespace std;

History::History() {}

void History::add(string s, string answer) {
    pair<string, string> p = {s, answer};
    if (history_table.size() == 10) {
        history_table.pop();
    }
    history_table.push(p);
}

void History::clear() {
    while (history_table.size() != 0) {
        history_table.pop();
    }
}

void History::print() {
    if (history_table.size() == 0) {
        cout << "No history available" << endl;
        return;
    }

    cout << "in print h.size: " << history_table.size() << endl;
    queue<pair<string, string>> q = history_table;
    cout << "q size = " << q.size() << endl;
    int i = 1;
    while (!q.empty()) {
        cout << i << ": " << q.front().first << " = " << q.front().second << endl;
        q.pop();
        i++;
    }
}
