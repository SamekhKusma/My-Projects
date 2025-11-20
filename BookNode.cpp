#include "BookNode.h"

using namespace std;

// Sets up a new BookNode with title, author, and # of copies
BookNode::BookNode(string t, string a, int c)
{
    title = t;
    author = a;
    copies = c;
    next = nullptr; // next is null by default
}

BookNode::~BookNode() {} // nothing to delete inside BookNode

// Getters and Setters

// Getter for title
string BookNode::getTitle()
{ 
    return title;
}

// Getter for author
string BookNode::getAuthor() 
{
    return author;
}

// Getter for number of copies
int BookNode::getCopies() 
{
    return copies; 
}

// Getter for next node pointer
BookNode* BookNode::getNext() 
{
    return next; 
}

// Setter for next node pointer
void BookNode::setNext(BookNode* node) 
{
    next = node;
}

// Setter that increases number of copies by 1
void BookNode::incCopies() 
{
    copies++; 
}

// Setter that decreases number of copies by 1
void BookNode::decCopies() 
{ 
    copies--; 
}
