#include "Carte.h"


Carte::Carte(const string &titlu, const string &autor, const string &isbn) : titlu(titlu), autor(autor), ISBN(isbn) {}

const string &Carte::getTitlu() const {
    return titlu;
}

const string &Carte::getAutor() const {
    return autor;
}

const string &Carte::getIsbn() const {
    return ISBN;
}
