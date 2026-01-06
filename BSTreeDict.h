#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        // ABB que almacena entradas de tipo TableEntry<V>
        BSTree<TableEntry<V>>* tree;

    public:
        // Constructor: Reserva memoria dinámica para el árbol
        BSTreeDict() {
            tree = new BSTree<TableEntry<V>>();
        }

        // Destructor: Libera la memoria del árbol
        ~BSTreeDict() {
            delete tree;
        }

        // --- Implementación de métodos de Dict<V> ---

        void insert(std::string key, V value) override {
            TableEntry<V> entry(key, value);
            // Delega la inserción al ABB
            tree->insert(entry);
        }

        V search(std::string key) override {
            // Se crea una entrada auxiliar solo con la clave para buscar
            TableEntry<V> entry(key);
            return tree->search(entry).value;
        }

        V remove(std::string key) override {
            TableEntry<V> entry(key);
            // Obtenemos el valor antes de eliminarlo para devolverlo
            V val = tree->search(entry).value;
            tree->remove(entry);
            return val;
        }

        int entries() override {
            // Delega la consulta de tamaño al ABB
            return tree->size();
        }

        // --- Métodos propios y sobrecargas ---

        V operator[](std::string key) {
            return search(key);
        }

        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs) {
            // El ABB ya tiene sobrecargado el operador << con recorrido inorden
            out << *(bs.tree);
            return out;
        }
};

#endif
