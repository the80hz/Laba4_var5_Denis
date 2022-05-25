//
// Created by the80hz on 25.05.2022.
//

#include <iostream>
#include <conio.h>
#include "menu.h"


int menu1()
{
    printf("\nЧтение данных из файла - Insert\nВывод всего массива на экран - Enter\nУдалить массив - Delete\nСохранить массив в файл - 1\nСортировка массива по любому полю - 2\nСформировать массив-результат по среднему баллу - 3\nПерейти к массиву - 4\nВыход - Escape\n");
    while (true)
    {
        int key = _getch();
        if (key == 82 || key == 13 || key == 83 || key == 49 || key == 50 || key == 51 || key == 52 || key == 27)
        {
            return key;
        }
    }
}

int menu2()
{
    printf("\n<- - следующий элемент\n-> - предыдущий элемент\nРедактировать текущий элемент - Enter\nУдалить текущий элемент - Delete\nДобавление элемента перед текущим - Insert\nДобавление элемента в конец - 1\nПереход к ближайшему элементу который содержит подстроку - 2\nВыход - Escape\n");
    while (true)
    {
        int key = _getch();
        if (key == 75 || key == 77 || key == 13 || key == 83 || key == 82 || key == 49 || key == 50 || key == 27)
        {
            return key;
        }
    }
}

int menu3()
{
    printf("\nИзменить фамилию - 1\nИзменить имя - 2\nИзменить отчество - 3\nИзменить 1-ую оценку - 4\nИзменить 2-ую оценку - 5\nИзменить 3-ю оценку - 6\nВыход - Escape\n");
    while (true)
    {
        int key = _getch();
        if (key == 49 || key == 50 || key == 51 || key == 52 || key == 53 || key == 54 || key == 27)
        {
            return key;
        }
    }
}

int menu4()
{
    printf("\nСортировка по фамилии - 1\nСортировка по имени - 2\nСортировка по отчеству - 3\nСортировать по среднему баллу - 4\nСортировать по первой оценке - 5\nСортировать по второй оценке - 6\nСортировать по третьей оценке - 7\nВыход - Escape\n");
    while (true)
    {
        int key = _getch();
        if (key == 49 || key == 50 || key == 51 || key == 52 || key == 53 || key == 54 || key == 55 || key == 27)
        {
            return key;
        }
    }
}

int menu5()
{
    printf("\nСохранить массив-результат в файл - Enter\nВыход - Escape\n");
    while (true)
    {
        int key = _getch();
        if (key == 13 || key == 27)
        {
            return key;
        }
    }
}
