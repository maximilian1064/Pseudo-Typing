//////////////////////////////////////////
//----------pseudo typping text---------//
// slowly output file content in        //
// simplified Chinese/English character //
// by character to command line         //
//////////////////////////////////////////

// USAGE:
//   $ pseudo-typing fileName delay(in seconds) 

#include <iostream>
#include <fstream>
#include <string>
#include <locale>

// for the delay
#include <cstdlib>
#include "accurate_timeDelay.h"

using namespace std;

int main(int argc, char *argv[]) 
{

    // test the validity of input arguments
    if(argc != 3)
    {
        cout << "insufficient arguments" << endl;
        return -1;
    }
    
    // set locale
    locale loc("zh_CN.UTF-8");
    locale::global(loc);

    // read the text file in lines
    // slowly output the lines through
    // setting delay between characters 
    // and flush the stdout
    wstring line = L"";

    wifstream fileStream(argv[1], wifstream::in);
    if(fileStream.is_open())
    {
        while(fileStream.good()) 
        {
            getline(fileStream, line);
            for(int i=0; i<line.length(); i++)
            {
                wcout << line.at(i);
                fflush(stdout);
                accurate_sleep( atof(argv[2]) * 1000000);
            }
            wcout << endl;
        }
        fileStream.close();
    }
    else
    {
        cout << "Failed to open file: " << argv[1] << endl;
        return -1;
    }


    return 0;
}

