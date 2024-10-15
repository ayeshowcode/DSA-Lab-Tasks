#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    char *s;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        s = new char[size];
    }

    ~Stack()
    {
        delete[] s;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    void push(char x)
    {
        if (isFull())
            cout << "stack overflow" << endl;
        else
        {
            s[++top] = x; 
        }
    }
    char pop()
    {
        char x = ' ';
        if (isEmpty())
            cout << "stack underflow" << endl;
        else
        {
            x = s[top--]; 
        }
        return x;
    }

    char peek(int index)
    {
        char x = -1;
        if (top - index + 1 < 0)
            cout << "invalid index" << endl;
        else
            x = s[top - index + 1];
        return x;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    int stackTop()
    {
        if (!isEmpty())
            return s[top];
        return -1;
    }
    int isPalindrome()
    {
        int i = 0;
        int j = top;

        while (i < j)
        {
            if (s[i] != s[j])
            {
                return 0;
            }
            i++;
            j--;
        }
        return 1; 
    }
};

int main()
{
    // Create a stack object with the desired size
   Stack st(9); // Stack size 9 for example


    // Push the word "MALAYALAM" onto the stack
    st.push('B');
    st.push('O');
    st.push('R');
    st.push('R');
    st.push('O');
    st.push('W');
    st.push('R');
    st.push('O');
    st.push('B');

    if (st.isPalindrome())
    {
        cout << " is palindrome" << endl;
    }
    else
        cout << "not a palindrome" << endl;

    st.display(); // Display the stack

    return 0;
}