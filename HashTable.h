#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"
#include "../../pract1/part1/PRA2526_P1/ListLinked.h" 

template <typename V>
class HashTable: public Dict<V> {
    private:
        int n;          // Elementos actuales
        int max;        // Tamaño de la tabla (cubetas)
        ListLinked<TableEntry<V>>* table; // Array de listas

        // Función Hash: Suma ASCII % max
        int h(std::string key) {
            int sum = 0;
            for (int i = 0; i < key.length(); i++) {
                sum += int(key.at(i));
            }
            return sum % max;
        }

    public:
        // Constructor
        HashTable(int size) {
            table = new ListLinked<TableEntry<V>>[size];
            max = size;
            n = 0;
        }

        // Destructor
        ~HashTable() {
            delete[] table;
        }

        // Capacidad total
        int capacity() {
            return max;
        }

        // --- Implementación de la interfaz Dict<V> ---

        void insert(std::string key, V value) override {
            int pos = h(key);
            TableEntry<V> entry(key, value);
            
            // Verificamos si la llave ya existe en esa lista
            if (table[pos].search(entry) != -1) {
                throw std::runtime_error("Key already exists: " + key);
            }
            
            // Insertamos al final de la lista de esa cubeta
            table[pos].append(entry);
            n++;
        }

        V search(std::string key) override {
            int pos = h(key);
            TableEntry<V> aux(key);
            int index = table[pos].search(aux);
            
            if (index == -1) {
                throw std::runtime_error("Key not found: " + key);
            }
            
            return table[pos].get(index).value;
        }

        V remove(std::string key) override {
            int pos = h(key);
            TableEntry<V> aux(key);
            int index = table[pos].search(aux);
            
            if (index == -1) {
                throw std::runtime_error("Key not found: " + key);
            }
            
            V val = table[pos].get(index).value;
            table[pos].remove(index);
            n--;
            return val;
        }

        int entries() override {
            return n;
        }

        // --- Sobrecarga de operadores ---

        V operator[](std::string key) {
            return search(key);
        }

        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]\n";
            out << "==============\n";
            for (int i = 0; i < th.max; i++) {
                out << "Cubeta " << i << ": " << th.table[i] << "\n";
            }
            out << "==============\n";
            return out;
        }
};

#endif
