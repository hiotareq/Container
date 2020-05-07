//
// Created by bobro on 02.05.2020.
//

#ifndef CONTAINER_LIST_ELEMENT_H
#define CONTAINER_LIST_ELEMENT_H

template<class T>
struct list_element{
    T data;
    list_element<T>* next;
};

#endif //CONTAINER_LIST_ELEMENT_H
