#include "io.hpp"
#include "helium.hpp"

auto main(int argc, char* argv[]) -> int {
    if(argc < 2) {
		std::cout << "Please specify a file with the executable to read..\n";
		std::cout << "For example: <executable-name> <filename>\n";

		return 1;
	}

	std::string filename = argv[1];
	std::string contents = read_file(filename);
	helium_compile(contents);
    
	return 0;
}