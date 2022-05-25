//
// Created by the80hz on 25.05.2022.
//

#include "cmp.h"
#include "cstring"

int cmp_surname(const student& s1, const student& s2)
{
    return strcmp(s1.get_surname(), s2.get_surname());
}

int cmp_name(const student& s1, const student& s2)
{
    return strcmp(s1.get_name(), s2.get_name());
}

int cmp_patronymic(const student& s1, const student& s2)
{
    return strcmp(s1.get_patronymic(), s2.get_patronymic());
}

int cmp_avg_mark(const student& s1, const student& s2)
{
    int m1 = s1.get_mark0() + s1.get_mark1() + s1.get_mark2();
    int m2 = s2.get_mark0() + s2.get_mark1() + s2.get_mark2();

    if (m1 < m2)
    {
        return 1;
    }
    else
    {
        if (m1 == m2)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
}

int cmp_mark0(const student& s1, const student& s2)
{
    return s2.get_mark0() - s1.get_mark0();

    /*
    int m1 = s1.get_mark0();
    int m2 = s2.get_mark0();

    if (m1 < m2)
    {
        return 1;
    }
    else
    {
        if (m1 == m2)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    */
}

int cmp_mark1(const student& s1, const student& s2)
{
    return s2.get_mark1() - s1.get_mark1();

    /*
    int m1 = s1.get_mark1();
    int m2 = s2.get_mark1();

    if (m1 < m2)
    {
        return 1;
    }
    else
    {
        if (m1 == m2)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    */
}

int cmp_mark2(const student& s1, const student& s2)
{
    return s2.get_mark2() - s1.get_mark2();

    /*
    int m1 = s1.get_mark2();
    int m2 = s2.get_mark2();

    if (m1 < m2)
    {
        return 1;
    }
    else
    {
        if (m1 == m2)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    */
}

int cmp_all(const student& s1, const student& s2)
{
    int a = cmp_surname(s1, s2);
    if (a != 0)
        return a;

    a = cmp_name(s1, s2);
    if (a != 0)
        return a;

    return cmp_patronymic(s1, s2);
}
