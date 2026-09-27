#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cout << "Enter the number of elements: "; cin >> n;
    
    vector<int> b(n + 1);
    cout << "Enter the elements: ";
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> p(n + 1, 0);
    vector<int> s(n + 1, 0);
    vector<int> u(n + 1, 0);
    vector<int> max_s(n + 1, 0);

    p[1] = b[1];

    for (int i = 2; i <= n; i++) {
        p[i] = max(b[i], b[i] + p[i - 1]);
        //cout << p[i] << endl;
    }

    s[n] = b[n];
    u[n] = s[n];

    for (int j = n - 1; j >= 1; j--) {
        if (b[j] < b[j + 1]) {
            s[j] = b[j] + s[j + 1];
        } else {
            s[j] = b[j];
        }

        u[j] = max(b[j], s[j]);
        max_s[j] = max(u[j], max_s[j + 1]);
    }

    int answer = 0;

    for (int i = 1; i <= n - 1; i++) {
        int l = p[i] + max_s[i + 1];
        answer = max(answer, l);
    }

    cout << "The maximum sum is: " << answer << endl;

    return 0;
}
