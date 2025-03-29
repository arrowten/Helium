#include "io.hpp"

auto read_file(std::string& input_file) -> std::string {
    std::ifstream file(input_file);

    if (!file.is_open()) {
        std::cerr << "Cannot read filename: " << input_file << '\n';
        
        return "";
    }

    std::cout << "\nFilename: " << input_file << "\n\n";
    std::ostringstream buffer;
    buffer << file.rdbuf();
    std::string output = buffer.str();
    std::cout << "*******************************************************************\n";
    std::cout << output << "\n";
    std::cout << "*******************************************************************\n";
    
    return output;
}