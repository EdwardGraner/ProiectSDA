//
// Created by Edy on 21.01.2024.
//

#include "Imprumut.h"

Imprumut::Imprumut(const Carte &carte, const Client &client, int dataImprumut, int dataRestituire) : carte(carte),
                                                                                                     client(client),
                                                                                                     dataImprumut(
                                                                                                             dataImprumut),
                                                                                                     dataRestituire(
                                                                                                             dataRestituire) {}

const Carte &Imprumut::getCarte() const {
    return carte;
}

const Client &Imprumut::getClient() const {
    return client;
}

int Imprumut::getDataImprumut() const {
    return dataImprumut;
}

int Imprumut::getDataRestituire() const {
    return dataRestituire;
}
