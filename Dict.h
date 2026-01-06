#ifndef DICT_H
#define DICT_H

#include <string>
#include <stdexcept> // Necesario para lanzar std::runtime_error

template <typename V>
class Dict {
    public:
        /**
         * Inserta el par key->value en el diccionario.
         * Lanza std::runtime_error si la llave ya existe.
         */
        virtual void insert(std::string key, V value) = 0;

        /**
         * Busca el valor correspondiente a key.
         * Devuelve el valor asociado o lanza std::runtime_error si no existe.
         */
        virtual V search(std::string key) = 0;

        /**
         * Elimina el par key->value del diccionario.
         * Devuelve el valor eliminado o lanza std::runtime_error si no existe.
         */
        virtual V remove(std::string key) = 0;

        /**
         * Devuelve el número de elementos actuales en el diccionario.
         */
        virtual int entries() = 0;

        /**
         * Destructor virtual para asegurar una limpieza correcta 
         * en las clases derivadas.
         */

        virtual ~Dict() {}
};

#endif
