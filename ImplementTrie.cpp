/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
#include <bits/stdc++.h>
class Node
{
public:
    Node *children[26];
    bool isEnd;

    Node()
    {
        memset(children, NULL, sizeof(children));
        isEnd = false;
    }
};
class Trie
{

private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *pcrawl = root;
        for (char c : word)
        {
            if (pcrawl->children[c - 'a'] == NULL)
                pcrawl->children[c - 'a'] = new Node();
            pcrawl = pcrawl->children[c - 'a'];
        }
        pcrawl->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *pcrawl = root;
        for (char c : word)
        {
            if (pcrawl->children[c - 'a'] == NULL)
                return false;

            pcrawl = pcrawl->children[c - 'a'];
        }
        return pcrawl->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *pcrawl = root;
        for (char c : prefix)
        {
            if (pcrawl->children[c - 'a'] == NULL)
                return false;

            pcrawl = pcrawl->children[c - 'a'];
        }
        return true;
    }
};