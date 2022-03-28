#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

// function to read in data
std::vector<std::vector<std::string>> readData(std::string fname) {

    // declare variables
    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;

    // read in file
    std::fstream file(fname, std::ios::in);

    // if the file opened successfully
    if(file.is_open()) {

        // skip header row
        getline(file, line);

        // while there is still data to be read in
        while(getline(file, line)) {

            // clear the row vector
            row.clear();

            // read in a line
            std::stringstream str(line);

            // parse the line
            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            // add the data to the vector
            content.push_back(row);
        }
    }

    // print an error message if the file could not be opened
    else {
        printf("Could not open file\n");
    }

    // return the content that has been read in
    return content;
}

// function to print the keys and values in a map
void printMap(FILE *fp, std::map<std::string, int> myMap) {

    // print each key and value in the map
    for (auto x: myMap) {
        fprintf(fp, "%s %i\n", x.first.c_str(), x.second);
    }
}

