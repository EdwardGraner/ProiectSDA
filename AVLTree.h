#ifndef PROIECTSDA_AVLTREE_H
#define PROIECTSDA_AVLTREE_H

#endif //PROIECTSDA_AVLTREE_H

#include <iostream>
#include <algorithm>
#include "Carte.h"

class AVLNode {
public:
    Carte carte;
    AVLNode* left;
    AVLNode* right;
    int height;
    int balanceFactor;

    AVLNode(const Carte& carte)
            : carte(carte), left(nullptr), right(nullptr), height(1), balanceFactor(0) {}
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) const {
        return (node != nullptr) ? node->height : 0;
    }

    int getBalanceFactor(AVLNode* node) const {
        return (node != nullptr) ? node->balanceFactor : 0;
    }

    int calculateHeight(AVLNode* node) {
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    int calculateBalanceFactor(AVLNode* node) {
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = calculateHeight(y);
        x->height = calculateHeight(x);

        y->balanceFactor = calculateBalanceFactor(y);
        x->balanceFactor = calculateBalanceFactor(x);

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = calculateHeight(x);
        y->height = calculateHeight(y);

        x->balanceFactor = calculateBalanceFactor(x);
        y->balanceFactor = calculateBalanceFactor(y);

        return y;
    }

    AVLNode* balanceNode(AVLNode* node) {
        if (node == nullptr)
            return nullptr;

        node->height = calculateHeight(node);
        node->balanceFactor = calculateBalanceFactor(node);

        if (node->balanceFactor > 1) {
            if (getBalanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }

        if (node->balanceFactor < -1) {
            if (getBalanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode* insertNode(AVLNode* node, const Carte& carte) {
        if (node == nullptr) {
            return new AVLNode(carte);
        }

        if (carte.getTitlu() < node->carte.getTitlu()) {
            node->left = insertNode(node->left, carte);
        } else if (carte.getTitlu() > node->carte.getTitlu()) {
            node->right = insertNode(node->right, carte);
        } else {
            return node;
        }

        return balanceNode(node);
    }

    AVLNode* findMinNode(AVLNode* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    AVLNode* deleteNode(AVLNode* node, const std::string& titlu) {
        if (node == nullptr)
            return nullptr;

        if (titlu < node->carte.getTitlu()) {
            node->left = deleteNode(node->left, titlu);
        } else if (titlu > node->carte.getTitlu()) {
            node->right = deleteNode(node->right, titlu);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode* temp = (node->left != nullptr) ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }

                delete temp;
            } else {
                AVLNode* temp = findMinNode(node->right);
                node->carte = temp->carte;
                node->right = deleteNode(node->right, temp->carte.getTitlu());
            }
        }

        if (node == nullptr)
            return nullptr;

        return balanceNode(node);
    }

public:
    AVLTree() : root(nullptr) {}

    void adaugaCarte(const Carte& carte) {
        root = insertNode(root, carte);
    }

    void stergeCarte(const std::string& titlu) {
        root = deleteNode(root, titlu);
    }

    // Alte funcționalități, cum ar fi actualizarea și căutarea, pot fi adăugate aici.

    // Funcție pentru afișarea în ordine a cărților
    void afiseazaInordine(AVLNode* node) const {
        if (node != nullptr) {
            afiseazaInordine(node->left);
            std::cout << "Titlu: " << node->carte.getTitlu() << ", Autor: " << node->carte.getAutor() << ", ISBN: " << node->carte.getIsbn() << "\n";
            afiseazaInordine(node->right);
        }
    }

    // Funcție publică pentru a afișa în ordine cărțile din arbore
    void afiseazaInordine() const {
        afiseazaInordine(root);
    }
};
