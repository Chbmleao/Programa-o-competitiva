#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    string aux;
    int x;
    vector<int> stack;
    set<int> orderedStack;
    int current = 1;
    int numSort = 0;

    for (int i = 0; i < 2*n; i++) {
        cin >> aux;
        if(aux == "add") {
            cin >> x;
            stack.push_back(x);
        } else {
            if(!stack.empty() && stack.back() == current) {
                stack.pop_back();
                current++;
            } else if (!stack.empty()) {
                for (int i = 0; i < stack.size(); i++) {
                    orderedStack.insert(stack[i]);
                }
                stack.clear();
                orderedStack.erase(current);
                current++;
                numSort++;
            } else {
                orderedStack.erase(current);
                current++;
            }       
        }
    }
    
    cout << numSort;

    return 0;
}
