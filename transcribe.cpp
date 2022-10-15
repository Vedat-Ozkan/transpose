#include <iostream>
#include "keys.cpp"

using namespace std;

int main (int argc, char *argv[]) {

  Keys keys{};

  string key = "Bb";

  string word;

  while (cin >> word) {
    cout << word << endl;
    // if ('A' <= word[0] && word[0] <= 'G') {
    //   Key key = keys.find(word.substr(0, 1));
    //   key = keys.transpose(key, 2);
    //   cout << key.key << endl;
    // }
  }
}
