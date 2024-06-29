#include <iostream>
#include <string.h>
using namespace std;

int kmp(char *text, char *pattern);

int main()
{
    kmp("ababcabcabababd", "ababd");
}

int kmp(char *text, char *pattern)
{
    int m = strlen(text);
    int n = strlen(pattern);

    // construct the lps array
    int lps[n] = {0};

    // compute the lps values
    int i = 1;
    while (i < n)
    {
        int j = 0;
        while (j < n)
        {
            if (pattern[i] == pattern[j])
            {
                lps[i] = j + 1;
                i++;
                j++;
            }
            else
            {
                i++;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << lps[i] << " ";
    }
    i = 0;
    int j = -1;
    // main logic
    while (i < m)
    {

        if (text[i] == pattern[j + 1])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            j = lps[j];
        }

        if (j + 1 == n)
        {
            cout << "Pattern found at index" << " " << (i - n);
        }
    }

    return 0;
}
