#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
const int N = 4000;
#include <cstring>
#include <iomanip>
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
            SetConsoleCP(1251);
            SetConsoleOutputCP(866);
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
List *MergeSort(List *&S, int n)
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
    return S;
}
struct queue
{
    List *top, *tail;
};
void init(queue *q)
{
    q->top = NULL;
    q->tail = NULL;
}
void insert(queue *q, record *R)
{
    List *q2;
    q2 = new List();
    if (q->top == NULL && q->tail == NULL)
    {
        q2->data = R;
        q2->next = NULL;
        q->tail = q2;
        q->top = q->tail;
    }
    else
    {
        List *q3;
        q3 = q->tail->next;
        q->tail->next = q2;
        q2->data = R;
        q2->next = q3;
        q->tail = q2;
    }
}
void spisprint(queue *q, int count)
{
    List *q2;
    int i = 0;

    for (q2 = q->top; q2 != NULL; q2 = q2->next, count++)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(866);
        cout << count << ") " << q2->data->fio << "\t" << q2->data->vclad << "\t"
             << q2->data->num_of_vclad << "\t" << q2->data->title << endl;
    }
}
int number(queue *q, int count = 1)
{
    List *q2;
    int i = 0;

    for (q2 = q->top; q2 != NULL; q2 = q2->next, count++)
    {
    }
    return count;
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
int strcompt(const string &str1, const string &str2)
{
    int c = 0;

    for (int i = 0; i < 3; ++i)
    {
        if (str1[i] == str2[i])
        {
            c++;
        }
        if (str1[i] < str2[i])
        {
            return -1;
        }
        if (str1[i] > str2[i])
        {
            return 1;
        }
    }

    return c;
}
int BinarySearch2(record *arr[], queue *top)
{

    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    char str[4] = {};
    char str2[4] = {};
    str[3] = '\0';
    cout << "Vvedite 3 bykvi FIO ";

    for (int i = 0; i < 3; i++)
    {
        cin >> str[i];
    }
    int c = 0;
    int L = 0;
    int m;
    int R = 4000;
    while (L < R)
    {
        m = (L + R) / 2;
        for (int i = 0; i < 3; i++)
        {
            str2[i] = arr[m]->title[i];
        }

        if (strcmp(str2, str) < 0)
            L = m + 1;
        else
            R = m;
    }
    int i = R + 1;

    while (strcmp(str2, str) == 0)
    {
        for (int v = 0; v < 3; v++)
        {
            str2[v] = arr[i]->title[v];
        }

        if (strcmp(str2, str) == 0)
            insert(top, arr[i]);
        i++;
    }
    return R;
}
void make_index_array(record *arr[], List *root, int n = N)
{
    List *p = root;
    for (int i = 0; i < n; i++)
    {
        arr[i] = &*(p->data);
        p = p->next;
    }
}
struct Vertex
{
    record *data;

    Vertex *left;
    Vertex *right;
    int balance;
};
bool grow;
void ll(Vertex *&p)
{
    Vertex *q = p->left;
    p->balance = q->balance = 0;
    p->left = q->right;
    q->right = p;
    p = q;
}
void rr(Vertex *&p)
{
    Vertex *q = p->right;
    p->balance = q->balance = 0;
    p->right = q->left;
    q->left = p;
    p = q;
}
void lr(Vertex *&p)
{
    Vertex *q = p->left;
    Vertex *r = q->right;
    if (r->balance < 0)
    {
        p->balance = 1;
    }
    else
    {
        p->balance = 0;
    }
    if (r->balance > 0)
    {
        q->balance = -1;
    }
    else
    {
        q->balance = 0;
    }
    r->balance = 0;
    q->right = r->left;
    p->left = r->right;
    r->left = q;
    r->right = p;
    p = r;
}
void rl(Vertex *&p)
{
    Vertex *q = p->right;
    Vertex *r = q->left;
    if (r->balance > 0)
    {
        p->balance = -1;
    }
    else
    {
        p->balance = 0;
    }
    if (r->balance < 0)
    {
        q->balance = 1;
    }
    else
    {
        q->balance = 0;
    }
    r->balance = 0;
    q->left = r->right;
    p->right = r->left;
    r->right = q;
    r->left = p;
    p = r;
}
void add_to_avl(Vertex *&p, record *h)
{

    if (!p)
    {

        p = new Vertex{h, nullptr, nullptr, 0};
        grow = true;
    }
    else if (strcompt(p->data->fio, h->fio) > 0)
    {

        add_to_avl(p->left, h);
        if (grow)
        {

            if (p->balance > 0)
            {
                p->balance = 0;
                grow = false;
            }
            else if (p->balance == 0)
            {
                p->balance = -1;
                grow = true;
            }
            else
            {
                if (p->left->balance < 0)
                {
                    ll(p);
                    grow = false;
                }
                else
                {
                    lr(p);
                    grow = false;
                }
            }
        }
    }
    else if (strcompt(p->data->fio, h->fio) < 0)
    {

        add_to_avl(p->right, h);
        if (grow)
        {

            if (p->balance < 0)
            {
                p->balance = 0;
                grow = false;
            }
            else if (p->balance == 0)
            {
                p->balance = 1;
                grow = true;
            }
            else
            {
                if (p->right->balance > 0)
                {
                    rr(p);
                    grow = false;
                }
                else
                {
                    rl(p);
                    grow = false;
                }
            }
        }
    }
    else
    {
        std::cout << "Data already exist";
    }
}
void print_record(record *record, int i)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(866);
    cout << "[" << i << "] "
         << record->fio
         << "  " << setw(5) << record->vclad
         << "  " << record->num_of_vclad
         << "  " << record->title << "\n";
}
void Print_tree(Vertex *p, int &i)
{

    if (p)
    {
        print_record(p->data, i++);
        Print_tree(p->left, i);

        Print_tree(p->right, i);
    }
}
void make_index_array_q(record *arr[], List *root, int n)
{
    List *p = root;
    for (int i = 0; i < n; i++)
    {
        arr[i] = &*(p->data);
        p = p->next;
    }
}
void search_in_tree(Vertex *root, const string &key, int &i)
{

    if (root)
    {
        if (strcompt(key, root->data->fio) == -1)
        {
            search_in_tree(root->left, key, i);
        }
        else if (strcompt(key, root->data->fio) == 1)
        {
            search_in_tree(root->right, key, i);
        }
        else if (strcompt(key, root->data->fio) == 3)
        {
            search_in_tree(root->left, key, i);
            print_record(root->data, i++);
            search_in_tree(root->right, key, i);
        }
    }
}
string prompt(const string &str)
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    cout << str;
    cout << "\n> ";
    string ans;
    cin >> ans;
    return ans;
}

struct code
{
    char c;
    float p;
};
const int n_symb = 256;
code symb[n_symb];
char C[n_symb][n_symb];
int *Length;
void InsertSort(code *a, int n)
{
    int i, j, k = 0;
    code t;
    for (i = 1; i < n; i++)
    {
        t = a[i];
        j = i - 1;
        while (j >= 0 && a[j].p < t.p)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = t;
    }
}
int m = 0;
float sl = 0, sr = 0;
int Med(int L, int R, code *symb)
{
    sl = 0;
    for (int i = L; i < R; i++)
        sl += symb[i].p;
    sr = symb[R].p;
    m = R;
    while (sl >= sr)
    {
        m--;
        sl -= symb[m].p;
        sr += symb[m].p;
    }
    return m;
}

void Fano(int L, int R, int k, code *symb)
{
    if (L < R)
    {
        k++;
        int m = Med(L, R, symb);
        for (int i = L; i <= R; i++)
        {
            if (i <= m)
            {
                C[i][k] = '0';
                Length[i]++;
            }
            else
            {
                C[i][k] = '1';
                Length[i]++;
            }
        }
        Fano(L, m, k, symb);
        Fano(m + 1, R, k, symb);
    }
}

void Coding_Fano()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(866);
    FILE *f;
    f = fopen("testBase3.dat", "r");

    for (int i = 0; i < n_symb; i++)
    {
        symb[i].c = i;
        symb[i].p = 0.0;
    }

    char c;
    int size = 0;
    while (!feof(f))
    {
        size++;
        char c = getc(f);
        for (int i = 0; i < n_symb; i++)
        {
            if (c == symb[i].c)
            {
                symb[i].p++;
                break;
            }
        }
    }
    fclose(f);
    int cx = 0;
    for (int i = 0; i < n_symb; i++)
    {
        if (symb[i].p != 0)
        {
            cx++;
            symb[i].p = (float)(symb[i].p / size);
        }
    }

    Length = new int[cx];
    for (int i = 0; i < cx; i++)
        Length[i] = 0;

    InsertSort(symb, n_symb);
    Fano(0, cx - 1, 0, symb);
    cout << "\n";

    cout << "Num| Symbol| Probability |  Length  | Code word\n";
    cout << "---|-------|-------------|----------|------------\n";
    for (int i = 0; i < cx; i++)
    {
        printf("%2d |", i + 1);
        printf("%4c   |", symb[i].c);
        printf(" %9f   |", symb[i].p);
        printf("%6d    |", Length[i]);
        for (int j = 0; j <= Length[i]; j++)
            cout << C[i][j];

        cout << "\n";
    }
    cout << "\n";
    float med_length = 0;
    float entropy = 0;
    float sum_p = 0;
    for (int i = 0; i < cx; i++)
    {
        med_length += symb[i].p * Length[i];
        entropy += symb[i].p * log2(symb[i].p);
        sum_p += symb[i].p;
    }
    entropy *= (-1);
    cout << "Medium length = " << med_length << "\n";
    cout << "Entropy = " << entropy << "\n\n\n";

    cout << "Medium L >= Entropy\n";
    cout << "Medium L < Entropy + 1\n\n";
}

int main()
{
    record *arr[4000];

    int flag = 0;
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
    List *v;
    List *v1;

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

    SetConsoleCP(1251);
    SetConsoleOutputCP(866);
    p = MergeSort(p, N);

    cout << "Vivesti vse? 1/0: ";
    cin >> c;
    if (c == 1)
    {
        p = printListfull(p, count);
        return 0;
    }
    v = p;
    v1 = p;
    cout << "Vivesti 20? 1/0: ";
    cin >> c;
    while (c == 1)
    {
        for (i = 0; i < N / 20 + 1; i++)
        {
            p = printList(p, count);

            cout << "Sled 20?  1/0: ";
            cin >> c;
            if (c == 0)
            {
                break;
            }
        }
    }

    cout << " Naiti ? 1\n Coding ? 2\n Exit ? 0 ";
    cin >> c;
    if (c == 1)
    {

        make_index_array(arr, v);
        queue *tops = new queue;
        init(tops);
        int num = BinarySearch2(arr, tops);
        spisprint(tops, num);
        int mk = number(tops, num);
        record *arr1[4000];
        make_index_array_q(arr1, v1, mk);
        Vertex *root = nullptr;
        List *h = new List;
        for (int i = 0; i < mk; i++)
        {

            add_to_avl(root, arr1[i]);
        }

        int i = 1;
        Print_tree(root, i);
        string key;

        key = prompt("Input search key, q - exit");
        cout << "_____________" << endl;
        i = 1;

        search_in_tree(root, key, i);
    }
    if (c == 2)
    {
        Coding_Fano();
    }
    if (c == 0)
    {

        return 0;
    }
}