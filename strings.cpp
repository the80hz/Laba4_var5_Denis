//
// Created by the80hz on 25.05.2022.
//

#include <string.h>
#include "strings.h"


bool search_in_string(const char* str1, const char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len2 > len1)
        return false;

    bool mark;

    for (int i = 0; i < len1; ++i)
    {
        mark = true;

        for (int j = 0; j < len2; ++j)
        {
            if (tolower_rus(str1[j + i]) != tolower_rus(str2[j]))
            {
                mark = false;
                break;
            }
        }

        if (mark)
        {
            return true;
        }
    }

    return false;
}

int sravnstr(const char* str1, char* str2)
{
    int i = 0;

    while (str1[i] != 0 && str1[i] != '\n' && str1[i] != '\r')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }

        ++i;
    }

    return 1;
}

char tolower_rus(char sym)
{
    char RusH[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char RusL[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 60; ++i)
    {
        if (sym == RusH[i])
        {
            return RusL[i];
        }
    }

    return sym;
}

int alf(char* a, char* alf)
{
    int lenalf = strlen(alf);

    int len = strlen(a);

    int mark = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < lenalf; j++)
        {
            if (tolower_rus(a[i]) == alf[j])
            {
                mark++;
                break;
            }
        }
    }

    if (mark == len)
    {
        return 1;
    }

    return 0;
}