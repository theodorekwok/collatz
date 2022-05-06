#include <bits/stdc++.h>

using namespace std;

// default numberOne longer than numberTwo
string sumNumber(string numberOne, string numberTwo) {
    if (numberOne.size() < numberTwo.size()) {
        string temp = numberOne;
        numberOne = numberTwo;
        numberTwo = temp;
    }
    string ans;
    int carry = 0;
    int indOne = numberOne.size() - 1;
    int indTwo = numberTwo.size() - 1;
    while (indOne >= 0) {
        int one = numberOne[indOne] - '0';
        int two = 0;
        if (indTwo >= 0) {
            two = numberTwo[indTwo] - '0';
        }
        int add = one + two + carry;
        int digit = (add % 10);
        carry = add / 10;
        ans.push_back(digit + '0');
        indOne--;
        indTwo--;
    }
    if (carry != 0) {
        ans.push_back(carry + '0');
    }   
    reverse(ans.begin(), ans.end());
    return ans;

}

string threeTimesPlusOne(string number) {
    string ans = sumNumber(number, number);
    ans = sumNumber(ans, number);
    ans = sumNumber(ans, "1");
    return ans;
}

string divide(string number, int divisor) {
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx) {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';

        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";

    // else return ans
    return ans;
}

int main() {
    int N;
    cin >> N;
    string startNumber;
    srand(time(0));
    for (int i = 0; i < N; i++) {
        int randomDigit;
        if (i == 0) {
            randomDigit = (rand() % 9) + 1;
        } else {
            randomDigit = (rand() % 9);
        }
        startNumber.push_back(randomDigit + '0');
    }
    // cout << threeTimesPlusOne(startNumber) << '\n';
    // cout << divide(startNumber, 2) << '\n';
    unordered_set<string> storePreviousNumbers;
    while (startNumber != "1") {
        int idxLastDigit = startNumber.size() - 1;
        if (startNumber[idxLastDigit] == '0' ||
            startNumber[idxLastDigit] == '2' ||
            startNumber[idxLastDigit] == '4' ||
            startNumber[idxLastDigit] == '6' ||
            startNumber[idxLastDigit] == '8') {
            startNumber = divide(startNumber, 2);
        } else {
            startNumber = threeTimesPlusOne(startNumber);
        }
        if (storePreviousNumbers.find(startNumber) != storePreviousNumbers.end()) {
            cout << "SHIT FOUND A non COLLATZ NUMBER " << startNumber << '\n';
        } else {
            storePreviousNumbers.insert(startNumber);
        }
        cout << startNumber << '\n';
    }
}
