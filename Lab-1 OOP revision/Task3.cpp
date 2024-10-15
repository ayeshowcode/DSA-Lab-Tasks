#include <iostream>
#include <cstring> 
using namespace std;
class Document
{
    char *text; 

public:
    Document(const char *initialText)
    {
        text = new char[strlen(initialText) + 1];
        strcpy(text, initialText);
        cout << endl;
        cout << "--------------------------------" << endl;
        cout << "Constructor called" << endl;
        cout << "--------------------------------" << endl << endl;
    }

    ~Document()
    {
        delete[] text;
        cout << endl;
        cout << "--------------------------------" << endl;
        cout << "Destructor called" << endl;
        cout << "--------------------------------" << endl << endl;
    }
    Document(const Document &other)
    {
        text = new char[strlen(other.text) + 1];
        strcpy(text, other.text);
        cout << endl;
        cout << "--------------------------------" << endl;
        cout << "Copy Constructor(deep) called" << endl;
        cout << "--------------------------------" << endl << endl;
    }

    Document &operator=(const Document &other)
    {
        if (this == &other)
        {
            return *this; 
        }

        delete[] text; 

        text = new char[strlen(other.text) + 1];
        strcpy(text, other.text);
        cout << endl;
        cout << "--------------------------------" << endl;
        cout << "Copy Assignment Operator called" << endl;
        cout << "--------------------------------" << endl << endl;

        return *this;
    }

    void display() const
    {
        cout << "Document Content: " << text << endl;
    }

    void setText(const char *newText)
    {
        delete[] text; 
        text = new char[strlen(newText) + 1];
        strcpy(text, newText);
    }
};
int main()
{
    Document doc1("Original Document Text");
    cout << "doc1 - ";
    doc1.display();

    Document doc2 = doc1;
    cout << "doc2 - ";
    doc2.display();

    doc1.setText("Updating tge Original Document Text");
    cout << "After modifying doc1:" << endl;
    cout << "doc1 - ";
    doc1.display();
    cout << "doc2 - ";
    doc2.display(); 

    Document doc3("My doc3");
    cout << "doc3 - ";
    doc3.display();

    doc3 = doc1;
    cout << "After assigning doc1 to doc3:" << endl;
    cout << "doc1 - ";
    doc1.display();
    cout << "doc3 - ";
    doc3.display(); 

    return 0;
}
// so, in assignment operator both original and being copied will be affected while modifying only the being copied one 
// in deep copy only which is copied to will be affected not the original