#include "Library.h"
#include <iostream>
using namespace std;

// Set head to nullptr 
Library::Library()
{
    head = nullptr;
}

// Destructor to clean up all BookNodes in the linked list
Library::~Library()
{
    BookNode* temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->getNext();
        delete temp; // free memory
    }
}

// Returns a book; adds it or increases copy count if it exists
void Library::returnBook(string title, string author)
{
    BookNode* curr = head;
    BookNode* prev = nullptr;
    
    // Search for the book in the list
    while (curr != nullptr && !(author < curr->getAuthor()))
{
    if (curr->getTitle() == title && curr->getAuthor() == author)
    {
        curr->incCopies(); // increase number of copies
        cout << title << " by " << author
             << " now has " << curr->getCopies() << " copies available." << endl;
        return;
    }
    prev = curr;
    curr = curr->getNext();
}

    // If book is not found, create a new node and insert
    BookNode* newNode = new BookNode(title, author, 1);
    if (prev == nullptr) // insert at beginning
    {
        newNode->setNext(head);
        head = newNode;
    }
    else // insert in middle or end
    {
        newNode->setNext(curr);
        prev->setNext(newNode);
    }
    cout << title << " by " << author
         << " has been returned; there is 1 copy available." << endl;
}

// Checks out a book (decreases copy count or deletes if last copy)
void Library::checkoutBook(string title, string author)
{
    BookNode* curr = head;
    BookNode* prev = nullptr;
    
    // Look for the book in the list
    while (curr != nullptr)
    {
        if (curr->getTitle() == title && curr->getAuthor() == author)
        {
            curr->decCopies(); // remove a copy
            if (curr->getCopies() > 0)
            {
                cout << title << " by " << author
                     << " has been successfully checked out. There are "
                     << curr->getCopies() << " copies remaining." << endl;
            }
            else // remove node if no copies left
            {
                cout << "The last copy of " << title << " by "
                     << author << " has been checked out." << endl;
                if (prev == nullptr)
                {
                    head = curr->getNext(); // remove head
                }
                else
                {
                    prev->setNext(curr->getNext()); // skip over current node
                }
                delete curr; // free memory
            }
            return;
        }
        prev = curr;
        curr = curr->getNext();
    }
    
    // If book wasn't found, print message
    cout << title << " by " << author
         << " is not currently in our system. Please check back at another time." << endl;
}

// Prints all books by the given author
void Library::searchAuthor(string author)
{
    BookNode* curr = head;
    bool found = false;
    while (curr != nullptr)
    {
        if (curr->getAuthor() == author)
        {
            if (!found)
            {
                cout << "The following titles by " << author << " are currently in stock:" << endl;
                found = true;
            }
            cout << "\t" << curr->getTitle() << " is available. There are " 
            << curr->getCopies() << " copies remaining." << endl;
        }
        curr = curr->getNext();
    }
    // If nothing was found for this author
    if (!found)
    {
        cout << "There are no titles by " << author << " found in the system." << endl;
    }
}

// Prints the whole library list
void Library::printList()
{
    cout << "The library has the following books in stock:" << endl;
    BookNode* curr = head;
    while (curr != nullptr)
    {
        cout << "\t" << curr->getTitle() << " by "
             << curr->getAuthor() << " has "
             << curr->getCopies() << " copies available." << endl;
        curr = curr->getNext();
    }
}
