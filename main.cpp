#include <iostream>
#include <vector>

using namespace std;

struct list
{
	int data;
	list *next;
};

int firstTaskFind(int findingElement, vector<list *> collisions)
{
	for (int i = 0; i < collisions.size(); i++)
	{
		list *p = collisions[i];
		while (p->next != NULL)
		{
			if (p->data != findingElement)
			{
				p = p->next;
			}
			else
				return p->data;
		}
	}
	return 0;
}

void firstTask(vector<int> input)
{
	int findingElement;
	int m = 7;
	cout << "Print finding element" << endl;
	cin >> findingElement;

	vector<list *> table;
	for (int i = 0; i < m; i++)
	{
		table.push_back(new list);
		table[i]->next = NULL;
	}

	for (int i = 0; i < input.size(); i++)
	{
		list *p = table[input[i] % m];
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = new list;
		p = p->next;
		p->next = NULL;
		p->data = input[i];
	}

	for (int i = 0; i < m; i++)
	{

		cout << i << ": ";
		list *p = table[i]->next;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	cout << endl
		 << "Finding element: " << findingElement << endl;
	if (firstTaskFind(findingElement, table) != 0)
	{
		cout << "Element " << findingElement << " is found";
	}
	else
		cout << "Element " << findingElement << " was not found";
}

int secondTaskSquare(vector<int> input, int m)
{
	cout << "---------------second task(square method)---------------" << endl;
	vector<int> table;
	int step2 = 0;
	int flag = 0;
	int mod2;
	//init table
	int coll = 0;
	for (int i = 0; i < m; i++)
	{
		table.push_back(-1);
	}

	for (int i = 0; i < m; i++)
	{
		if (flag == 0)
		{
			int step = 1;
			if (table[input[i] % m] == -1)
			{
				table[input[i] % m] = input[i];
			}
			else
			{
				int mod = input[i] % m;
				while (mod < m)
				{
					if (table[mod] == -1)
					{
						table[mod] = input[i];
						break;
					}
					else
					{
						mod += step;
						step += 2;
						coll++;
					}
					if (mod >= m)
					{
						mod -= m;
					}

					if (table[mod] == -1)
					{
						table[mod] = input[i];
						break;
					}
					else
					{

						mod += step;
						step += 2;
						coll++;
						if (step > m)
						{
							flag = 1;
							//coll--;
						}
					}
				}
			}
		}
	}
	cout << "Num\t";
	for (int i = 0; i < m; i++)
	{
		cout << i << "\t";
	}
	cout << endl
		 << "Symb\t";
	for (int i = 0; i < m; i++)
	{
		if (table[i] != -1)
		{
			cout << table[i] << "\t";
		}
		else
		{
			cout << "  \t";
		}
	}

	return coll;
}

int secondTaskLinear(vector<int> input, int m)
{
	cout << endl
		 << "---------------second task(linear method)---------------" << endl;
	vector<int> table;

	int coll = 0;
	for (int i = 0; i < m; i++)
	{
		table.push_back(-1);
	}

	for (int i = 0; i < m; i++)
	{
		int step = 1;
		if (table[input[i] % m] == -1)
		{
			table[input[i] % m] = input[i];
		}
		else
		{
			int mod = input[i] % m;
			while (mod < m)
			{
				if (table[mod] == -1)
				{
					table[mod] = input[i];
					break;
				}
				else
				{
					mod += step;
					coll++;
				}
			}
			if (mod >= m)
			{
				mod -= m;
				while (mod < m)
				{
					if (table[mod] == -1)
					{
						table[mod] = input[i];
						break;
					}
					else
					{
						mod += step;
						coll++;
					}
				}
			}
		}
	}

	cout << "Num\t";
	for (int i = 0; i < m; i++)
	{
		cout << i << "\t";
	}
	cout << endl
		 << "Symb\t";
	for (int i = 0; i < m; i++)
	{
		if (table[i] != -1)
		{
			cout << table[i] << "\t";
		}
		else
		{
			cout << "  \t";
		}
	}
	cout << endl
		 << endl;
	return coll;
}
void printStat(int size, int N, int linearColl, int squareColl)
{
	cout << "size\t"
		 << "quantity\t"
		 << "linear collisions\t"
		 << "square  collisions" << endl;
	cout << size << "\t" << N << "\t\t" << linearColl << "\t\t\t" << squareColl;
}

int main()
{
	int m = 10;

	//vector<int> input = {1, 3, 4, 5, 6, 7, 8, 10, 13, 14, 9};
	vector<int> input = {1, 23, 46, 89, 102, 78, 90, 45, 32, 56, 44, 34, 67, 11};
	cout << "---------------first task---------------" << endl;
	firstTask(input);
	cout << endl
		 << endl;
	printStat(m, (int)input.size(), secondTaskLinear(input, m), secondTaskSquare(input, m));
}