#include "Replacer.hpp"

Replacer::Replacer(std::string arg1, std::string arg2, std::string arg3) 
: filename(arg1), str_to_find(arg2), new_str(arg3), file_content(""), output_string("") {
}

Replacer::~Replacer() {
}

void    Replacer::readFile() {

    std::ifstream text;
    //open file and write to string
    text.open(filename.c_str()); // converting to const char * to pass argument to open()

    if (!text || !text.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return ;
    }
    
    std::string line;
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(text, line)) {
        // Output the text from the file
        file_content += line;
        file_content += '\n';
    }
    text.close();
}

int  Replacer::findSubstrPos(int start) const {

    size_t  index;

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
        return;

    while ((found_pos = findSubstrPos(current_pos)) != -1) {
        output_string += file_content.substr(current_pos, found_pos - current_pos);
        output_string += new_str;
        current_pos = found_pos + str_to_find.length();
        found_and_replaced = true;
    }
    if (!found_and_replaced)
        std::cout << "The string '" << str_to_find << "' was not found in file." << std::endl;
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