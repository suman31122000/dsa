#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function declaration
void test(int temp);

int main()
{
    int temp = 100;
    test(temp);
    cout << "hello world" << endl; // Fixed typo in output text
}

void test(int temp) {
    cout << temp << endl;
}
