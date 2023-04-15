#include <iostream>
#include <string>
using namespace std;
 
int main(int argc, char const *argv[]) {
    int n;
    int x;
 
    cin >> n;
    cin >> x;
 
    int start, end;
    int currentMinute = 0;
    int minutesWatched = 0;
 
    for (int i = 0; i < n; i++) {
        cin >> start;
        cin >> end;
 
        while(currentMinute < end) {
            if(start > currentMinute + x)
                currentMinute += x;
            else {
                minutesWatched += end - currentMinute;
                currentMinute = end;
            }
        }
    }
    
    cout << minutesWatched;
 
    return 0;
}