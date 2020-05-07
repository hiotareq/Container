//
// Created by bobro on 02.05.2020.
//

#ifndef CONTAINER_CONTAINER_H
#define CONTAINER_CONTAINER_H

template<typename T>
class Container
{
public:
    // Виртуальный деструктор
    Container()=default;
    virtual ~Container()=default;

    /*
     * Виртуальные методы, должны быть реализованы вашим контейнером
     */

    // Вставка элемента
    virtual void insert(const T& value) = 0;

    // Удаление элемента
    virtual void remove(const T& value) = 0;

    // Проверка наличия элемента
    virtual bool exists(const T& value) const = 0;
    virtual void print() const=0;
};

#endif //CONTAINER_CONTAINER_H
