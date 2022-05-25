#include "students_collection.h"
#include "file_errors.h"
#include "pause.h"
#include "students_functions.h"
#include "cmp.h"
#include "menu.h"
#include <Windows.h>


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //int d = take_int_for_d();

    collection_of_students* collection = new collection_of_students();

    while (1)
    {
        system("cls");

        int m1 = menu1();

        if (m1 == 27)
        {
            break;
        }

        switch (m1)
        {
            case 82:
            {
                printf("\nЧтение данных из файла");
                char filename[255] = { 0 };
                printf("\nВведите название файла ");
                gets(filename);
                FILE* input = NULL;

                try
                {
                    fopen_s(&input, filename, "r");

                    if (input == NULL)
                    {
                        throw open_file_error();
                    }

                    collection->fileinput(input);
                    fclose(input);
                    printf("\nДанные успешно получены");
                }
                catch (error& err)
                {
                    fclose(input);
                    err.print();
                }

                pause();

                break;
            }
            case 13:
            {
                print_collection(collection);

                pause();
                break;
            }
            case 83:
                collection->delete_all();

                break;
            case 49:
                printf("\nСохранение массива в файл");

                file_output(collection);

                /*
                if (collection->get_size() != 0)
                {
                    FILE* output = NULL;

                    char filename2[100] = { 0 };
                    printf("\nВведите название файла, в который будет производиться запись ");
                    gets_s(filename2);

                    try
                    {
                        fopen_s(&output, filename2, "w");

                        if (output == NULL)
                        {
                            throw output_file_error();
                            break;
                        }

                        collection->fileoutput(output);

                        fclose(output);
                    }
                    catch (error& err)
                    {
                        err.print();
                        pause();
                    }
                }
                else
                {
                    printf("\nОшибка, попытка вывести пустой массив в файл ");
                    pause();
                }
                */
                break;
            case 50:
            {
                printf("\nСортировка массива по полю");

                system("cls");

                int m4 = menu4();

                if (m4 == 27)
                {
                    break;
                }

                switch (m4)
                {
                    case 49:
                        collection->bubble_stort(&cmp_surname);

                        break;
                    case 50:
                        collection->bubble_stort(&cmp_name);

                        break;
                    case 51:
                        collection->bubble_stort(&cmp_patronymic);

                        break;
                    case 52:
                        collection->bubble_stort(&cmp_avg_mark);

                        break;
                    case 53:
                        collection->bubble_stort(&cmp_mark0);

                        break;
                    case 54:
                        collection->bubble_stort(&cmp_mark1);

                        break;
                    case 55:
                        collection->bubble_stort(&cmp_mark2);

                        break;
                }
                pause();

                break;
            }
            case 51:
            {
                printf("\nСформировать массив по среднему баллу");

                double value = take_double_for_student();

                collection_of_students* collection2 = collection->create_filtred_collection(value);

                collection2->bubble_stort(&cmp_all);

                printf("\nМассив-результат: ");

                print_collection(collection2);

                int m5 = menu5();

                if (m5 == 13)
                {
                    printf("\nСохранение массива в файл");

                    file_output(collection2);

                    /*
                    if (collection2->get_size() != 0)
                    {
                        FILE* output = NULL;

                        char filename2[100] = { 0 };
                        printf("\nВведите название файла, в который будет производиться запись ");
                        gets_s(filename2);

                        try
                        {
                            fopen_s(&output, filename2, "wb");

                            if (output == NULL)
                            {
                                throw output_file_error();
                                break;
                            }

                            collection2->fileoutput(output);

                            fclose(output);
                        }
                        catch (error& err)
                        {
                            err.print();
                            pause();
                        }
                    }
                    else
                    {
                        printf("\nОшибка, попытка вывести пустой массив в файл ");
                        pause();
                    }
                    */
                }

                delete collection2;
                break;
            }
            case 52:
            {
                int current = 0;

                while (true)
                {
                    system("cls");

                    if (collection->get_size() != 0)
                    {
                        print_student(collection->get_student(current));
                    }
                    else
                    {
                        printf("\nНа данный момент массив пуст");
                    }

                    int m2 = menu2();

                    if (m2 == 27)
                    {
                        break;
                    }

                    switch (m2)
                    {
                        case 75:
                            if (current > 0) current--;

                            break;
                        case 77:
                            if (current < collection->get_size() - 1) current++;

                            break;
                        case 13:
                        {
                            if (collection->get_size() > 0)
                            {
                                student* tmp = collection->get_student(current);
                                change_student(tmp);
                            }

                            break;
                        }
                        case 83:
                            collection->delete_index(current);

                            if (current > collection->get_size() - 1)
                            {
                                if (collection->get_size() == 0)
                                {
                                    current = 0;
                                }
                                else
                                {
                                    --current;
                                }
                            }

                            break;
                        case 82:
                        {
                            printf("\nДобавление элемента перед текущим");

                            char surname[100] = { 0 };
                            char name[100] = { 0 };
                            char patronymic[100] = { 0 };
                            int mark0 = 0;
                            int mark1 = 0;
                            int mark2 = 0;

                            take_data_for_student(surname, name, patronymic, mark0, mark1, mark2);

                            student* tmp = new student(surname, name, patronymic, mark0, mark1, mark2);
                            collection->add_prev_index(current, tmp);
                        }
                            break;
                        case 49:
                        {
                            printf("\nДобавление элемента в конец");

                            char surname[100] = { 0 };
                            char name[100] = { 0 };
                            char patronymic[100] = { 0 };
                            int mark0 = 0;
                            int mark1 = 0;
                            int mark2 = 0;

                            take_data_for_student(surname, name, patronymic, mark0, mark1, mark2);

                            student* tmp = new student(surname, name, patronymic, mark0, mark1, mark2);
                            collection->add_last(tmp);

                            break;
                        }
                        case 50:
                        {
                            printf("\nПереход к ближайшему элементу который содержит подстроку в фамилии");

                            char str[100] = { 0 };
                            printf("\nВведите подстроку по которой необходимо провести поиск ");
                            gets(str);

                            int index = collection->search_in_surname_from_index(current, str);

                            if (index == -1)
                            {
                                index = collection->search_in_surname_from_index(-1, str);

                                if (index == -1)
                                {
                                    printf("\nЭлемента с искомой подстрокой в фамилии не существует");
                                    pause();
                                }
                                else
                                {
                                    current = index;
                                }
                            }
                            else
                            {
                                current = index;
                            }

                            break;
                        }
                    }
                }
                break;
            }
        }
    }

    delete(collection);

    return 0;
}