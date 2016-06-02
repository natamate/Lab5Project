// File: aghContainer.h
// Author: Natalia Materek, Aleksander Lisiecki
// v 1.1 12.05.2016
// Plik zawiera deklaracje szablonu klasy bazowej aghContainer

#ifndef AGHCONTAINER_H
#define AGHCONTAINER_H
#include <iostream>
using namespace std;

template <class T>
class aghContainer{
public:
    //Metoda dodawania elementu do pojemnika,
    //dodaj�ca podany jako argument obiekt typu T do pojemnika.
	virtual void append(T const&) = 0;
	virtual ~aghContainer()
	{
        cout << "";
    }
	//Operator �,
    //dodaje element do pojemnika i zwraca referencje do this.
	virtual aghContainer<T>& operator<<(T const&){}
	//Metoda wstawiania elementu do pojemnika,
	///wstawiaj�ca obiekt typu T w wybrane miejsce. Zwraca true je�eli podane miejsce wstawienia jest prawid�owe, w przeciwnym wypadku zwraca false.
 	virtual bool insert(int, T const& ) = 0;
	//Metoda podmiany elementu w pojemniku,
	//podmienia obiekt typu T z obiektem na wybranym miejscu. Zwraca true je�eli podane miejsce podmiany jest prawid�owe, w przeciwnym wypadku zwraca false.
	virtual bool replace(int, T const& ) = 0;
	//Metoda zwracaj�ca ilo�� element�w,
	//zwraca ilo�� element�w w pojemniku.*/
	virtual int size(void) const{}
    virtual aghContainer& operator= (aghContainer const& ) {}
    //Metoda zwracaj�ca warto�� elementu,
    //zwraca warto�� w pojemniku. Zak�adamy �e indeksowanie warto�ci rozpoczynamy od zera.
     virtual T& at(int) const{}
    //Metoda usuwaj�ca wybrany element,
    //usuwa element na danym miejscu. Zwraca true je�eli podane miejsce usuni�cia jest prawid�owe, w przeciwnym wypadku zwraca false.
    virtual bool remove(int) = 0;
    //Metoda opr�niaj�ca pojemnik,
    //usuwa wszystkie elementy pojemnika.*/
    virtual void clear(void){}
    //Metoda sprawdzaj�ca czy pojemnik jest pusty,
    //zwraca true je�eli pojemnik jest pusty, inaczej false.
     virtual bool isEmpty(void){}
    //Metoda wyszukuj�ca element w pojemniku przez warto�� od zadanego momentu,
    //wyszukuje i zwraca indeks pierwszego elementu o warto�ci _value zaczynaj�c od elementu _from. Je�eli takiego elementu nie ma to zwraca -1.
     virtual int indexOf(T const& _value, int _from = 0) const = 0;
    //Metoda sprawdzaj�ca czy dany element jest ju� w pojemniku,
    //zwraca true je�eli element o warto�ci _value znajduje si� w pojemniku inaczej zwraca false. Wyszukiwanie rozpoczyna si� od elelmetnu _from.
    virtual bool contains(T const& _value, int _from = 0) const = 0;
    //Operator por�wnania,
    //sprawdza czy zawarto�� pojemnik�w jest taka sama.
    virtual bool operator==(aghContainer<T> const& right){}
    //Operator nier�wno�ci,
    //sprawdza czy zawarto�� pojemnik�w jest r�na.
    virtual bool operator!=(aghContainer<T> const& right){}
    //Operator [],
    //zwraca element o indeksie n.
    virtual T& operator[](int n) const{}
    //Operator +=,
    //dodaje element do pojemnika i zwraca referencje do this.
    virtual aghContainer<T>& operator+=(T const& element){}
    //Operator +=,
    //dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this.
    virtual aghContainer<T>& operator+=(aghContainer<T> const& right){}
    //Operator �,
    //dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this.
    virtual aghContainer<T>& operator<<(aghContainer<T> const& right){};
    //Operator �,
    //wypisuje zawarto�� pojemnika na strumie�.
    friend ostream& operator<<(ostream&, aghContainer<T> const& right){}

};

#endif
