#pragma once

#include <iostream>
#include <new>
#include <algorithm>
#include <string>
#include <memory>
#include <bitset>


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


    size_t GetSize() const
    {
        return m_size;
    }

    const T &GetBackElement()
    {
        if (m_tail)
            return m_tail->m_data;
        else
            throw;
    }

    const T &GetBackElement() const
    {
        if (m_tail)
            return m_tail->m_data;
        else
            throw;
    }

    bool IsEmpty() const
    {
        return m_size == 0;
    }


    void Clear()
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

    void PushBack(const T &value)
    {
        Node *newNode = new Node(value, nullptr, m_tail);
        if (m_head == nullptr)
            m_head = newNode;
        if (m_tail != nullptr)
            m_tail->m_next = newNode;
        m_tail = newNode;
        ++m_size;
    }

    void PushFront(const T &value)
    {
        Node *newNode = new Node(value, m_head, nullptr);
        if (m_tail == nullptr)
            m_tail = newNode;
        if (m_head != nullptr)
            m_head->m_prev = newNode;
        m_head = newNode;
        ++m_size;
    }

    template<typename P>
    class CListIterator : public std::iterator<std::bidirectional_iterator_tag, P>
    {
    public:
        CListIterator(Node *value, bool isReverse)
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

        Node *operator->() const
        {
            return m_node;
        }

    private:
        Node *m_node = nullptr;
        bool m_isReverse = false;
    };

    typedef CListIterator<T> ListIterator;
    typedef CListIterator<const T> ConstListIterator;

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

    void Insert(const ListIterator &listIterator, const T &value)
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

    CMyList(CMyList &cMyList)
    {
        CMyList<T> tmp;
        for (auto &it : cMyList)
        {
            tmp.PushBack(it);
        }
        std::swap(m_head, tmp.m_head);
        std::swap(m_tail, tmp.m_tail);
        std::swap(m_size, tmp.m_size);
    }

    void Erase(const ListIterator &listIterator)
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

private:
    Node *m_head = nullptr;
    Node *m_tail = nullptr;
    size_t m_size = 0;
};


