#pragma once

#include <iostream>
#include <new>
#include <algorithm>


template<typename T>

class CMyList
{
public:
    CMyList() = default;

    size_t GetSize() const
    { return m_elements; }

    void Append(const T &data);

    T &GetBackElement();

    T const &GetBackElement() const;

    bool IsEmpty();

    void Clear();

    void Push(const T & value = T())
    {
        try
        {
            node* newNode = new node(value, nullptr, m_tail);
            if(m_head == nullptr)
                m_head = newNode;
            if(m_tail != nullptr)
                m_tail->m_next = newNode;
            m_tail = newNode;
            ++m_elements;
        }
        catch (std::exception const &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
private:
    struct node
    {
        T m_data;
        node *m_next, *m_prev;

        node(T const &data, node *next, node *prev)
                : m_data(data), m_next(next), m_prev(prev)
        {
        }

        node(T &&data, node *next, node *prev)
                : m_data(std::move(data)), m_next(next), m_prev(prev)
        {
        }
    };

    node *m_head = nullptr;
    node *m_tail = nullptr;
    size_t m_elements = 0;
};


