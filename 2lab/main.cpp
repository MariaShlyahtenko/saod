#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
struct node
{
    int data;
    node *left, *right;
};

void print(node *p)
{
    if (p)
    {

        print(p->left);
        cout << p->data << " ";
        print(p->right);
    }
}

double sum_lens_way(node *p, int z)
{
    int s;
    if (!p)
        s = 0;
    else
    {
        s = z + sum_lens_way(p->left, z + 1) + sum_lens_way(p->right, z + 1);
    }
    return s;
}
//размер дерева
int check_size(node *p)
{
    int size_tree;
    if (!p)
        size_tree = 0;
    else
    {
        size_tree = 1 + check_size(p->left) + check_size(p->right);
    }
    return size_tree;
}
//средняя высота дерева
double mid_hight(node *p)
{
    return (sum_lens_way(p, 1) / check_size(p));
}
//контрольная сумма
int check_sum(node *p)
{
    int sum;
    if (!p)
        sum = 0;
    else
    {
        sum = p->data + check_sum(p->left) + check_sum(p->right);
    }
    return sum;
}
//высота
int tree_height(node *p)
{
    if (!p)
        return -1;
    return 1 + max(tree_height(p->left), tree_height(p->right));
}
//информация
void showInfo(node *root)
{
    cout << "    " << check_size(root) << "      " << check_sum(root) << "         " << tree_height(root) + 1 << "         " << mid_hight(root) << endl;
    print(root);
}
//поиск
void serch(node *p, int x)
{

    while (p)
    {
        if (x < p->data)
        {
            p = p->left;
        }
        if (!p)
            break;
        if (x > p->data)
        {
            p = p->right;
        }
        if (!p)
            break;
        if (x == p->data)
            break;
    }

    if (p)
        cout << "Vershina " << p->data << " naidena po adresy " << p << endl;
    else
        cout << "Vershini net v dereve" << endl;
}

//сдп с двойной косвенностью
node *CDP2(node **root, int *D)
{
    node **p = root;
    for (int i = 0; i < 100; i++)
    {
        node **p = root;
        while ((*p) != NULL)
        {
            if (D[i] < (*p)->data)
            {
                p = &((*p)->left);
            }
            else if (D[i] > (*p)->data)
            {
                p = &((*p)->right);
            }
            else // В случае если элемент уже есть
            {
                break;
            }
        }

        if ((*p) == NULL)
        {
            (*p) = new node;
            (*p)->data = D[i];
            (*p)->left = (*p)->right = NULL;
        }
    }
    return (*root);
}
//сдп рекурсивно
node *CDPrec(node *&root, int D)
{

    if (root == NULL)
    {
        root = new node;
        root->data = D;
        root->left = root->right = NULL;
    }
    else if (root->data < D)
    {
        CDPrec(root->right, D);
    }
    else if (root->data > D)
    {
        CDPrec(root->left, D);
    }
    return root;
}

//исдп
void ISDP(int L, int R, node *&p, int *a)
{
    if (L > R)
        p = NULL;
    else
    {
        p = new node;
        int m = (L + R) / 2;
        p->data = a[m];
        ISDP(L, m - 1, p->left, a);
        ISDP(m + 1, R, p->right, a);
    }
}
// void printtree(node *p,node *v ,int l)
// {
//     if (p)
//     {
//         if (p->left )
//         cout << setw(l) << p->data << ' ' << endl;
//         printtree(p->left, l - 2);
//         if (p->right->data > p->left->data && l < 20)
//         {
//             l += 2;
//         }
//         printtree(p->right, l - 2);
//     }
// }
void printtree(node *p, int space)
{

    if (p == NULL)
        return;

    space += 1;

    printtree(p->right, space);

    cout << endl;
    for (int i = 0; i < space; i++)
        cout << " ";
    cout << p->data << "\n";

    printtree(p->left, space);
}
int main()
{
    node *p = NULL;
    const int n = 100;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] == arr[i])
            {
                while (arr[j] == arr[i])
                {
                    arr[i] = rand() % 1000;
                }
            }
        }
    }

    cout << "n=" << n << "    "
         << "Razmer"
         << "    "
         << "KontrolSum"
         << "    "
         << "Visota"
         << "    "
         << "Sredn visota" << endl;
    ISDP(0, 99, p, arr);
    cout << "ISDP"
         << "   ";
    showInfo(p);
    cout << endl;
    p = NULL;
    p = CDP2(&p, arr);
    cout << "SDP"
         << "    ";
    showInfo(p);
    cout << endl;
    // printtree(p, 0);
    // print(v);

    // cout << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     v = CDPrec(p, arr[i]);
    // }
    // int x;
    //cin >> x;
    //serch(p, x);
}