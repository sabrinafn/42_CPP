#include "Replacer.hpp"

Replacer::Replacer(std::string arg1, std::string arg2, std::string arg3) 
: filename(arg1), str_to_find(arg2), new_str(arg3), file_content(""), output_string("") {
}

Replacer::~Replacer() {
}

void    Replacer::readFile() {

    std::ifstream text;
    std::string line;

    //open file and write to string
    text.open(filename.c_str()); // c_str() = converting to const char * to pass argument to open()

    if (!text || !text.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return ;
    }
    
    // read the file line by line to the string file_content
    while (getline(text, line)) {
        file_content += line;
        if (!text.eof()) // Check if we've reached the end of the file
            file_content += '\n';
    }
    text.close();

    if (file_content.empty()) {
        std::cerr << "File is empty." << std::endl;
        return ;
    }
}

int  Replacer::findSubstrPos(int start) const {

    size_t  index;

    // size_t find(const char* s, size_t pos = 0) const;
    //  'find' is used to locate the first occurrence of a substring within a string
    index = file_content.find(str_to_find, start);
    if (index == std::string::npos)
        return -1;
    return ((int)index);
}

void    Replacer::stringReplace() {

    bool    found_and_replaced = false;
    int     found_pos = 0;
    int     current_pos = 0;

    if (file_content.empty())
        return ;
    if (str_to_find.empty())
    {
        std::cerr << "The string to find was empty." << std::endl;
        return;
    }
    while ((found_pos = findSubstrPos(current_pos)) != -1) {
        output_string += file_content.substr(current_pos, found_pos - current_pos);
        output_string += new_str;
        current_pos = found_pos + str_to_find.length();
        found_and_replaced = true;
    }
    output_string += file_content.substr(current_pos);

    if (!found_and_replaced)
        std::cerr << "The string '" << str_to_find << "' was not found in file." << std::endl;
    else
        writeToFile();
}

void    Replacer::writeToFile() {
    
    std::string output_filename = filename + ".replace";
    std::ofstream output_file;
    
    output_file.open(output_filename.c_str());
    if (!output_file || !output_file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }
    else {
        output_file << output_string;
        output_file.close();
    }
}