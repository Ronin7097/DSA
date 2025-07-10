#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    bool isTerminal;
    TrieNode *child[26];
    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;
    TrieNode *removeUtil(TrieNode *root, const string &str, int i)
    {
        if (root == NULL)
            return NULL;
        if (i == str.size())
        {
            if (root->isTerminal)
                root->isTerminal = false;
            if (isEmpty(root))
            {
                delete root;
                root = NULL;
            }
            return root;
        }
        root->child[str[i] - 'a'] = removeUtil(root->child[str[i] - 'a'], str, i + 1);
        if (isEmpty(root) && root->isTerminal == false)
        {
            delete root;
            root = NULL;
        }
        return root;
    }
    bool isEmpty(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
            if (root->child[i])
                return false;
        return true;
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(const string &str)
    {
        TrieNode *node = root;
        for (char ch : str)
        {
            int index = ch - 'a';
            if (node->child[index] == nullptr)
                node->child[index] = new TrieNode(ch);
            node = node->child[index];
        }
        node->isTerminal = true;
    }

    bool search(const string &str)
    {
        TrieNode *node = root;
        for (char ch : str)
        {
            int index = ch - 'a';
            if (node->child[index] == nullptr)
                return false;
            node = node->child[index];
        }
        return node->isTerminal;
    }
    void remove(const string &str)
    {
        removeUtil(root, str, 0);
    }
};

// Driver Code
int main()
{
    system("clear");
    Trie *t = new Trie();
    t->insertWord("hello");
    t->insertWord("hell");
    cout << t->search("hell") << endl;
    t->remove("hello");
    cout << t->search("hell") << endl;
    cout << t->search("hello") << endl;
    return 0;
}