#include <iostream>
#include <string>

using namespace std;

void bruteForceSearch(const string &text, const string &pattern, int matches[], int &count)
{
    int n = text.length();
    int m = pattern.length();
    count = 0;

    for (int i = 0; i <= n - m; i++)
    {
        bool match = true;

        for (int j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            matches[count++] = i;
        }
    }
}

int main()
{
    string text, pattern;
    const int MAX_MATCHES = 100;
    int matches[MAX_MATCHES];
    int count;

    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    bruteForceSearch(text, pattern, matches, count);

    if (count == 0)
    {
        cout << "Pattern not found in the text." << endl;
    }
    else
    {
        cout << "Pattern found at indices: ";
        for (int i = 0; i < count; i++)
        {
            cout << matches[i] << " ";
        }
        cout << endl;
    }

    return 0;
}