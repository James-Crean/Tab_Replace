
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
    int tabcount = 0;
    char character;
    string spaces = "    ";
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
        character = infile.get();
        if(character == '\t')
        {
            outfile << spaces;
            tabcount++;
        }
            
        else
            outfile << character;
    }

    cout << "Found " << tabcount << " tabs.";
    return 0; // everything is ok
}
