#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int numTests;
    cin >> numTests;

    for (int i = 0; i < numTests; i++) {
        int n;
        cin >> n;

        int arr[n];
        int operation[n-1];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            if(j < n-1)
                operation[j] = 0;
        }

        operation[0] = -1;
        operation[n-2] = 1;

        int isImpossible = false;
        
        if(n == 1) {
            isImpossible = false;
        } else if (n == 2) {
            if(arr[0] > arr[1])
                isImpossible = true;
        } else {
            int current, previous;
            
            for (int j = 1; j < n-1; j++) {
                previous = arr[j-1];
                current = arr[j];

                if(current < previous) {
                    if(j+1 < n)
                        operation[j] = 1;
                    else if (j-2 >= 0) {
                        if(operation[j-2] == 1)
                            isImpossible = true;
                        else
                            operation[j-2] = -1;
                    } else {
                        isImpossible = true;
                    }
                }
            }
        }

        cout << (isImpossible ? "NO" : "YES") << endl;

    }
    
    


    return 0;
}
