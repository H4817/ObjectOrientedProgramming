#pragma once

#include <iostream>
#include <new>
#include <algorithm>


template<typename T>

class CMyList
{
public:
    CMyList() = default;

    CMyList(const CMyList &cMyList)
    { }

    size_t GetSize() const
    { return m_elements; }

    void Append(const T &data);

    T &GetBackElement()
    {
        return m_tail->m_data;
    }

    T const &GetBackElement() const;

    bool IsEmpty()
    {
        return m_elements == 0;
    }

/*    void Clear()
    {
        while ()
        {

        }
    }*/

    void PushBack(const T &value = T())
    {
        Node *newNode = new Node(value, nullptr, m_tail);
        if (m_head == nullptr)
            m_head = newNode;
        if (m_tail != nullptr)
            m_tail->m_next = newNode;
        m_tail = newNode;
        ++m_elements;
    }

    void PushFront(const T &value = T())
    {
        Node *newNode = new Node(value, m_head, nullptr);
        if (m_tail == nullptr)
            m_tail = newNode;
        if (m_head != nullptr)
            m_head->m_prev = newNode;
        m_head = newNode;
        ++m_elements;
    }

private:
    struct Node
    {
        T m_data;
        Node *m_next, *m_prev;

        Node(T const &data, Node *next, Node *prev)
                : m_data(data), m_next(next), m_prev(prev)
        {
        }

        Node(T &&data, Node *next, Node *prev)
                : m_data(std::move(data)), m_next(next), m_prev(prev)
        {
        }
    };

    Node *m_head = nullptr;
    Node *m_tail = nullptr;
    size_t m_elements = 0;
};


