/*
 * list.h
 *
 *  Created on: 2026-10-01
 *      Author: Miguel Ángel López (A01714510)
 */
#ifndef LIST_H
#define LIST_H
#include <sstream>
#include <string>

template <class T> class List;

template <class T> class Node {
private:
  T value;
  Node<T> *next_node;

public:
  Node(T val) : value(val), next_node(NULL) {};
  friend class List<T>;
};

template <class T> class List {
private:
  int size;
  Node<T> *head;

public:
  void insertion(T val) {
    Node<T> *new_node = new Node<T>(val);
    Node<T> *current_node = head;

    if (size == 0) {
      head = new_node;
    } else {
      while (current_node->next_node != NULL) {
        current_node = current_node->next_node;
      }

      current_node->next_node = new_node;
    }

    size++;
  }
  int search(T val) {
    if (size == 0) {
      return -1;
    }
    Node<T> *current_node = head;

    for (int i = 0; i < size; i++) {
      if (current_node->value == val) {
        return i;
      }

      current_node = current_node->next_node;
    }

    return -1;
  }

  void update(int position, T val) {
    Node<T> *current_node = head;

    for (int i = 0; i < position; i++) {
      current_node = current_node->next_node;
    }
    current_node->value = val;
  };

  T deleteAt(int position) {
    if (position == 0) {
      Node<T> *old_node = head;
      T value = old_node->value;
      head = head->next_node;
      delete old_node;
      size--;
      return value;
    }

    Node<T> *previous = head;

    for (int i = 0; i < position - 1; i++) {
      previous = previous->next_node;
    }

    Node<T> *old_node = previous->next_node;
    T value = old_node->value;

    previous->next_node = old_node->next_node;

    delete old_node;
    size--;

    return value;
  }

  List() {
    head = NULL;
    size = 0;
  }
  ~List() {
    while (head != nullptr) {
      Node<T> *temp = head;
      head = head->next_node;
      delete temp;
    }
  }

  std::string toString() const {
    std::stringstream aux;
    Node<T> *p;

    p = head;
    aux << "[";
    while (p != 0) {
      aux << p->value;
      if (p->next_node != 0) {
        aux << ", ";
      }
      p = p->next_node;
    }
    aux << "]";
    return aux.str();
  }
};

#endif
