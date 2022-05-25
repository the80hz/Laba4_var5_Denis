//
// Created by the80hz on 25.05.2022.
//

#include "string.h"
#include "students_functions.h"


void take_str_for_student(char* str)
{
    char alf1[] = { "абвгдеёжзийклмнопрстуфхцчшщъыьэюяabcdefghijklmnopqrstuvwxyz" };
    char end[2] = "\n";

    char b[100] = { 0 };
    printf("\nВведите данные(только буквы) ");
    gets_s(b, 100);

    if (b[0] == '\0' || atoi(b) != 0 || alf(b, alf1) == 0)
    {
        while (1)
        {
            printf("\nОшибка ввода строки");
            printf("\nВведите данные(только буквы) ");

            char a[100] = { 0 };
            gets_s(a, 100);

            if (a[0] != '\0' && atoi(a) == 0 && alf(a, alf1) != 0)
            {
                strcat_s(a, 100, end);
                strcpy_s(str, 100, a);
                break;
            }
        }
    }
    else
    {
        strcat_s(b, 100, end);
        strcpy_s(str, 100, b);
    }

    /*
    while (1)
    {
        try
        {
            printf("\nВведите данные(только буквы) ");
            gets_s(str, 100);

            if (str[0] == '\0')
            {
                throw input_string_error();
            }

            if (atoi(str) != 0)
            {
                throw input_string_error();
            }

            if (alf(str, alf1) == 0)
            {
                throw input_string_error();
            }

            strcat_s(str, 100, end);
            break;
        }
        catch (error& err)
        {
            err.print();
        }
    }
    */
}

int take_mark_for_student()
{
    char m[100] = { 0 };
    char alf2[] = { "1234567890" };

    printf("\nВведите оценку(целое число от 1 до 5) ");
    gets_s(m, 100);
    int a = atoi(m);

    if (alf(m, alf2) == 0 || a < 1 || a > 5)
    {
        while (1)
        {
            printf("\nОшибка ввода целого числа");
            printf("\nВведите оценку(целое число от 1 до 5) ");
            char n[100] = { 0 };

            gets_s(n, 100);
            int b = atoi(n);

            if (alf(n, alf2) != 0 && b >= 1 && b <= 5)
            {
                return b;
                break;
            }
        }
    }
    else
    {
        return a;
    }

    /*
    while (1)
    {
        try
        {
            printf("\nВведите оценку(целое число от 1 до 5) ");
            gets_s(m, 100);

            if (alf(m, alf2) == 0)
            {
                throw input_int_error();
            }

            int a = atoi(m);

            if (a < 1 || a > 5)
            {
                throw input_int_value_error();
            }

            return a;
            break;
        }
        catch (error& err)
        {
            err.print();
        }
    }
    */
}

double take_double_for_student()
{
    char m[100] = { 0 };
    char alf2[] = { "1234567890." };

    printf("\nВведите оценку(вещественное число от 1 до 5) ");
    gets_s(m, 100);
    double a = atof(m);

    if (alf(m, alf2) == 0 || a < 1 || a > 5)
    {
        //throw input_double_error();
        while (1)
        {
            printf("\nОшибка ввода вещественного числа");
            printf("\nВведите оценку(вещественное число от 1 до 5) ");
            char n[100] = { 0 };
            gets_s(n, 100);
            double b = atof(n);

            if (alf(n, alf2) != 0 && b >= 1 && b <= 5)
            {
                return b;
                break;
            }
        }
    }
    else
    {
        return a;
    }



    /*
    if (a < 1 || a > 5)
    {
        while (1)
        {
            printf("Ошибка ввода вещественного числа");
            printf("\nВведите оценку(вещественное число от 1 до 5) ");
            gets_s(m, 100);
            if (alf(m, alf2) != 0) break;
        }
    }
    */
}

void take_data_for_student(char* surname, char* name, char* patronymic, int& mark0, int& mark1, int& mark2)
{
    printf("\nВведите фамилию ");
    take_str_for_student(surname);

    printf("\nВведите имя ");
    take_str_for_student(name);

    printf("\nВведите отчество ");
    take_str_for_student(patronymic);

    mark0 = take_mark_for_student();
    mark1 = take_mark_for_student();
    mark2 = take_mark_for_student();
}

void change_student(student* object)
{
    char str[100] = { 0 };
    char end[3] = "\r\n";
    int a = 0;

    while (true)
    {
        system("cls");

        print_student(object);

        int m3 = menu3();

        if (m3 == 27)
        {
            break;
        }

        switch (m3)
        {
            case 49:
            {
                printf("\nВведите фамилию\n");

                take_str_for_student(str);

                object->set_surname(str);

                break;
            }
            case 50:
            {
                printf("\nВведите имя\n");

                take_str_for_student(str);

                object->set_name(str);

                break;
            }
            case 51:
            {
                printf("\nВведите отчество\n");

                take_str_for_student(str);

                object->set_patronymic(str);

                break;
            }
            case 52:
            {
                int mark0 = take_mark_for_student();

                object->set_mark0(mark0);

                break;
            }
            case 53:
            {
                int mark1 = take_mark_for_student();

                object->set_mark1(mark1);

                break;
            }
            case 54:
            {
                int mark2 = take_mark_for_student();

                object->set_mark2(mark2);

                break;
            }
        }
    }
}

void print_student(student* object)
{
    printf("\n");

    printf("Surname: %s", object->get_surname());
    printf("Name: %s", object->get_name());
    printf("Patronymic: %s", object->get_patronymic());

    printf("Marks: %d ", object->get_mark0());
    printf("%d ", object->get_mark1());
    printf("%d", object->get_mark2());

    printf("\n\n");
}

void print_collection(collection_of_students* collection)
{
    printf("\nВывод всего массива на экран\n");

    int size = collection->get_size();

    if (size == 0)
    {
        printf("\nМассив на данный момент пуст");
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            print_student(collection->get_student(i));
        }
    }
}

/*
int take_int_for_d()
{
	char m[100] = { 0 };
	char alf2[] = { "1234567890" };

	while (1)
	{
		try
		{
			printf("\nВведите значение прироста для расширения коллекции(целое число больше 0) ");
			gets_s(m, 100);

			if (alf(m, alf2) == 0)
			{
				throw input_int_error();
			}

			int a = atoi(m);

			if (a < 1)
			{
				throw input_int_value_error();
			}

			return a;
			break;
		}
		catch (error& err)
		{
			err.print();
		}
	}
}
*/

void file_output(collection_of_students* collection)
{
    FILE* output = NULL;

    char filename2[100] = { 0 };
    printf("\nВведите название файла, в который будет производиться запись ");
    gets(filename2);

    fopen_s(&output, filename2, "w");

    if (output == NULL)
    {
        printf("\nОшибка при попытке вывода в файл");
    }
    else
    {
        try
        {
            collection->fileoutput(output);
            printf("Данные успешно сохранены");
            fclose(output);
        }
        catch (...)
        {
            fclose(output);
            throw;
        }
    }

    pause();
}