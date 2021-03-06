//File: aghElement.h
//Plik zawiera deklaracje klasy Element, ktora definiuje typ danych zawartych w liscie dwukierunkowej aghDlist
//Autor: N. Materek & A. Lisiecki
//21.05.2016 v 1.2
#ifndef AGHELEMENT_H
#define AGHELEMENT_H
#include <iostream>
using namespace std;

template <class T>
class Element{
protected:
        Element *previousElement;
        Element *nextElement;
public:
        T data;

        Element()
        {
            previousElement = NULL;
            nextElement = NULL;
        }

        Element (T value)
        {
            previousElement = NULL;
            nextElement = NULL;
            data = value;
        }

        Element(Element *prev, T value)
        {
            previousElement = prev;
            nextElement = NULL;
            data = value;
        }

        Element* prev()
        {
            return previousElement;
        }

        Element* next()
        {
            return nextElement;
        }

        Element* & operator++()
        {
            return nextElement;
        }

        void setNext(Element* next)
        {
            nextElement = next;
        }

        void setPrev(Element* prev)
        {
            previousElement = prev;
        }

        T getValue()
        {
            return data;
        }

        void setValue(T value)
        {
            data = value;
        }
};
#endif // AGHELEMENT_H
