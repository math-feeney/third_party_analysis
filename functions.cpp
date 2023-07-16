// Functions

#include <string>

/*The function below now returns a name that matches the name that 
matches (if it matches)*/


std::string name_match(std::string name_list, std::string name) {

    for (int i = 0; i < name_list.size(); i++) {
        
        if (name_list.substr(i, name.size()) == name) {
            return name;
            break;
        }
    }
    return "";
}
