#include <assert.h>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    
    const std::vector<std::string> cmdLineArgs { argv, argv+argc };

    std::string infilename = ""; 
    std::string outfilename = ""; 
    std::string version = "v1.0";

    int count = 0;
    for (auto el : cmdLineArgs) {
        if (el == "-v" || el == "--version") {
            std::cout << "mpags-cipher version " << version << std::endl;
        }
        if (el == "-h" || el == "--help") {
            std::cout << "Options:" << std::endl <<
            " -i <input txt file> " << std::endl <<
            " -o <output txt file> " << std::endl <<
            " -c <cipher name> " << std::endl <<
            " -k <int> " << std::endl <<
            " --encrypt" << std::endl;
        } 
        else if (el == "-i") {
           infilename =  cmdLineArgs.at(count+1); 
        }
        else if (el == "-o") {
           outfilename =  cmdLineArgs.at(count+1); 
        }
        count++;
    }

    assert((infilename != "") && "No input file provided. Use -i option to specify.");
    assert((outfilename != "") && "No output file provided. Use -o option to specify.");

    std::ifstream in(infilename);
    if (!in) {
        std::cerr << "Unable to open input .txt file" << std::endl;
        return 1;   // call system to stop
    }

    // string to store output cipher
    std::string out = "";

    // Loop over all input characters
    char c;
    while (in.get(c)) {

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
    in.close();

    // open output file and write to it
    std::ofstream outf(outfilename);
    if (!outf) {
        std::cerr << "Unable to open output .txt file" << std::endl;
        return 1;   // call system to stop
    }

    outf << out;
    outf << std::endl;
}