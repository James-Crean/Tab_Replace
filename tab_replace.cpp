/*
    Simple program to demonstrate file I/O and 
    how to access command line arguments.  For example:

        $ mycat myinput 

    "myinput" is specified on the command line when the program mycat is started.

    This string (called a command line argument) is available in the main() 

    This program is similar to the Linux cat program.  It accepts a single
    command line argument (the name of a file), then it opens the file and 
    reads each line from the file and writes that line to standard output

        $ cat myfile
        one
        two
        three
        $ mycat myfile
        one
        two
        three
        $

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// in order to access the command line arguments, declare main() like this
int main(int argc, char *argv[])
{
    int tabcount = 0;
    char character;
    string spaces = "    ";
    // make sure a filename was specified on the command line
    // argc tells us how many command line arguments were given
    // "2" means that no command line arguments were given
    // (the first argument is the name of the executable)
    if (argc < 3)
    {
        // write to standar error (cerr)
        cerr << "Must specify input and output file." << endl;
        return 1; // 1 is error condition
    }
    if (argc > 3)
    {
        cerr << "Too many command line arguments specified." << endl;
        return 1;
    }

    // open the file specified in argv[1].  
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);


    if (!infile)
    {
        cerr << "Could not open input file <" << argv[1] << ">." << endl;
        return 1; 
    }
    
    if (!outfile)
    {
        cerr << "Could not open output file <" << argv[2] << ">." << endl;
        return 1;
    }
    
    // as long as there is more input (not end of file), read a character
    while(infile.peek() != EOF)
    {
        character = infile.get()
        if(character == '\t')
        {
            outfile << spaces;
            tabcount++;
        }
            
        else
            outfile << character;
    }

    cout << "Found " << tabcount << " tabs."
    return 0; // everything is ok
}
