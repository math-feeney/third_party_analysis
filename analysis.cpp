/*****************************************************************
 * THIRD PARTY PRIVILEGE LOG ANALYSIS SOUCE CODE
 * AUTHOR: Michael Feeney
 * START DATE:  2023-07-07
 * *****************************************************************
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "analysis.hpp"

int main() {

    char input;

    // This is a test input to begin analysis
    std::cout << "Welcome to the third party privlege analysis\n";
    std::cout << "Run analysis? (y/n)\n";
    std::cin >> input;

    if (input != 'y') {
        std::cout << "Alright then, goodbye";

        return 1;
    }

    /*///////////////////////////////////////////////////////////////
    This section reads in the tp_list as a vector of strings
    - This appears to have worked, consider writing as a function
    *//////////////////////////////////////////////////////////////////
 
    std::vector<std::string> tp_list;
    std::ifstream tp_file;
    std::string tp_name;

    tp_file.open("tp_list.csv", std::ios::in);

    // Check if file is open, or return error
    if(!tp_file.is_open()) {
        std::cout << "Failed to open the third party list." << std::endl;
        return 1;
    }

    // read in tp_list and store as a vector of strings
    while (std::getline(tp_file, tp_name)) {

    // Remove double quotes from the line
    tp_name.erase(std::remove(tp_name.begin(), tp_name.end(), '\"'), tp_name.end());
        
    tp_list.push_back(tp_name);

    }
    
    tp_file.close();

   /*////////////////////////////////////////////////////////////////////

    This section reads through each line of the log, then checks for 
    third party name matches, it then writes a csv file that includes
    any third party names that match 

    *////////////////////////////////////////////////////////////////////

    std::vector<std::string> tp_present;
    std::ifstream priv_file;
    std::string line;
    std::fstream out_file;

    // open output file and priv_log
    out_file.open("text_output.csv", std::ios::out);
    priv_file.open("test_log.csv", std::ios::in);

    // check if priv_log is open or return error
    if(!priv_file.is_open()) {
        std::cout << "Failed to open the privilege log." << std::endl;
        return 1;
    }

    // read each line of priv_log and check for names
    while (std::getline(priv_file, line)) {

        std::string names_in_line = ";";
        
        // loop through the tp_list for each priv_log line 
        for (int i = 0; i < tp_list.size(); i++) {

            // this concatenates all tp matched for a given line in the priv_log
            names_in_line += name_match(line, tp_list[i]) += " "; // Think about how to separate multiple matches
            
        }
        
        tp_present.push_back(names_in_line);

        // this is to output each set of names that match per priv line for testing
        // uncomment for testing
        //std::cout << names_in_line << std::endl;

        // writes each set of matching tp names and adds quotes so excel keeps in one column
        out_file << '\"' << names_in_line << '\"' << std::endl;
    }
    
    // close both files
    priv_file.close();
    out_file.close();
    
    return 0;
} 
