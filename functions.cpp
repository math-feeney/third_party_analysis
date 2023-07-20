#include <string>

// function definitions////////////////

/*//////////////////////////////////////////////////////////////
The function below returns a name if it matches a name in 
another list (name_list)
*/////////////////////////////////////////////////////////////////

std::string name_match(std::string name_list, std::string name) {

    for (int i = 0; i < name_list.size(); i++) {
        
        if (name_list.substr(i, name.size()) == name) {
            name += "; "; // this is what separates the matched names in the output
            return name;
            break;
        }
    }
    return "";
}

/*///////////////////////////////////////////////////////////////////////////////////////////
This function searches through a string and changes any upper case characters to lower case
*////////////////////////////////////////////////////////////////////////////////////////////

std::string to_lower(std::string name) {
    for (int i = 0; i < name.size(); i++) {

            // this top conditional handles ASCII
            if ((name[i] > 64) && (name[i] < 91)) {
                name[i] += 32;
            }
            // this conditional handles extended ASCII (UTF-8)
            else if ((name[i] > 191) && (name[i] < 223)) {
                name[i] += 34;
            }
        
    }
    return name;
}
