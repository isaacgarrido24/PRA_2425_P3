#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
    public:
        // Atributos públicos
        T elem;                // Elemento almacenado en el nodo
        BSNode<T>* left;      // Puntero al sucesor izquierdo
        BSNode<T>* right;     // Puntero al sucesor derecho

        /**
         * Método constructor.
         * Crea un nodo con el elemento proporcionado y punteros nulos por defecto.
         */
        BSNode(T elem, BSNode<T>* left = nullptr, BSNode<T>* right = nullptr) 
            : elem(elem), left(left), right(right) {}

        /**
         * Sobrecarga del operador <<.
         * Imprime el elemento almacenado en el nodo.
         */
        friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn) {
            out << bsn.elem;
            return out;
        }
};

#endif
