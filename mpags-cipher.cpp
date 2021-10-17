#include <ctype.h>

#include <iostream>
#include <string>

int main() {
    // string to store output cipher
    std::string out = "";

    // Loop over all input characters
    while (true) {
        // read input
        char c;
        std::cin >> c;
        if (std::cin.eof()){ 
            break;
        }
        //
        // If letter, make sure it is upper case
        if (isalpha(c)) {
            if (isupper(c)) { // is upper case
                out += c;
            } else { // is lower case
                c = toupper(c);
                out += c;
            }
        }

        // If number, convert to letters
        else if (isdigit(c)) {
            switch(c) {
                case '0': out+="NULL"; break;
                case '1': out+="ONE"; break;
                case '2': out+="TWO"; break; 
                case '3': out+="THREE"; break;
                case '4': out+="FOUR"; break;
                case '5': out+="FIVE"; break;
                case '6': out+="SIX"; break;
                case '7': out+="SEVEN"; break;
                case '8': out+="EIGHT"; break;
                case '9': out+="NINE"; break;
            }
        }

        // If neither number nor letter, ignore
        else {
            continue;
        }
    }
    std::cout << out << std::endl;        
}