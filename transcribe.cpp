#include <iostream>
#include <sstream>
#include "keys.cpp"

using namespace std;

int main (int argc, char *argv[]) {
  Keys keys{};
  string key = "Bb";
  string word;
  stringstream ss;

  while (getline(cin, word)) {
    ss.str(word);
    while (ss >> word) {
      if ('A' <= word[0] && word[0] <= 'G') {
        string t = "";
        bool chordDone = false;
        for (auto c : word) {
          if (chordDone) {
            cout << c;
          } else if (('A' <= c && c <= 'G') || c == 'b' || c == '#') {
            t += c;
          } else {
            Key key = keys.find(t);
            key = keys.transpose(key, 2);
            cout << key.key;
            cout << c;
            chordDone = true;
          }
        }
      } else {
        for (auto c : word) {
          if (32 <= c <= 136) {
            cout << c;
          }
        }
      }
    }
    cout << endl;
    ss.clear();
  }
  
}
