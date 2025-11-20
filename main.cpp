#include <iostream>
#include <fstream> 
#include "Library.h"

using namespace std;

int main()
{
    string fileName;
    cout << "Please input a filename to open >> ";
    cin >> fileName;

    ifstream infile(fileName.c_str());
    if (!infile)
    {
        cerr << "Error opening file \"" << fileName << "\". Program terminating." << endl;
        return 1;
    }

    Library library;
    int option = 0; // stores each menu option from the file

    // Read each option from the file until end
    while (infile >> option)
{
    if (option == 1) // return a book
    {
        string title, author;
        infile >> title >> author;
        library.returnBook(title, author);
    }
    else if (option == 2) // checkout a book
    {
        string title, author;
        infile >> title >> author;
        library.checkoutBook(title, author);
    }
    else if (option == 3) // search for an author
    {
        string author;
        infile >> author;
        library.searchAuthor(author);
    }
    else if (option == 4) // print full list
    {
        library.printList();
    }
    else if (option == 5) // quit program
    {
        cout << "Thank you for using the new library system!" << endl;
        return 0; // end the main function and quit 
    }
    else // anything else would be considered invalid
    {
        cerr << "Warning: unrecognized option code " << option << endl;
    }
}
// If file ends and option 5 wasn't found, program just exits here as normal


    return 0;
}
