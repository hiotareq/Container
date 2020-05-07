#include <iostream>
#include "Container.h"
#include "List.h"
#include <stdexcept>

template<typename T>
    list<T>::list():root(nullptr) {}

	template<typename T>
	list<T>::list ( const list& pre_list){
	    root = create_list_element( pre_list.root -> data );
	    list_element<T>* cur_elem = root;
	    list_element<T>* cur_elem_pre = pre_list.root;
	    while ( cur_elem_pre -> next != nullptr ){
	        cur_elem_pre = cur_elem_pre->next;
	        cur_elem->next = create_list_element( cur_elem_pre -> data);
	        cur_elem = cur_elem->next;
	    }
	}

	template<typename T>
	list<T>::~list() {
    delete_list( root );
}

    template<typename T>
	list<T>& list<T>:: operator=( const list& pre_list ){
        if ( pre_list.root == root ) return *this;
        if ( root != nullptr ) (*this).delete_list(root );
        root = create_list_element( pre_list.root -> data );
        list_element<T>* cur_elem = root;
        list_element<T>* cur_elem_pre = pre_list.root;
        while ( cur_elem_pre -> next != nullptr ){
            cur_elem_pre = cur_elem_pre->next;
            cur_elem->next = create_list_element( cur_elem_pre->data);
            cur_elem = cur_elem->next;
        }
        return *this;
	}

	template<typename T>
	void list<T>::insert(const T& value) {
		if (root == nullptr)
		{
			root = create_list_element(value);
		}
		else
		{
			insert_into_list(root, create_list_element(value));
		}
	}

template<typename T>
	void list<T>::print() const	{
		print_list(root);
	}

template<typename T>
	bool list<T>::exists(const T& value) const {
		return look_for_element(root, value);
	}

template<typename T>
	void list<T>::remove(const T& value)	{
		Delete(value);
	}

template<typename T>
    using iterator=MyListIterator<T>;

template<typename T>
    iterator<T> list<T>::begin() const{
        if ( root == nullptr ) return nullptr;
        return MyListIterator<T>(root);
    }

template<typename T>
    iterator<T> list<T>::end() const{
        return nullptr;
    }

template<typename T>
	list_element<T>* list<T>:: Create_list_element( const T& value )	{
		return create_list_element( value );
	}

	template<typename T>
	void list<T>::Delete( const T& value ) {
        if (look_for_element(root, value)) {
            if (value == root->data) {
                list_element<T> *e = root;
                root = root->next;
                delete e;
            } else {
                delete_element(value, root);
            }
        }
        else return;
	}

template<typename T>
	void list<T>::print_list(const struct list_element<T>* Root ) const	{
		while (Root != nullptr)
		{
			std::cout << Root->data << std::endl;
			Root = Root->next;
		}
	}

	template<typename T>
	list_element<T>* list<T>::create_list_element( const T& value) {
		auto elem = new list_element<T>;
		elem->data = value;
		elem->next = nullptr;
		return elem;
	}

	template<typename T>
	void list<T>::insert_into_list( list_element<T>* Root, list_element<T>* new_elem) {
		new_elem->next = Root->next;
		Root->next = new_elem;
	}

template<typename T>
	void list<T>::delete_element(const T& value, list_element<T>* Root) {
		list_element<T>* cur_elem, * pre_elem;
		pre_elem = Root;
		cur_elem = Root;
		while (cur_elem->data != value)
		{
			if ((cur_elem->next == nullptr) & (cur_elem->data != value))
			{
				return;
			}
			cur_elem = cur_elem->next;
		}
		while (pre_elem->next != cur_elem)
		{
			pre_elem = pre_elem->next;
		}
		pre_elem->next = cur_elem->next;
		delete cur_elem;
	}

template<typename T>
	void list<T>::delete_list( list_element<T>* Root)	{
	    if (Root==nullptr) return;
		list_element<T>* cur_elem, * next_elem;
		cur_elem = Root;
		while (cur_elem->next != nullptr)
		{
			next_elem = cur_elem->next;
			delete cur_elem;
			cur_elem = next_elem;
		}
		delete cur_elem;
	}

template<typename T>
	bool list<T>::look_for_element(list_element<T>* Root, const T& value) const	{
		if (Root == nullptr) return false;
	    list_element<T>* cur_elem = Root;
		while (cur_elem->data != value)
		{
			if (cur_elem->next == nullptr ) return false;
			cur_elem = cur_elem->next;
		}
		return true;
	}