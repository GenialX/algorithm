#include <iostream>

using namespace std;

int main() {
    char c = 'a';
    c = (c - 'a') >= 0 ? toupper(c) : c ;
    cout<<c<<endl;
    return 0;
}

