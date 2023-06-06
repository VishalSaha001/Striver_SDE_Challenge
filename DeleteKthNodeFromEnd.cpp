/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *recur(Node *head, int k, int &itr)
{
    if (head == NULL)
    {
        itr = 1;
        return NULL;
    }
    head->next = recur(head->next, k, itr);
    if (itr == k)
    {
        itr++;
        return head->next;
    }
    itr++;
    return head;
}

Node *removeKthNode(Node *head, int K)
{
    // Write your code here
    int itr = -1;
    return recur(head, K, itr);
}
