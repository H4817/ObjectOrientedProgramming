#pragma once

#include <iostream>
#include <new>
#include <algorithm>
#include <cassert>
#include <string>
#include <memory>


template<typename T>

class CMyList
{
    struct Node
    {
        T m_data;
        Node *m_next;
        Node *m_prev;

        Node(T const &data, Node *next, Node *prev)
                : m_data(data), m_next(next), m_prev(prev)
        {
        }

        Node(T &&data, Node *next, Node *prev)
                : m_data(std::move(data)), m_next(next), m_prev(prev)
        {
        }
    };

public:
    CMyList() = default;

    ~CMyList()
    {
        Clear();
    }

    CMyList(const CMyList &cMyList) : m_head(cMyList.m_head), m_tail(cMyList.m_tail), m_elements(cMyList.m_elements)
    {
    }

    size_t GetSize() const
    {
        return m_elements;
    }

    T &GetBackElement()
    {
        return m_tail->m_data;
    }

    bool IsEmpty()
    {
        return m_elements == 0;
    }

    void Clear()
    {
        Node *curr = m_head;
        while (m_head)
        {
            curr = m_head;
            m_head = m_head->m_next;
            delete curr;
        }
        m_head = m_tail = nullptr;
        m_elements = 0;
    }

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

    template<typename P>
    class CListIterator : public std::iterator<std::random_access_iterator_tag, P>
    {
    public:
        CListIterator(Node *value, bool isReverse = false)
                : m_node(value), m_isReverse(isReverse)
        { }

        friend class CMyList<T>;

        bool operator!=(CListIterator const &other) const
        {
            return m_node != other.m_node;
        }

        bool operator==(CListIterator const &other) const
        {
            return m_node == other.m_node;
        }

        P &operator*() const
        {
            return m_node->m_data;
        }

        CListIterator &operator++()
        {
            m_isReverse ? m_node = m_node->m_prev : m_node = m_node->m_next;
            return *this;
        }

        CListIterator &operator--()
        {
            m_isReverse ? m_node = m_node->m_next : m_node = m_node->m_prev;
            return *this;
        }

    private:
        Node *operator->() const
        {
            return m_node;
        }

        Node *m_node = nullptr;
        bool m_isReverse = false;
    };

    typedef CListIterator<T> ListIterator;

    ListIterator begin()
    {
        return ListIterator(m_head, false);
    }

    ListIterator end()
    {
        return ListIterator(m_tail->m_next, false);
    }

    ListIterator rbegin()
    {
        return ListIterator(m_tail, true);
    }

    ListIterator rend()
    {
        return ListIterator(m_head->m_prev, true);
    }

private:
    Node *m_head = nullptr;
    Node *m_tail = nullptr;
    size_t m_elements = 0;
};


