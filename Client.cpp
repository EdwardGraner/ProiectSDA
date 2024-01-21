#include "Client.h"


Client::Client(const string &nume, const string &prenume, const string &cnp) : nume(nume), prenume(prenume), CNP(cnp) {}

const string &Client::getNume() const {
    return nume;
}

const string &Client::getPrenume() const {
    return prenume;
}

const string &Client::getCnp() const {
    return CNP;
}

