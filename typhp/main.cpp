#include <iostream>
#include <string.h>
#include "Lexer.h"
#include <vector>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"
#include "Generator.h"

#define VERSION "1.0.0"

int main(int argc, char *argv[])
{

    char *input = "<?php\n"
                "mixed     $username;\n"
                "function main() {}\n"
                "interface ISome {}\n"
                
                "class Some {"
                "}\n"
                //   "require_once dirname(__DIR__).\"/vendor/autoload.php\";\n"
                //   ""
                //   "function main(int $argc, string[] $argv) {\n"
                //   "return (int) 0;\n"
                //   "}\n"
                //   ""
                //   "?>\n"
                //   "<!doctype html>\n"
                //   "<html>\n"
                //   "<head>\n"
                //   "<title>Web Page</title>\n"
                //   "<meta name=\"content-type\" content=\"text/html\" />\n"
                //   "</head>\n"
                //   "<body>\n"
                //   "<?php echo $content; ?>\n"
                //   "</body></html>\n"
                  "";

    typhp::Lexer lexer = typhp::Lexer(input, strlen(input));
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

    std::cout << "This is the generated php source code:\n"
              << generator.generate() << "\n";

    return 0;
}