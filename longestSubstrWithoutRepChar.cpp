#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;

    int size = s.length();

    string subs = "";
    int max = 0;

    for (size_t i = 0; i < size; i++) {
        int indexToErase = subs.find(s[i]);
        if(indexToErase != -1) {
            if(subs.length() > max)
                max = subs.length();
            subs.erase(0, indexToErase+1);
        }

        subs.push_back(s[i]);
    }

    cout << (max > subs.length() ? max : subs.length());

    return 0;
}
