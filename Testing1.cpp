#include <iostream>
#include <string>

int main()
{
    std::string s = "C-+";
    char ch = '*';

    s.append(2, ch);
    std::cout << s;

    return 0;
}
