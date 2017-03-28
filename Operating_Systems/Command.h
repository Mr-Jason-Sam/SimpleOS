#ifndef OS_COMMAND_H
#define OS_COMMAND_H

#include <vector>
#include <iostream>

using namespace std;

class Command
{
private:
    vector<char> order;
    vector<char> object;
public:
    Command(vector<char> operaring_command);
    bool execute();
};

#endif // OS_COMMAND_H
