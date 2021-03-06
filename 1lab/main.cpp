#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
struct node
{
    int data;
    node *left = NULL, *right = NULL;
};

// void print(node *p)
// {

//     if (p)
//     {
//         cout << p->data << " " << endl;
//         print(p->left);
//         cout << p->left->data << " " << p->right->data << endl;
//         print(p->right);
//     }
// }
void print(node *p, int l)
{
    if (p != NULL)
    {

        if (p->left)
            print(p->left, l + 4);
        cout << p->data << "\n ";
        if (p->right)
            print(p->right, l + 4);

        if (l)
        {
            std::cout << setw(l) << ' ';
        }
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
    cout << "size: " << check_size(root) << " sum: " << check_sum(root) << " height: " << tree_height(root) + 1 << " mid_height: " << mid_hight(root) << endl;
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
void serch(node *p, int x)
{

    while (p)
    {
        if (x < p->data)
        {
            p = p->left;
        }

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
int main()
{

    const int n = 15;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
    node *p = NULL;

    ISDP(0, 14, p, arr);
    print(p, 0);
    int x;
    cin >> x;
    serch(p, x);
    showInfo(p);
}