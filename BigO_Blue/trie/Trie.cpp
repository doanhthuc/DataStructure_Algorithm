#include "bits/stdc++.h"

using namespace std;

const int MAX = 26;

struct Node
{
    struct Node *child[MAX];
    int countWord;
};

struct Node *newNode()
{
    Node *node = new Node;
    node->countWord = 0;
    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    return node;
};

void addWord(struct Node *root, string s)
{
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
        {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
    }
    temp->countWord++;
}

bool findWord(Node *root, string s)
{
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
        {
            return false;
        }
        temp = temp->child[ch];
    }
    return temp->countWord > 0;
}

bool isWord(Node *node)
{
    return node->countWord != 0;
}

bool isEmpty(Node *node)
{
    for (int i = 0; i < MAX; i++)
    {
        if (node->child[i] != NULL)
        {
            return false;
        }
    }
    return true;
}

bool removeWord(Node *root, string s, int level, int len)
{
    if (!root)
        return false;
    if (level == len)
    {
        if (root->countWord > 0)
        {
            root->countWord--;
            return true;
        }
        return false;
    }
    int ch = s[level] - 'a';
    int flag = removeWord(root->child[ch], s, level + 1, len);
    if (flag && !isWord(root->child[ch]) && isEmpty(root->child[ch]))
    {
        delete root->child[ch];
        root->child[ch] = NULL;
    }
    return flag;
}

void printWords(Node *root, string s)
{
    if (isWord(root))
    {
        cout << s << endl;
    }
    for (int i = 0; i < MAX; i++)
    {
        if (root->child[i])
        {
            printWords(root->child[i], s + (char)(i + 'a'));
        }
    }
}

int main()
{
    Node *root = new Node();
    addWord(root, "the");
    addWord(root, "then");
    addWord(root, "bigo");
    cout << findWord(root, "there") << endl;
    cout << findWord(root, "th") << endl;
    cout << findWord(root, "the") << endl;
    removeWord(root, "bigo", 0, 4);
    removeWord(root, "the", 0, 4);
    printWords(root, "");
    removeWord(root, "then", 0, 4);
    return 0;
}