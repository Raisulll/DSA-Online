//! left e choto and right e boro ba soman value thakbe binary search tree te.
//? binary search tree te inorder search korle sorted list ashe
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *right, *left, *parent;
    node()
    {
        val = 0;
        right = NULL;
        left = NULL;
        parent = NULL;
    }
};
class tree
{
    node *root;

public:
    tree()
    {
        root = NULL;
    }
    bool isEmpty()
    {
        if (root == NULL)
            return true;
        return false;
    }
    void Insert(int x)
    {
        node *item;
        item = new node;
        item->val = x;
        if (isEmpty())
        {
            root = item;
        }
        else
        {
            node *it, *prev;
            it = root;
            prev = NULL;
            while (it != NULL)
            {
                if (it->val > x)
                {
                    prev = it;
                    it = it->left;
                }
                else
                {
                    prev = it;
                    it = it->right;
                }
            }
            if (prev->val > x)
            {
                prev->left = item;
                item->parent = prev;
            }
            else
            {
                prev->right = item;
                item->parent = prev;
            }
        }
    }
    bool search(int x)
    {
        node *it;
        it = root;
        while (it != NULL)
        {
            if (it->val == x)
                return true;
            else if (it->val > x)
            {
                it = it->left;
            }
            else
            {
                it = it->right;
            }
        }
        return false;
    }
    node *findNode(int x)
    {
        node *it;
        it = root;
        while (it != NULL)
        {
            if (it->val == x)
                break;
            else if (it->val > x)
            {
                it = it->left;
            }
            else
            {
                it = it->right;
            }
        }
        return it;
    }
    void Delete(int x)
    {
        node *it=findNode(x);
        if(it==NULL) cout<<"Value not Found\n";
        else
        {
            
        }
    }
};