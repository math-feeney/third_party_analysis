#include <iostream>
#include <string>

/*function that loops through a name_list string and 
checks for a match to name, if there is then it prints
that name*/


void name_match(std::string name_list, std::string name) {

    for (int i = 0; i < name_list.size(); i++) {

        if (name_list.substr(i, name.size()) == name) {
            std::cout << "There is a match!:\n";
            std::cout << name_list.substr(i, name.size()) << "\n";
            break;

        }

    }

}
