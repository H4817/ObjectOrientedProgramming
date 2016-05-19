#include <malloc.h>
#include "StringStack.h"

CStringStack::CStringStack(std::string str)
{
    InitializeNode(str);
}

CStringStack::CStringStack()
{ }

CStringStack::Node *CStringStack::InitializeNode(std::string str)
{
    Node *lst;
    lst = (Node *) malloc(sizeof(Node));
    lst->data = str;
    lst->next = NULL;
    return (lst);
}

CStringStack::Node *CStringStack::Append(Node *lst, std::string str)
{
    Node *temp;
    Node *p;
    try
    {
        if (!(temp = (Node *) malloc(sizeof(Node))))
        {
            throw std::invalid_argument("Out of memory");
        }
        else
        {
            p = lst->next;
            lst->next = temp;
            temp->data = str;
            temp->next = p;
        }
    }
    catch (std::exception const &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Unknown error with append block\n";
    }
    return (temp);
}

CStringStack::Node *CStringStack::DeleteElement(Node *lst, Node *root)
{
    Node *temp;
    temp = root;
    while (temp->next != lst)
    {
        temp = temp->next;
    }
    temp->next = lst->next;
    free(lst);
    return (temp);
}

CStringStack::Node *CStringStack::DeleteHead(Node *root)
{
    Node *temp;
    temp = root->next;
    free(root);
    return (temp);
}

void CStringStack::Print(Node *lst)
{
    Node *p;
    p = lst;
    do
    {
        std::cout << p->data << std::endl;
        p = p->next;
    }
    while (p);
}
