#include <iostream>
#include <cmath>
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
        print(p->right);
        cout << p->data << " ";
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
void showInfo(node *root)
{
    cout << "size: " << check_size(root) << " sum: " << check_sum(root) << " height: " << tree_height(root) + 1 << " mid_height: " << mid_hight(root) << endl;
    print(root);
}
//шртука на 5+
// struct Trunk
// {
//     Trunk *prev;
//     string str;

//     Trunk(Trunk *prev, string str)
//     {
//         this->prev = prev;
//         this->str = move(str);
//     }
// };
// //показывает какой-то сундук(пока хз что)
// void showTrunks(Trunk *p)
// {
//     if (p == nullptr)
//         return;

//     showTrunks(p->prev);

//     std::cout << p->str;
// }

// void printTree(node *root, Trunk *prev = nullptr, bool isLeft = false)
// {
//     if (root == nullptr)
//         return;

//     std::string prev_str = "    ";
//     Trunk *trunk = new Trunk(prev, prev_str);

//     printTree(root->left, trunk, true);

//     if (!prev)
//         trunk->str = "---";
//     else if (isLeft)
//     {
//         trunk->str = ".---";
//         prev_str = "   |";
//     }
//     else
//     {
//         trunk->str = "`---";
//         prev->str = prev_str;
//     }

//     showTrunks(trunk);
//     std::cout << root->data << std::endl;

//     if (prev)
//         prev->str = prev_str;
//     trunk->str = "   |";

//     printTree(root->right, trunk, false);
// }
node *addVertex(int data, node *left, node *right)
{
    auto *vertex = new node;
    vertex->data = data;
    vertex->left = left;
    vertex->right = right;
    return vertex;
}
node *IDSP(const int array[], int l, int r)
{
    if (l > r)
    {
        return nullptr;
    }
    else
    {
        int m = (int)ceil((double)(l + r) / 2);
        auto p = addVertex(array[m], IDSP(array, l, m - 1), IDSP(array, m + 1, r));
        return p;
    }
}

int main()
{
    const int n = 100;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
    node *tree = IDSP(arr, 0, n - 1);
    showInfo(tree);
    cout << '\n';
    //std::cout << "TreeLenSum = " << treeLenSum(tree, 1) << '\n';
    //  printTree(tree);
    // delTree(tree);
}