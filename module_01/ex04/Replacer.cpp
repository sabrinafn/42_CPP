#include "Replacer.hpp"

Replacer::Replacer() : filename(""), str_to_find(""), new_str(""), file_content("") {
    std::cout << "Replacer constructor called" << std::endl;
}

Replacer::~Replacer() {
    std::cout << "Replacer destructor called" << std::endl;
}

void    Replacer::storeArguments(std::string arg1, std::string arg2, std::string arg3) {
 
    filename = arg1;
    str_to_find = arg2;
    new_str = arg3;

    std::cout << "filename = " << filename << std::endl;
    std::cout << "string to find = " << str_to_find << std::endl;
    std::cout << "new string = " << new_str << std::endl;
}

void    Replacer::readFileandStore() {


    std::ifstream text;
    //open file and write to string
    text.open(filename.c_str()); // converting to const char * to pass argument to open()

    if (!text.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }
    
    std::string line;
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(text, line)) {
        // Output the text from the file
        file_content += line;
        file_content += '\n';
    }
    std::cout << file_content << std::endl;

    text.close();
}

int  Replacer::findSubstrPos(int start) {

    size_t index;

    index = file_content.find(str_to_find, start);
    if (index == std::string::npos) {
        std::cout << "The string '" << str_to_find << "' was not found in file." << std::endl;
        std::cout << "index returned: " << index << std::endl;
        return -1;
    }
    else
        std::cout << "The string '" << str_to_find << "' was found at position: " << index << std::endl;

    return ((int)index);
}

void    Replacer::stringReplace() {

    //std::string output_filename = filename + ".replace";
    //std::ofstream output_file;
    //output_file.open(output_filename.c_str());
    //if (!output_file.is_open()) {
    //    std::cerr << "Error opening file." << std::endl;
    //    return;
    //}
    std::string output_file;
    int found_pos = 0;
    int current_pos = 0;

    while ((found_pos = findSubstrPos(current_pos)) != -1) {
        output_file += file_content.substr(current_pos, found_pos - current_pos);
        output_file += new_str;
        current_pos = found_pos + str_to_find.length();
    }
    std::cout << std::endl << "=========================================="<< std::endl;
    std::cout << "New file: " << std::endl;
    std::cout << output_file;
    std::cout << std::endl << "=========================================="<< std::endl;
    std::cout << std::endl;
}