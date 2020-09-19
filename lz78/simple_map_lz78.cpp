#include <iostream>
#include <map>
#include <string>

using namespace std;

void compress();
void decompress();

int main() {
    decompress();
    return 0;
}

void compress() {
    map<string, int> trie;
    int count = 0;
    
    string now = "";
    int prev = 0;
    trie[now] = count++;

    char c;
    while (cin.get(c)) {
        now += to_string(c);
        auto it = trie.find(now);
        if (it == trie.end()) {
            cout << prev << "\t" << c << "\t" << count << endl;
            trie[now] = count ++;
            now = "", prev = 0;
        } else {
            prev = it->second;
        }
    }
}

void decompress() {
    map<int, string> trie;
    trie[0] = "";

    int prev, now;
    string c;
    while (cin >> prev >> c >> now) {
        string str = trie[prev] + c;
        trie[now] = str;
        cout << str;
    }

    cout << endl;
}