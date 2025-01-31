#include <iostream>
#include <cctype>
using namespace std;

void toLowercase(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = tolower(arr[i]);
    }
}

void constructLps(char pat[], int m, int lps[])
{
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void search(char txt[], int n, char pat[], int m, int res[], int &resCount)
{
    int lps[m];
    constructLps(pat, m, lps);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;

            if (j == m)
            {
                res[resCount++] = i - j;
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    char txt[] = "Data Structures and DATA structures";
    char pat[] = "data";

    int n = sizeof(txt) / sizeof(txt[0]) - 1;
    int m = sizeof(pat) / sizeof(pat[0]) - 1;

    toLowercase(txt, n);
    toLowercase(pat, m);

    int res[100];
    int resCount = 0;

    search(txt, n, pat, m, res, resCount);

    for (int i = 0; i < resCount; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}