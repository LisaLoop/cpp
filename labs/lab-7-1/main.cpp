#include <iostream>

using namespace std;


int main() {
    
    int input[INPUT_ARRAY_SIZE];
    int count = 0;
    std::cout << "Please enter exactly 50 integers." << endl;
    while(count < INPUT_ARRAY_SIZE)
    {
        std::cin >> input[count];
        count++;
    }
    int i;
    for(i=0; i<INPUT_ARRAY_SIZE; i++)
    {
        std::cout << input[i] << ' ';
    }
    
    return 0;
}
