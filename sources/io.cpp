#include "io.hpp"

auto read_file(std::string& in_file) -> std::string {
    std::ifstream file(in_file);

    if (!file.is_open()) {
        std::cerr << "Cannot read filename: " << in_file << '\n';
        return "";
    }

    std::cout << "Filename: " << in_file << "\n\n";

    std::ostringstream buffer;
    buffer << file.rdbuf();
    std::string out = buffer.str();

    std::cout << "*******************************************************************\n";
    std::cout << out << "\n";
    std::cout << "*******************************************************************\n\n";
    
    return out;
}