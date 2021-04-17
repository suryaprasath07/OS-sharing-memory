#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "ls";

    const char *command = str.c_str();

    cout << "Compiling file using " << command << endl;
    system(command);

    return 0;
}