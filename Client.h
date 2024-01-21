//
// Created by Edy on 21.01.2024.
//

#ifndef PROIECTSDA_CLIENT_H
#define PROIECTSDA_CLIENT_H
#include <iostream>

using namespace std;

class Client {
private:
    string nume;
    string prenume;
    string CNP;
public:
    Client(const string &nume, const string &prenume, const string &cnp);

    const string &getNume() const;

    const string &getPrenume() const;

    const string &getCnp() const;


};


#endif //PROIECTSDA_CLIENT_H
