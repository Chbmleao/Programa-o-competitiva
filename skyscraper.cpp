#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    long long int floors[n];
    long long int ans[n];
    long long int sumAns = 0;
    long long int bestAns[n];
    long long int bestSum = 0;
    long long int minor;

    for (int i = 0; i < n; i++) {
        cin >> floors[i];
        bestAns[i] = floors[i];
    }


    if(n > 2) {
        for (int i = 0; i < n; i++) {
            ans[i] = floors[i];
            sumAns = ans[i];
            minor = ans[i];
            for (int j = i+1; j < n; j++) {
                if (floors[j] > minor) {
                    ans[j] = minor;
                } else {
                    ans[j] = floors[j];
                }
                sumAns += ans[j];
                minor = ans[j];
            }

            minor = ans[i];
            for (int j = i-1; j >= 0; j--) {
                if (floors[j] > minor) {
                    ans[j] = minor;
                } else {
                    ans[j] = floors[j];
                }
                minor = ans[j];
                sumAns += ans[j];
            }

            if(sumAns > bestSum) {
                bestSum = sumAns;
                for (int j = 0; j < n; j++) {
                    bestAns[j] = ans[j];
                }
            }

            // cout << "center: " << floors[i] << " sum: "<< sumAns<<  endl;
            // for (int j = 0; j < n; j++)
            // {
            //     cout << ans[j] << " ";
            // }
            // cout << endl << endl;
            
            
        }
    }

    for (int i = 0; i < n; i++) {
        cout << bestAns[i] << " ";
    }
    
    return 0;
}
