#pragma once

#include <iostream>
#include <list>
#include <exception>

template <class T>
struct MyComparator
{
    /**
     * @brief Functor to compare two objects of type T.
     * @param a The first object to compare.
     * @param b The second object to compare.
     * @return true if a is less than b, false otherwise.
     */
    bool operator()(const T& a, const T& b)
    {
        return a < b;
    }
};


template <class T>
class PriorityQueue
{
public:
    /**
     * @brief Inserts an element into the priority queue.
     * @param t The element to insert.
     */
    void push(const T& t);

    /**
     * @brief Removes and returns the element with the highest priority from the priority queue.
     * @return The element with the highest priority.
     * @throws std::exception if the priority queue is empty.
     */
    T poll();

private:
    std::list<T> _queue;
    MyComparator<T> cmp;
};

template <class T>
void PriorityQueue<T>::push(const T& item)
{
    for (auto it = _queue.begin(); it != _queue.end(); ++it)
    {
        if (cmp(item, *it))
        {
            _queue.insert(it, item);
            return;
        }
    }
    _queue.push_back(item); // If item has the highest priority
}

template <class T>
T PriorityQueue<T>::poll()
{
    if (_queue.empty())
    {
        throw std::exception("PriorityQueue empty !");
    }
    T returnedVal = _queue.front();
    _queue.pop_front();
    return returnedVal;
}
