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

    cout << "size: " << check_size(root) << " sum: " << check_sum(root) << " height: " << tree_height(root) + 1 << " mid_height: " << mid_hight(root) << endl;
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
void deleteCDP(int *D, node **root, int x)
{
    node **p = root;
    node *r = NULL;
    node *S = NULL;

    node *q = NULL;
    for (int i = 0; i < x; i++)
    {
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
            else if (D[i] == (*p)->data) // В случае если элемент уже есть
            {
                break;
            }
        }
        if ((*p) != NULL)
        {
            q = *p;
            if (q->left == NULL)
                *p = q->right;
            else if (q->right == NULL)
                *p = q->left;
            else
            {
                r = q->left;
                S = q;

                if (r->right == NULL)
                {

                    r->right = q->right;
                    *p = r;
                }
                else
                {
                    while (r->right != NULL)
                    {
                        S = r;
                        r = r->right;
                    }
                    S->right = r->left;
                    r->left = q->left;
                    r->right = q->right;
                    *p = r;
                }
            }
        }
        p = root;
    }
    delete q;
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
    node *tree = CDP2(&p, arr);

    showInfo(tree);
    int x;
    cout << endl;
    cout << "Vvedite kol-vo simvolov" << endl;
    cin >> x;
    cout << "Vvedite simvol" << endl;
    int *ar = new int[x];
    for (int i = 0; i < x; i++)
    {

        cin >> ar[i];
        cout << endl;
        deleteCDP(ar, &tree, x);
        showInfo(tree);
        cout << endl;
    }

    delete[] ar;
}