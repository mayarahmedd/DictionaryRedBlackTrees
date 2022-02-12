// Implementing Red-Black Tree in C++
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>
using namespace std;






struct Node {
  string data;
  Node *parent;
  Node *left;
  Node *right;
  int color;

};

typedef Node *NodePtr;

class RedBlackTree {
   public:
  NodePtr root;
  NodePtr TNULL;
string data;
   protected:

  void initializeNULLNode(NodePtr node, NodePtr parent) {


node->left = node->right = NULL;
    node->parent = parent;

    node->color = 0;
  }



 bool searchTreeHelper(NodePtr node, string key) {
      bool f=false;

          while (node != NULL)
    {
        if (key > node->data)
            node = node->right;

        else if (key < node->data)
            node = node->left;
        else
            {
             f=true;
             //Found
             return f;
            }
    }
    if(f == false)
    {
       //Not Found
        return f;
    }

 }

 int max(int a, int b)
{
    return a>b?a:b;
}

int getheight(NodePtr node)
{
    if ( node==TNULL )
        return -1;
    else
        return 1 + max(getheight(node->left), getheight(node->right));
}
int getSize(NodePtr node)
{
    if ( node==TNULL )
        return 0;
    else
        return 1 + getSize(node->left)+ getSize(node->right);
}

  void printHeighSizetHelper(NodePtr node )
{
    cout << "\nthe height of the tree = ";
    int k=getheight(node);
    cout << k;
    cout << "\n";
    cout << "the Dictionary Size = ";
    int n=getSize(node);
    cout << n;
    cout << "\n";


}


  // For balancing the tree after insertion
  void insertFix(NodePtr k) {
    NodePtr u;
    while (k->parent->color == 1) {
      if (k->parent == k->parent->parent->right) {
        u = k->parent->parent->left;
        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->left) {
            k = k->parent;
            rightRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          leftRotate(k->parent->parent);
        }
      } else {
        u = k->parent->parent->right;

        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            leftRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          rightRotate(k->parent->parent);
        }
      }
      if (k == root) {
        break;
      }
    }
    root->color = 0;
  }



   public:
  RedBlackTree() {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = NULL;
    TNULL->right = NULL;
    root = TNULL;
  }




  void leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
      this->root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void rightRotate(NodePtr x) {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
      this->root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

  // Inserting a node
  void insert(string  key) {
    NodePtr node = new Node;
    node->parent = NULL;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    NodePtr y = NULL;
    NodePtr x = this->root;
 bool f=false;
    f= searchTree(key );
    if(f==false){
        while (x != TNULL) {
      y = x;
      if (node->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == NULL) {
      root = node;
    } else if (node->data < y->data) {
      y->left = node;
    } else {
      y->right = node;
    }

    if (node->parent == NULL) {
      node->color = 0;
      return;
    }

    if (node->parent->parent == NULL) {
      return;
    }

    insertFix(node);
    }
    else
     cout << "\n ERROR: Word already in the dictionary! ";

  }

  bool searchTree(string k) {
    return searchTreeHelper(this->root, k);
  }

 void printHeightSize(){
     return  printHeighSizetHelper(this->root);
 }
 };




int main()
{
    RedBlackTree bst;

   string  str;
   string file;
    ifstream inFile;
    inFile.open("EN-US-Dictionary.txt");
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1);
    }

    while (inFile >> file)
    {
        std::transform(file.begin(), file.end(), file.begin(), ::tolower);
        bst.insert(file);

    }

    int x,y,z;
    do
    {
        system("CLS");

        cout << "1- Insert New Words\n\n";
        cout << "2- Search for a Word\n\n";
        cout << "3- Show the Height of the Tree\n\n";
        cout << "4- Exit\n\n";
        cout << "Enter Command: ";
        cin >>x;
        system("CLS");

        if(x==1)
        {
            z=1;

            cout << "Please enter the word you want to insert:\n";
            cin >> str;
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
            bst.insert(str);
            bst.printHeightSize();
            while(z != 0)
            {
                cout << "Enter 0 to return to Main Menu\n";
                cin >> z;
                if(z==0)
                    y=z;
            }
        }
        if(x==2)
        {
            z=1;

            cout << "Please enter the word you want to search for:\n";
            cin >> str;
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);

            cout << "\nsearch result:\n";
            bool f=false;
            f=bst.searchTree(str);
            if(f==false)
               cout<<"NO\n";
            else
               cout<<"YES\n";
            while(z != 0)
            {
                cout << "Enter 0 to return to Main Menu\n";
                cin >> z;
                if(z==0)
                    y=z;
            }
        }


        if(x==3)
        {
            z=1;
            bst.printHeightSize();
            while(z != 0)
            {
                cout << "Enter 0 to return to Main Menu\n";
                cin >> z;
                if(z==0)
                    y=z;
            }
        }

        if(x==4)
        {
            exit(0);
        }

    }
    while(y==0);
    return 0;
}
