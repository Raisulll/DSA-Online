#include <bits/stdc++.h>
using namespace std;
#define int long long
class Node
{
public:
    Node *left, *right, *parent;
    int ISBN, quantity;
    float price;
    string title, author;
    Node(int i, string t, string a, float p, int q)
    {
        left = NULL, right = NULL, parent = NULL;
        ISBN = i;
        title = t;
        author = a;
        price = p;
        quantity = q;
    }
    void display()
    {
        cout << "ISBN: " << ISBN << "\nTitle: " << title << "\nAuthor: " << author << "\nPrice: $" << price << "\nQuantity: " << quantity << "\n\n";
    }
};

class BFS
{
    Node *root;

public:
    BFS()
    {
        root = NULL;
    }
    void insert(int i, string t, string a, float p, int q)
    {
        Node *newitem;
        newitem = new Node(i, t, a, p, q);
        if (root == NULL)
        {
            root = newitem;
        }
        else
        {
            Node *cur, *prev;
            cur = root, prev = NULL;
            while (cur != NULL)
            {
                prev = cur;
                if (newitem->ISBN < cur->ISBN)
                {
                    cur = cur->left;
                }
                else
                {
                    cur = cur->right;
                }
            }
            newitem->parent = prev;
            if (newitem->ISBN < prev->ISBN)
            {
                prev->left = newitem;
            }
            else
            {
                prev->right = newitem;
            }
        }
    }
    Node *Find_element(int n)
    {
        Node *it;
        it = root;
        while (it != NULL)
        {
            if (n == it->ISBN)
            {
                break;
            }
            else if (n < it->ISBN)
            {
                it = it->left;
            }
            else
                it = it->right;
        }
        return it;
    }
    void Delete_element(int n)
    {
        Node *it, *prev;
        it = root;
        while (it != NULL)
        {
            if (n == it->ISBN)
            {
                break;
            }
            else if (n < it->ISBN)
            {
                it = it->left;
            }
            else
                it = it->right;
        }
        if (it->left == NULL and it->right == NULL)
        {
            if (it == root)
            {
                root = NULL;
            }
            else
            {
                Node *prev = it->parent;
                if (it->ISBN < prev->ISBN)
                {
                    prev->left = NULL;
                }
                else
                {
                    prev->right = NULL;
                }
            }
            delete it;
        }
        else if ((it->right == NULL and it->left != NULL) or (it->right != NULL and it->left == NULL))
        {
            if (it == root)
            {
                if (it->left != NULL)
                    root = it->left;
                else
                    root = it->right;
                delete it;
            }
            else if (it->right == NULL and it->left != NULL)
            {
                Node *next, *prev;
                prev = it->parent;
                next = it->left;
                next->parent = prev;
                if (it->ISBN < prev->ISBN)
                {
                    prev->left = next;
                }
                else
                {
                    prev->right = next;
                }
                delete it;
            }
            else 
            {
                Node *next, *prev;
                prev = it->parent;
                next = it->right;
                next->parent = prev;
                if (it->ISBN < prev->ISBN)
                {
                    prev->left = next;
                }
                else
                {
                    prev->right = next;
                }
                delete it;
            }
        }
        else
        {
            Node *temp, *prev,*l,*r,*ch;
            temp = Successor(it->right);
            prev=temp->parent;
            if(temp->right!=NULL)
            {
                ch=temp->right;
                prev->left=ch;
                ch->parent=prev;
            }
            else
            {
                prev->left=NULL;
            }
            temp->parent=it->parent;
            temp->right=it->right;
            temp->left=it->left;
            if(it!=root)
            {
                prev=temp->parent;
                if(temp->ISBN<prev->ISBN)
                {
                    prev->left=temp;
                }
                else prev->right=temp;
            }
            else
            {
                root=temp;
            }
            l=it->left;
            r=it->right;
            r->parent=temp;
            l->parent=temp;
            delete it;
        }
    }
    Node *Successor(Node *it)
    {
        while (it->left != NULL)
        {
            it = it->left;
        }
        return it;
    }
    void Update_quantity(int i, int n)
    {
        Node *it;
        it = root;
        while (it != NULL)
        {
            if (it->ISBN == i)
            {
                it->quantity = n;
                break;
            }
            else if (i < it->ISBN)
                it = it->left;
            else
                it = it->right;
        }
    }
    void printing_level_order()
    {
        Node *it;
        it = root;
        queue<Node *> q;
        q.push(it);
        while (!q.empty())
        {
            Node *temp = q.front();
            temp->display();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
};

int32_t main()
{
    BFS l;
    while (1)
    {
        cout << "\t1.Add a book to the inventory.\n";
        cout << "\t2.Remove a book from a inventory.\n";
        cout << "\t3.Update the quantity of a book.\n";
        cout << "\t4.Search for a book by ISBN.\n";
        cout << "\t5.Display all the book in inventory.\n";
        cout << "\t6.Exit.\n\n";
        cout << "Enter your choice: ";
        int ch, x, y;
        cin >> ch;
        cout << endl;
        if (ch == 1)
        {
            int isbn, quantity;
            string title, author;
            float price;
            cout << "Enter the book's ISBN: ", cin >> isbn;
            cin.ignore();
            cout << "Enter the book's title: ", getline(cin, title);
            cout << "Enter the book's author: ", getline(cin, author);
            cout << "Enter the book's price: ", cin >> price;
            cout << "Enter the book's quantity: ", cin >> quantity;
            l.insert(isbn,title, author, price,quantity);
            cout << "Book added to the inventory successfully.\n\n";
        }
        else if (ch == 2)
        {
            cout << "Enter the ISBN of the book to remove: ", cin >> x;
            l.Delete_element(x);
            cout << "Book removed from the inventory succesfully.\n\n";
        }
        else if (ch == 3)
        {
            cout << "Enter the ISBN of the book to add new quantity: ", cin >> x;
            cout << "New quantity of ISBN " << x << " :", cin >> y;
            l.Update_quantity(x, y);
            Node *it = l.Find_element(x);
            cout << "New quantity of ISBN " << x << " is " << y << "\n\n";
        }
        else if (ch == 4)
        {
            cout << "Enter the ISBN of the book to search: ", cin >> x;
            Node *it = l.Find_element(x);
            if (it != NULL)
                it->display();
        }
        else if (ch == 5)
        {
            cout << "Inventory: \n\n";
            l.printing_level_order();
        }
        else
            break;
    }
}
/*
1
20
1
10
1
30
1
5
1
15
1
27
1
40
1
3
1
6
1
21
1
35
1
45

*/