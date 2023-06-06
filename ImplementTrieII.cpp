#include <bits/stdc++.h>
class Node
{
public:
    Node *children[26];
    int endCnt, cnt;

    Node()
    {
        memset(children, NULL, sizeof(children));
        endCnt = cnt = 0;
    }
};

class Trie
{

private:
    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        Node *pcrawl = root;
        for (char c : word)
        {
            if (pcrawl->children[c - 'a'] == NULL)
                pcrawl->children[c - 'a'] = new Node();

            pcrawl = pcrawl->children[c - 'a'];
            pcrawl->cnt++;
        }
        pcrawl->endCnt++;
    }

    int countWordsEqualTo(string &word)
    {
        Node *pcrawl = root;
        for (char c : word)
        {
            if (pcrawl->children[c - 'a'] == NULL)
                return 0;

            pcrawl = pcrawl->children[c - 'a'];
        }
        return pcrawl->endCnt;
    }

    int countWordsStartingWith(string &word)
    {
        Node *pcrawl = root;
        for (char c : word)
        {
            if (pcrawl->children[c - 'a'] == NULL)
                return 0;

            pcrawl = pcrawl->children[c - 'a'];
        }
        return pcrawl->cnt;
    }

    void erase(string &word)
    {
        Node *pcrawl = root;
        for (char c : word)
        {
            pcrawl = pcrawl->children[c - 'a'];
            pcrawl->cnt--;
        }
        pcrawl->endCnt--;
    }
};
