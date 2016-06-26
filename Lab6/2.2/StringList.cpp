#include "StringList.h"


CStringList::~CStringList()
{
    Clear();
}

size_t CStringList::GetSize() const
{
    return m_size;
}

const std::string &CStringList::GetFrontElement()
{
    if (m_head)
        return m_head->m_data;
    else
        throw;
}

const std::string &CStringList::GetFrontElement() const
{
    if (m_head)
        return m_head->m_data;
    else
        throw;
}

const std::string &CStringList::GetBackElement()
{
    if (m_tail)
        return m_tail->m_data;
    else
        throw;

}

const std::string &CStringList::GetBackElement() const
{
    if (m_tail)
        return m_tail->m_data;
    else
        throw;
}

bool CStringList::IsEmpty() const
{
    return m_size == 0;
}

void CStringList::Clear()
{
    while (m_head)
    {
        Node *current = m_head;
        m_head = m_head->m_next;
        delete current;
    }
    m_head = m_tail = nullptr;
    m_size = 0;
}

void CStringList::PushBack(const std::string &value)
{
    Node *newNode = new Node(value, nullptr, m_tail);
    if (m_head == nullptr)
        m_head = newNode;
    if (m_tail != nullptr)
        m_tail->m_next = newNode;
    m_tail = newNode;
    ++m_size;
}

void CStringList::PushFront(const std::string &value)
{
    Node *newNode = new Node(value, m_head, nullptr);
    if (m_tail == nullptr)
        m_tail = newNode;
    if (m_head != nullptr)
        m_head->m_prev = newNode;
    m_head = newNode;
    ++m_size;
}

void CStringList::Insert(const ListIterator &listIterator, const std::string &value)
{

    if (listIterator == begin())
    {
        PushFront(value);
    }
    else if (listIterator == end())
    {
        PushBack(value);
    }
    else
    {
        Node *node = new Node(value, std::move(listIterator->m_prev->m_next), listIterator->m_prev);
        listIterator->m_prev = std::move(node);
        node->m_prev->m_next = std::move(node);
    }
}

void CStringList::Erase(const ListIterator &listIterator)
{
    if (m_size == 1)
    {
        Clear();
        return;
    }
    if (listIterator == begin())
    {
        listIterator->m_next->m_prev = nullptr;
        m_head = std::move(listIterator->m_next);
    }
    else
    {
        listIterator->m_next->m_prev = std::move(listIterator->m_prev);
        listIterator->m_prev->m_next = std::move(listIterator->m_next);
    }
    if (m_size > 0)
    {
        m_size--;
    }
}

CStringList::CStringList(CStringList &cMyList)
{
    CStringList tmp;
    for (auto &it : cMyList)
    {
        tmp.PushBack(it);
    }
    std::swap(m_head, tmp.m_head);
    std::swap(m_tail, tmp.m_tail);
    std::swap(m_size, tmp.m_size);
}
