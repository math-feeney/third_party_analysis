/*****************************************************************
 * THIRD PARTY PRIVILEGE LOG ANALYSIS SOURCE CODE
 * AUTHOR: Michael Feeney
 * START DATE:  2023-07-07
 * *****************************************************************
*/

/*
Dependencies: "libgcc_s_seh-1.dll", "libstdc++-6.dll", "libwinpthread-1.dll"
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include "analysis.hpp"

int main() {


    // set the sub folder that includes the necessary dll files
    SetDllDirectoryA("dll"); // This doesn't seem to do what I want it to do

    char input;

    // This is a test input to begin analysis
    std::cout << "Welcome to the third party privilege analysis\n";
    std::cout << "Please ensure that the file names match the following:\n";
    std::cout << "\nPriv log: 'priv_log.csv'\n";
    std::cout << "Third party list: 'tp_list.csv'\n";
    std::cout << "\nRun analysis? (y/n)\n";
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

    tp_file.open("tp_list.csv", std::ios::in); // Name of tp_list file

    // Check if file is open, or return error
    if(!tp_file.is_open()) {
        std::cout << "Failed to open the third party list." << std::endl;
        std::cout << "\nPlease ensure the third party list is named 'tp_list.csv'\n";
        std::cout << "Enter any character to exit and try again:\n";
        std::cin >> input;
        return 1;
    }

    // read in tp_list and store as a vector of strings
    while (std::getline(tp_file, tp_name)) {

    // Remove double quotes from the line
    tp_name.erase(std::remove(tp_name.begin(), tp_name.end(), '\"'), tp_name.end());

    // change names to lower case    
    tp_list.push_back(to_lower(tp_name));

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
    out_file.open("tp_output.csv", std::ios::out); // name of output file
    priv_file.open("priv_log.csv", std::ios::in); // name of priv log file

    // check if priv_log is open or return error
    if(!priv_file.is_open()) {
        std::cout << "Failed to open the privilege log." << std::endl;
        std::cout << "\nPlease ensure the third party list is named 'priv_log.csv'\n";
        std::cout << "Enter any character to exit and try again:\n";
        std::cin >> input;
        return 1;
    }
    // read each line of priv_log and check for names
    while (std::getline(priv_file, line)) {

        // change to lower case
        line = to_lower(line);

        std::string names_in_line = ""; // default value that any name matches append to
        
        // loop through the tp_list for each priv_log line 
        for (int i = 0; i < tp_list.size(); i++) {

            // this concatenates all tp matched for a given line in the priv_log
            names_in_line += name_match(line, tp_list[i]);
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
