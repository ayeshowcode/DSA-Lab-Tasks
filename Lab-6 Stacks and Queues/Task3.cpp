#include <iostream>
#include <string>
#include <cstring> 
using namespace std;

class StackChar
{
private:
    int top;
    int size;
    char *arr;

public:
    StackChar(int sz)
    {
        size = sz;
        arr = new char[size];
        top = -1;
    }

    void push(char x)
    {
        if (top == size - 1)
            cout << "Stack overflow!" << endl;
        else
            arr[++top] = x;
    }

    char pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow!" << endl;
            return '\0';
        }
        else
            return arr[top--];
    }

    char peek()
    {
        if (top == -1)
            return '\0';
        else
            return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class StackFloat
{
private:
    int top;
    int size;
    float *arr;

public:
    StackFloat(int sz)
    {
        size = sz;
        arr = new float[size];
        top = -1;
    }

    void push(float x)
    {
        if (top == size - 1)
            cout << "Stack overflow!" << endl;
        else
            arr[++top] = x;
    }

    float pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        else
            return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class Stack
{
private:
    StackChar operators;
    StackFloat values;

public:
    Stack(int sz) : operators(sz), values(sz) {}

    int precedence(char x);
    int isOperand(char x);
    string infixToPostfix(string infix);
    float evaluatePostfix(string postfix);
};

int Stack::precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int Stack::isOperand(char x)
{
    return isdigit(x) || x == '.'; 
}

string Stack::infixToPostfix(string infix)
{
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        if (isOperand(infix[i]))
        {
            while (i < infix.length() && (isOperand(infix[i]) || isdigit(infix[i])))
            {
                postfix += infix[i++];
            }
            postfix += " "; 
            i--;  
        }
        else if (infix[i] == '(')
        {
            operators.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!operators.isEmpty() && operators.peek() != '(')
            {
                postfix += operators.pop();
                postfix += " ";
            }
            operators.pop(); 
        }
        else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-')
        {
            while (!operators.isEmpty() && precedence(infix[i]) <= precedence(operators.peek()))
            {
                postfix += operators.pop();
                postfix += " ";
            }
            operators.push(infix[i]);
        }
    }

    while (!operators.isEmpty())
    {
        postfix += operators.pop();
        postfix += " ";
    }

    return postfix;
}

float Stack::evaluatePostfix(string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isdigit(postfix[i]) || postfix[i] == '.')
        {
            string num;
            while (i < postfix.length() && (isdigit(postfix[i]) || postfix[i] == '.'))
            {
                num += postfix[i++];
            }
            values.push(stof(num));
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            float val1 = values.pop();
            float val2 = values.pop();
            switch (postfix[i])
            {
            case '+': values.push(val2 + val1); break;
            case '-': values.push(val2 - val1); break;
            case '*': values.push(val2 * val1); break;
            case '/': values.push(val2 / val1); break;
            }
        }
    }
    return values.pop();  
}
int main()
{
    Stack stk(100);

    string infix = "12+13-5*(0.5+0.5)+1";
    cout << "Infix: " << infix << endl;

    string postfix = stk.infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    float result = stk.evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
