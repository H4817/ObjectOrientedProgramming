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

private:
    struct node
    {
        int data;
        node *next, *prev;

        node(T const &data, node *next, node *prev)
                : data(data), next(next), prev(prev)
        {
        }

        node(T &&data, node *next, node *prev)
                : data(std::move(data)), next(next), prev(prev)
        {
        }
    };

    node *head = nullptr;
    node *tail = nullptr;
    size_t m_elements = 0;
};


