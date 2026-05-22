#include <iostream>
#include <cstring>
#include "parser.hpp"

bool unique_arguments(const int &arguments_amount, char **arguments) noexcept {
    for (int i = 0; i < arguments_amount; ++i) {
        for (int j = i+1; j < arguments_amount; ++j) {
            if (strcmp(arguments[i], arguments[j]) == 0) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc <= 1 || argc >= 7) { // +1 program arg, +4 options, +1 input file
        std::cout <<
        "Usage: " << argv[0] << " <OPTIONS> <FILE>" <<
        "\n\nOptions:\n" <<
        "-RAW\t\tjust create raw binary\n" <<
        "-OBJ\t\tjust create object file\n" <<
        "-o\t\tspecify output file name\n"
        << std::endl;
        return 0;
    }
    bool raw_bin = false;
    bool raw_object = false;
    std::string output_file = "output.out";
    std::string input_file {};
    

    if (!unique_arguments(argc, argv)) {
        std::cerr << "Error: Cannot be same options\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-RAW") == 0) {
            raw_bin = true;
        }
        else if (strcmp(argv[i], "-OBJ") == 0) {
            raw_object = true;
        }
        else if (strcmp(argv[i], "-o") == 0 && ((i + 1) < argc)) {
            output_file = argv[i+1];
            ++i;
        }
        else {
            input_file = argv[i];
        }
    }
    
    if (parse(input_file, output_file, raw_bin, raw_object) == false) {
        return 1;
    }

}
