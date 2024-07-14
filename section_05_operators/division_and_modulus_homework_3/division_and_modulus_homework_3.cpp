#include <iostream>
using namespace std;

void problem_1()
{
    // 100 or 7?
    int num;
    cin >> num;
    
    int isEven = num % 2 == 0;
    int isOdd = (1 - isEven);
    int result = isEven * 100 + isOdd * 7;
    cout << result;
}

