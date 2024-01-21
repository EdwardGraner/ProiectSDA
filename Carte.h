#ifndef PROIECTSDA_CARTE_H
#define PROIECTSDA_CARTE_H

#include <iostream>

using namespace std;

class Carte {
private:
    string titlu;
    string autor;
    string ISBN;
public:
    Carte(const string &titlu, const string &autor, const string &isbn);

    const string &getTitlu() const;

    const string &getAutor() const;

    const string &getIsbn() const;
};


#endif //PROIECTSDA_CARTE_H
