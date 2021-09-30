#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
const int N = 4000;
#include <cstring>
using namespace std;

struct record
{
    char fio[30] = {};
    unsigned short int vclad;
    char num_of_vclad[10] = {};
    char title[22] = {};
};

struct List
{
    record *data;
    List *next;
};

List *printList(List *p, int &count)
{

    for (int i = 0; i < 20; i++, count++)
    {
        cout << count << ") " << p->data->fio << "\t" << p->data->vclad << "\t"
             << p->data->num_of_vclad << "\t" << p->data->title << endl;
        p = p->next;
    }
    return p;
}
List *printListfull(List *p, int &count)
{
    for (int i = 0; i < 4000; i++, count++)
    {
        if (count < 4001)
        {
            cout << count << ") " << p->data->fio << "\t" << p->data->vclad << "\t"
                 << p->data->num_of_vclad << "\t" << p->data->title << endl;
            p = p->next;
        }
        else
            return 0;
    }
    return p;
}
int compare(const record &record1, const record &record2)
{

    if (strcmp(record1.title, record2.title) > 0)
    {
        return -1;
    }
    else if (strcmp(record1.title, record2.title) < 0)
    {
        return 1;
    }
    if (record1.vclad < record2.vclad)
    {
        return -1;
    }
    else
        return 1;
    return 0;
}
struct body
{
    List *head;
    List *tail;
};

void MergeSort(List *&S, int n)
{
    int t, q, r, i, m;
    List *a, *b, *k, *p;
    body c[2];
    a = S;
    b = S->next;
    k = a;
    p = b;
    while (p != NULL)
    {
        k->next = p->next;
        k = p;
        p = p->next;
    }
    t = 1;
    List *temp1 = a, *temp2 = b;
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        temp2 = temp2->next;
    }

    while (t < n)
    {
        c[0].tail = c[0].head = NULL;
        c[1].tail = c[1].head = NULL;
        i = 0;
        m = n;
        while (m > 0)
        {
            if (m >= t)
                q = t;
            else
                q = m;
            m = m - q;
            if (m >= t)
                r = t;
            else
                r = m;
            m = m - r;
            while (q != 0 && r != 0)
            {
                if (compare(*a->data, *b->data) > 0)
                {
                    if (c[i].tail == NULL)
                    {
                        c[i].tail = c[i].head = a;
                    }
                    else
                    {
                        c[i].tail->next = a;
                        c[i].tail = a;
                    }
                    a = a->next;
                    q--;
                }
                else
                {

                    if (c[i].tail == NULL)
                    {
                        c[i].tail = c[i].head = b;
                    }
                    else
                    {
                        c[i].tail->next = b;
                        c[i].tail = b;
                    }
                    b = b->next;
                    r--;
                }
            }
            while (q > 0)
            {
                if (c[i].tail == NULL)
                {
                    c[i].tail = c[i].head = a;
                }
                else
                {
                    c[i].tail->next = a;
                    c[i].tail = a;
                }
                a = a->next;
                q--;
            }
            while (r > 0)
            {
                if (c[i].tail == NULL)
                {
                    c[i].tail = c[i].head = b;
                }
                else
                {
                    c[i].tail->next = b;
                    c[i].tail = b;
                }
                b = b->next;
                r--;
            }
            i = 1 - i;
        }
        a = c[0].head;
        b = c[1].head;
        t = 2 * t;
    }
    c[0].tail->next = NULL;
    S = c[0].head;
}
int strcomp(const string &str1, const string &str2)
{
    int c = 0;

    for (int i = 0; i < 3; ++i)
    {
        if (str1[i] == str2[i])
        {
            c++;
        }
    }
    return c;
}
List *serch(List *p)
{

    char str[4] = {};
    cout << "Vvedite 3 bykvi FIO ";
    cin >> str;
    int c = 0;

    for (int i = 0; i < 3999; i++)
    {
        char *str1 = p->data->title;

        if (strcomp(str1, str) == 3)
        {
            SetConsoleCP(1251);
            SetConsoleOutputCP(866);

            cout << p->data->fio << "\t" << p->data->vclad << "\t"
                 << p->data->num_of_vclad << "\t" << p->data->title << endl;
        }
        p = p->next;
    }
    return p;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1200);
    SetConsoleOutputCP(1200);
    FILE *fin;
    fin = fopen("testBase3.dat", "rb");
    int i;
    int c;
    int count = 1;
    List *head = new List;
    List *p = head;

    for (i = 0; i < N; i++)
    {

        p->data = new record;
        fread((record *)p->data, sizeof(record), 1, fin);

        if (i != N - 1)
        {
            p->next = new List;
            p = p->next;
        }
        else
        {
            p->next = NULL;
        }
    }
    p = head;
    p = serch(p);
    SetConsoleCP(1251);
    SetConsoleOutputCP(866);
    p = head;
    MergeSort(p, N);
    cout << "Vivesti vse? 1/0: ";
    cin >> c;
    if (c == 1)
    {
        p = printListfull(p, count);
    }

    cout << "Vivesti 20? 1/0: ";
    cin >> c;
    if (c == 1)
    {
        for (i = 0; i < N / 20 + 1; i++)
        {
            p = printList(p, count);

            cout << "Sled 20?  1/0: ";
            cin >> c;
            if (c == 0)
            {

                return 0;
            }
            if (c == 1)
            {
                int Size = 20;
                while (Size)
                {
                    List *tmp = head;
                    head = head->next;
                    delete tmp;
                    Size--;
                }
            }
        }
    }
}