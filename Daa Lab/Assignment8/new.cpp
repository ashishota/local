#include <bits/stdc++.h>
#include <cmath> // for pow function

using namespace std;

bool checkArmstrong(int n) {
    int count_digit = 0;
    int q = n;
    while(q > 0){
        count_digit++;
        q /= 10;
    }
    long long num = 0; // Changed to long long
    int rem = 0;
    q = n;
    while(q > 0){
        rem = q % 10;
        int power = 1;
        for (int i = 1; i <= count_digit; i++) {
            power *= rem;
        }
        num += power;
        q /= 10;
    }


    cout << "Sum: " << num << endl; // Print the sum of powers
    return num == n;
}

int main() {
    if(checkArmstrong(153))
        cout << "true";
    else
        cout << "false";

    return 0;
}
