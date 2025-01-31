#include <iostream>
#include <cstring> 
using namespace std;

const int PRIME = 101; 

long long calculateHash(const char *str, int start, int end)
{
    long long hash = 0;
    long long power = 1;

    for (int i = start; i <= end; i++)
    {
        hash = (hash + (str[i] - 'A' + 1) * power) % PRIME;
        power = (power * 26) % PRIME; 
    }

    return hash;
}

long long calculateReverseHash(const char *str, int start, int end)
{
    long long hash = 0;
    long long power = 1;

    for (int i = end; i >= start; i--)
    {
        hash = (hash + (str[i] - 'A' + 1) * power) % PRIME;
        power = (power * 26) % PRIME;
    }

    return hash;
}

bool isPalindrome(const char *str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void findPalindromicSubstrings(const char *text)
{
    int n = strlen(text);

    cout << "Palindromic substrings:" << endl;

    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            long long forwardHash = calculateHash(text, start, end);
            long long reverseHash = calculateReverseHash(text, start, end);

            // If hashes match, verify if the substring is a palindrome
            if (forwardHash == reverseHash && isPalindrome(text, start, end))
            {
                for (int i = start; i <= end; i++)
                {
                    cout << text[i];
                }
                cout << endl;
            }
        }
    }
}

int main()
{
    const char text[] = "ABCBAB";

    findPalindromicSubstrings(text);

    return 0;
}