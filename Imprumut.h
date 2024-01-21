#ifndef PROIECTSDA_IMPRUMUT_H
#define PROIECTSDA_IMPRUMUT_H
#include "Carte.h"
#include "Client.h"

class Imprumut {
private:
    Carte carte;
    Client client;
    int dataImprumut;
    int dataRestituire;
public:
    Imprumut(const Carte &carte, const Client &client, int dataImprumut, int dataRestituire);

    const Carte &getCarte() const;

    const Client &getClient() const;

    int getDataImprumut() const;

    int getDataRestituire() const;
};


#endif //PROIECTSDA_IMPRUMUT_H
