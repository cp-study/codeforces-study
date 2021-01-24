#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>
#include <cstdlib>
#include <list>
#include <iomanip>
#define ll long long
using namespace std;



int main() {
    int T;

    cin >> T;

    for (int t = 0; t < T; t++) {

        string str;
        cin >> str;

        vector<pair<char, char>> alphSet(26, { '.','.' });
        int keyPos[26];
        for (int i = 0; i < 26; i++) {
            keyPos[i] = -1;
        }
        string ans;
        bool isPossible = true;
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (i==0) {
                ans.push_back(c);
                keyPos[c - 'a'] = ans.size() - 1;
            }
            else {
                char lastChar = str[i-1];
                if (alphSet[lastChar - 'a'].first == '.' && keyPos[c-'a'] == -1) {
                    if (alphSet[c - 'a'].second != '.') {
                        isPossible = false;
                    }
                    ans.insert(ans.begin() + keyPos[lastChar - 'a'],
                        c);
                    for (int i = 0; i < 26; i++) {
                        if (keyPos[i] >= keyPos[lastChar - 'a']) {
                            keyPos[i]++;
                        }
                    }
                    keyPos[c - 'a'] = keyPos[lastChar - 'a'] - 1;
                    alphSet[c - 'a'].second = lastChar;
                    alphSet[lastChar - 'a'].first = c;

                }
                else if (alphSet[lastChar - 'a'].second == '.' && keyPos[c - 'a'] == -1) {
                    if (alphSet[c - 'a'].second != '.') {
  
                        isPossible = false;
                    }

                    ans.insert(ans.begin() + keyPos[lastChar - 'a']+1,
                        c);
                    for (int i = 0; i < 26; i++) {
                        if (keyPos[i] > keyPos[lastChar - 'a']) {
                            keyPos[i]++;
                        }
                    }
                    keyPos[c - 'a'] = keyPos[lastChar - 'a'] + 1;
                    alphSet[c - 'a'].first = lastChar;
                    alphSet[lastChar - 'a'].second = c;
                }
                else {
                    if (!(alphSet[lastChar - 'a'].first == c ||
                        alphSet[lastChar - 'a'].second == c)) {
                        isPossible = false;
                    } 
                }
            }
        }
       
        if (isPossible) {
            for (int i = 0; i < 26; i++) {
                if (keyPos[i] == -1) {
                    ans.push_back(i + 'a');
                }
            }
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}