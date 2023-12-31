#include <iostream>
#include <string.h>
#include "Lexer.h"
#include <vector>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"
#include <fstream>
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

    // std::streamsize ssize = is.tellg();
    is.seekg(0, std::ios::beg);

    std::ostringstream buf;
    buf << is.rdbuf();

    std::string input = buf.str();

    typhp::Lexer lexer = typhp::Lexer((char *)input.c_str(), input.size());
    std::vector<typhp::Token *> tokens = lexer.tokenize();

#ifdef TYPHP_DEBUG
    for (
        auto it = tokens.begin();
        it != tokens.end();
        it++)
    {

        std::cout << (*it)->value << "\t"
                  << " type is " << (*it)->type << "\n";
    }
#endif

    typhp::Parser parser(tokens);
    typhp::ASTNode *root = parser.parse();

    std::cout << "This is the generated php source code:\n"
              << root->generate() << "\n";

    return EXIT_SUCCESS;
}