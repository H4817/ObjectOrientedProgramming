#include <iostream>
#include <memory>


class CStringStack
{

    struct Node
    {
        std::string data;
        Node *next;
    };


public:

    CStringStack(std::string str);

    CStringStack();

    Node *InitializeNode(std::string str);

    Node *Append(Node *lst, std::string str);

    Node *DeleteElement(Node *lst, Node *root);

    Node *DeleteHead(Node *root);

    void Print(Node *lst);

private:
    Node *m_list;
    size_t m_size = 0;
};


