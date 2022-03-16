#pragma once

namespace CicleList
{

template <typename T>
struct Node
{
    Node* next;
    Node* prev;
    T value;
};

template <typename T>
Node<T>* createCicleList(T value)
{
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

template <typename T>
void deleteCicleList(Node<T>* node)
{
    auto n = node->next;
    while (n != node)
    {
        auto del = n;
        n = n->next;
        delete del;
    }
    delete n;
}

template <typename T>
void addCicleNode(Node<T>* node, T value)
{
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    newNode->next = node->next;
    newNode->prev = node;
    node->next->prev = newNode;
    node->next = newNode;
}

template <typename T>
void printCicleList(Node<T>* node)
{
    auto n = node;
    do
    {
        std::cout << n->value << std::endl;
        n = n->next;
    } while (n != node);
}

}