#ifndef BOOKNODE_H
#define BOOKNODE_H

#include <string>
using namespace std;

// Represents a single book in the library linked list
class BookNode
{
public:
    BookNode(string t, string a, int copies); // Constructor
    ~BookNode(); // Destructor

    // Getters
    // Getter for title
    string getTitle();

    // Getter for author
    string getAuthor();
    
    // Getter for number of copies
    int getCopies();

    // Getter for next pointer
    BookNode* getNext();

    // Setters
    // Setter for next pointer
    void setNext(BookNode* node);

    // Setter that increases number of copies
    void incCopies();

    // Setter that decreases number of copies
    void decCopies();

    

private:
    string title;        // book's title
    string author;       // book's author
    int copies;          // number of copies available
    BookNode* next;      // pointer that points to the next book in the list
};

#endif
