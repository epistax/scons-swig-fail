
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

// Expecting argv[0] -o "lua_interop_wrap.cc" -Wextra -Werror -c++ -w312 "lua_interop.i" as a command line.
// If your version of SCons is producing a different command line, then the output_file_name variable initialization below may need to change.
int main(int argc, char* argv[])
{
    if (argc != 8)
    {
        std::cerr << "Didn't get the expected command line. See source code in " << __FILE__ << "." << std::endl;
        return 1;
    }
    std::string input_file_name("class_header.h");
    std::string output_file_name(argv[2]);
    std::ofstream output_file{output_file_name};
    output_file << "// This part is always written" << std::endl;
    output_file << "#include <iostream>" << std::endl;
    output_file << "int main(int, char **) {" << std::endl;

    {
        std::ifstream input_file{input_file_name};
        std::string line;
        const std::string PRIVATE{"private:"};
        while (std::getline(input_file, line))
        {
            assert(line.find(PRIVATE) == std::string::npos);
        }
    }

    {
        output_file << "\t// The rest is only written on success" << std::endl;
        output_file << "\tstd::cout << \"Hello World!\" << std::endl;" << std::endl;
        output_file << "\treturn 0;" << std::endl << "}" << std::endl << std::endl;
    }
    
    return 0;
}
