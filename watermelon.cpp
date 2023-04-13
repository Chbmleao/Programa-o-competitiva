#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (x % 2 == 0 && x > 2)
    {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    
    return 0;
}