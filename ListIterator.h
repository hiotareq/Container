//
// Created by bobro on 02.05.2020.
//

#ifndef CONTAINER_LISTITERATOR_H
#define CONTAINER_LISTITERATOR_H

#include <iterator>
#include "list_element.h"
#include <stdexcept>

template<typename T>
class MyListIterator {
private:
    list_element<T>* p;
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using pointer =T*;
    using reference =T&;

    using difference_type = std::ptrdiff_t;
    MyListIterator() : p(nullptr) {}
    MyListIterator(list_element<T>* el) : p(el) {}
    MyListIterator(list_element<T>& el) : p(&el) {}

    reference operator*() const{
        if ( *this == NULL)   throw std::exception();
        else    return p->data;
    }

    MyListIterator& operator++(){
        if ( *this == NULL ) throw std::exception();
        p = p->next;
        return *this;
    }
    MyListIterator operator++(int) {
        MyListIterator resp = *this;
        if ( resp == NULL ) throw std::exception();
        p = p->next;
        return resp;
    }

    bool operator==(const MyListIterator& it) const{
        return p == it.p;
    }
    bool operator!=(const MyListIterator& it) const{
        return !(*this == it);
    }
};




#endif //CONTAINER_LISTITERATOR_H
