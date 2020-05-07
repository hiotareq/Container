#ifndef CONTAINER_LIST_H
#define CONTAINER_LIST_H

#include <iostream>
#include "Container.h"
#include "ListIterator.h"
#include "list_element.h"

template<typename T>
class list : public Container<T> {
public:

    friend class MyListIterator<T>;

    list();

    list ( const list& pre_list);

    ~list();

    list& operator=( const list& pre_list );

    void insert(const T& value);

    void print() const;

    void remove(const T& value);

    bool exists(const T& value) const;

    using iterator=MyListIterator<T>;

    iterator begin() const;
    iterator end() const;
private:

    list_element<T> * root;

    list_element<T>* Create_list_element( const T& value );

    void Delete( const T& value );

    void print_list(const struct list_element<T>* Root ) const;

    list_element<T>* create_list_element( const T& value);

    void insert_into_list( list_element<T>* Root, list_element<T>* new_elem);

    void delete_element(const T& value, list_element<T>* Root);

    void delete_list( list_element<T>* Root);

    bool look_for_element(list_element<T>* Root, const T& value) const;

};
#endif //CONTAINER_LIST_H
