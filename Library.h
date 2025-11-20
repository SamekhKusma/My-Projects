#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include "BookNode.h"
using namespace std;

// This class manages all the books in the library using a linked list
class Library
{
public:
    Library();
    ~Library();
    
    // Add or return a book
    void returnBook(string title, string author);     
    
    // Checkout a book
    void checkoutBook(string title, string author);  
    
    // Find all books by author
    void searchAuthor(string author);         
    
    // Show all books
    void printList();                                 

private:
    // Start of the linked list
    BookNode* head;  
};

#endif
