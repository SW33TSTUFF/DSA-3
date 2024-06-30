#include <iostream>
#include <string.h>
using namespace std;
#define asize 27

// This is my implementation of the algorithm, this may not be efficient

int bmp(char *text, char *pattern);

int main()
{
    // char *text = "trusthardtoothbrushes";
    // char *pattern = "tooth";
    char *text = "here is a simple example";
    char *pattern = "example";
    bmp(text, pattern);
    return 0;
}

int bmp(char *text, char *pattern)
{
    int m = strlen(text);
    int n = strlen(pattern);

    // implement the shift table (working!)
    int st[asize];

    for (int i = 0; i < asize; i++)
    {
        st[i] = n;
    }

    for (int i = 0; i < n - 1; i++)
    {
        // cout << int(pattern[i]) - int('a') << endl;
        int index = int(pattern[i]) - int('a');
        st[index] = n - 1 - i;
    }

    // print the shift table
    // for (int i = 0; i < asize; i++)
    // {
    //     if (st[i] != n)
    //         cout << i << "-" << st[i] << endl;
    // }

    // implement the matching

    int i = n - 1;
    while (i < m)
    {
        int matchCount = 0;
        while (text[i - matchCount] == pattern[n - matchCount - 1])
        {
            matchCount++;
            if (matchCount == n)
            {
                cout << "Pattern found at index " << (i - n + 1) << endl;
            }
        }
        // cout << int(text[i]) - int('a') << endl;
        i += st[int(text[i]) - int('a')];
    }
}
