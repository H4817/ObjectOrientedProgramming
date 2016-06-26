#pragma once

#include <iostream>
#include <new>
#include <algorithm>
#include <string>
#include <memory>
#include <bitset>

class CStringList
{
    struct Node
    {
        std::string m_data;
        Node *m_next;
        Node *m_prev;

        Node(std::string const &data, Node *next, Node *prev)
                : m_data(data), m_next(next), m_prev(prev)
        {
        }

        Node(std::string &&data, Node *next, Node *prev)
                : m_data(std::move(data)), m_next(next), m_prev(prev)
        {
        }
    };

public:
    CStringList() = default;

    ~CStringList();

    size_t GetSize() const;

    const std::string &GetFrontElement();

    const std::string &GetFrontElement() const;

    const std::string &GetBackElement();

    const std::string &GetBackElement() const;

    bool IsEmpty() const;

    void Clear();

    void PushBack(const std::string &value);

    void PushFront(const std::string &value);

    template<typename P>
    class CListIterator : public std::iterator<std::bidirectional_iterator_tag, P>
    {
    public:
        CListIterator(Node *value, bool isReverse)
                : m_node(value), m_isReverse(isReverse)
        { }

        friend class CStringList;

        bool operator!=(CListIterator const &other) const
        {
            return m_node != other.m_node;
        }

        bool operator==(CListIterator const &other) const
        {
            return m_node == other.m_node;
        }

        std::string &operator*() const
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

        Node *operator->() const
        {
            return m_node;
        }

    private:
        Node *m_node = nullptr;
        bool m_isReverse = false;
    };

    typedef CListIterator<std::string> ListIterator;
    typedef CListIterator<const std::string> ConstListIterator;

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

/*
    const ConstListIterator cbegin() const
    {
        return ListIterator(m_head, false);
    }

    const ConstListIterator cend() const
    {
        return ListIterator(m_tail->m_next, false);
    }

    const ConstListIterator crbegin() const
    {
        return ListIterator(m_tail, true);
    }

    const ConstListIterator crend() const
    {
        return ListIterator(m_head->m_prev, true);
    }
*/

    void Insert(const ListIterator &listIterator, const std::string &value);

    CStringList(CStringList &cMyList);

    void Erase(const ListIterator &listIterator);
private:
    Node *m_head = nullptr;
    Node *m_tail = nullptr;
    size_t m_size = 0;
};


