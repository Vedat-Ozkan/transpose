#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Key {
  string key;
  vector<string> enharms;
  bool operator==(Key const k) {
    if (k.key == key || find(enharms.begin(), enharms.end(), k.key) != enharms.end()) {
      return true;
    }
    return false;
  }

  bool operator==(string const sym) {
    if (sym == key || find(enharms.begin(), enharms.end(), sym) != enharms.end()) {
      return true;
    }
    return false;
  }

};

struct Keys {
  vector<Key> TTET = {
    Key{"A", {"G##, Bbb"}}, Key{"Bb", {"A#, Cbb"}}, Key{"B", {"A##, Cb"}},
    Key{"C", {"B#, Dbb"}}, Key{"C#", {"B##, Db"}}, Key{"D", {"C##, Ebb"}},
    Key{"Eb", {"D#, Fbb"}}, Key{"E", {"D##, Fb"}}, Key{"F", {"E#, Gbb"}},
    Key{"F#", {"E##, Gb"}}, Key{"G", {"F##, Abb"}}, Key{"Ab", {"G#, Bbb"}}
  };

  int difference(Key k, Key l) {
    int count = 0;
    for (auto i : TTET) {
      if (k == i) {
        break;
      }
      count++;
    }
    for (auto i : TTET) {
      if (l == i) {
        break;
      }
      count--;
    }
    return count < 0 ? -1 * count : count;
  }

  Key find(string symbol) {
    for (auto i : TTET) {
      if (i == symbol) {
        return i;
      }
    }
    return Key{};
  }

  Key transpose(Key k, int factor) {
    int count = 0;
    for (auto i : TTET) {
      if (k == i) {
        break;
      }
      count++;
    }
    count += factor;
    if (count > 11) {
      count -= 12;
    }
    return TTET[count];
  }
};