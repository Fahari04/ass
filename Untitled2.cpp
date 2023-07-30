#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


std::vector<int> decimalToBinary(int decimal) {
    std::vector<int> binary;

    while (decimal > 0) {
        binary.push_back(decimal % 2);
        decimal /= 2;
    }

    // Reverse the binary vector
    reverse(binary.begin(), binary.end());

    return binary;
}
int binaryToDecimal(int binary) {
    int decimal = 0;
    int power = 0;

    while (binary != 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * pow(2, power);
        power++;
        binary /= 10;
    }

    return decimal;
}
int main() {
   /* int decimal;

    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;

    std::vector<int> binary = decimalToBinary(decimal);

    std::cout << "Binary representation: ";
    for (int bit : binary) {
        std::cout << bit;
    }
    std::cout << std::endl;

    return 0;*/
    int t;
    std::cin>>t;
    while(t--){
        int n;std::cin>>n;
        std::vector<int> binary = decimalToBinary(n);
        std::reverse(binary.begin(), binary.end());
       int decimal = binaryToDecimal(binary);
        cout<<decimal<<endl;

    }
}

