#include <iostream>
#include <string.h>
#include "Lexer.h"
#include <vector>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"
#include "Generator.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>

#define VERSION "1.0.0"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return EXIT_FAILURE;
    }

    std::string source_file(argv[1]);
    std::ifstream is(source_file, std::ios::binary | std::ios::ate);
    if (!is.is_open())
    {
        std::cout << "Failed to open source file\n";

        return EXIT_FAILURE;
    }

    std::streamsize ssize = is.tellg();
    is.seekg(0, std::ios::beg);

    std::ostringstream buf;
    buf << is.rdbuf();

    std::string input = buf.str();

    typhp::Lexer lexer = typhp::Lexer((char *)input.c_str(), input.size());
    std::vector<typhp::Token *> tokens = lexer.tokenize();

    for (
        auto it = tokens.begin();
        it != tokens.end();
        it++)
    {

        std::cout << (*it)->value << "\t"
                  << " type is " << (*it)->type << "\n";
    }

    typhp::Parser parser(tokens);
    typhp::ASTNode *global_scope = parser.parse();
    typhp::Generator generator(global_scope);

    std::string generated = generator.generate();

    std::cout << "This is the generated php source code:\n"
              << generated << "\n";

    return EXIT_SUCCESS;
}