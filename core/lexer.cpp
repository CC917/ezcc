#include <iostream>

#include "lexer.hpp"

std::string Lex::IdentifierStr;

double Lex::NumVal;

/*
* LastChar will always point to next character.
*/
int Lex::getNextToken() {
    static int LastChar = ' ';

    if (isspace(LastChar)) {
        LastChar = getchar();
    }

    // match identifier. make keyword be specical identifier.
    if (std::isalpha(LastChar)) {
        // [a-zA-Z][a-zA-Z0-9]*
        IdentifierStr = LastChar;
        LastChar = getchar();
        while (std::isalnum(LastChar)) {
            IdentifierStr += LastChar;
            LastChar = getchar();
        }
        // find a character not be alpha or number.
        if (IdentifierStr == "def") {
            return tok_def;
        }
        else if (IdentifierStr == "extern") {
            return tok_extern;
        }
        return tok_identifier;
    }

    /*
    * ISO/IEC 9899:1999 (E)
    * The getchar function returns the next character from the input stream pointed to by
    * stdin. If the stream is at end-of-file, the end-of-file indicator for the stream is
    * set and getchar returns EOF. If a read error occurs, the error indicator for the
    * stream is set and getchar returns EOF.
    */
    if (LastChar == EOF) {
        if (errno != 0) {
            std::cout << "exception: err info"
                    << strerror(errno) << std::endl;
        }
        return tok_eof;
    }

    // match numeric values.
    if (isdigit(LastChar)) {
        std::string tmpStr;
        do {
            tmpStr = LastChar;
            // get next character.
            LastChar = getchar();
        } while (std::isdigit(LastChar));
        NumVal = std::strtod(tmpStr.c_str(), 0);
        return tok_number;
    }

    // this mean a normal character. return this and move current pointer.
    int cur_tok = LastChar;
    LastChar = getchar();
    return cur_tok;
}
