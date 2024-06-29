#include <iostream>
#include <string.h>
using namespace std;

int naiveStringMatchIndex(char *text, char *pattern);

int main()
{
    string text = "This is a pattern";
    string pattern = "pat";
    naiveStringMatchIndex("This is a pattern", "pat");
}

int naiveStringMatchIndex(char *text, char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i < n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }

        if (j == m)
        {
            cout << "Pattern found at index" << " " << i;
        }
    }
}
