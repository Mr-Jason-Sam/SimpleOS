#include "Command.h"

Command:: Command(vector<char> operaring_command)
{
    for (auto it = operaring_command.begin(); it != operaring_command.end(); it ++) {
            char character = *it;
            if(character == ' '){
                //object.assign(it+1, operaring_command.end());
                character = *(++it);
                object.push_back(character);
                //break;
            }else{
                order.push_back(character);
            }
        }
}

bool Command::execute(){

}
