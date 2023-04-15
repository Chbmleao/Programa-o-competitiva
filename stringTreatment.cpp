#include <iostream>
#include <string>
using namespace std;
 
int calculateValue(int weight, int i) {
    return weight * i;
}
 
int main(int argc, char const *argv[]) {
    string s;
    int k;
    int weights[26];
 
    cin >> s;
    
    cin >> k;
    int maxWeight = 0;
 
    for (int i = 0; i < 26; i++) {
        cin >> weights[i];
        if(weights[i] > maxWeight)
            maxWeight = weights[i];
    }
 
    int stringSize = s.size();
    int stringValue = 0; 
    
    for (int i = 0; i < stringSize; i++) {
        int charValue = weights[int(s[i]) - 97];
        stringValue += calculateValue(i+1, charValue);
    }
 
    
 
    for (int i = 0; i < k; i++) {
        stringValue += maxWeight * (stringSize+1);
        stringSize++;
    }
    
    cout << stringValue;
 
    
 
    return 0;
}