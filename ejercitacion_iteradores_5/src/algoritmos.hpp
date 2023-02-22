#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// Completar con las funciones del enunciado

/* Ejercicio 1 */
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::value_type min = *it;
    while(it != c.end()){
        if(*it < min){
            min = *it;
        }
        ++it;
    }
    return min;
}

/* Ejercicio 2 */
template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::value_type prom = 0;
    typename Contenedor::value_type sumaTotal = 0;
    int longitud = 0;

    for(typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it){
        sumaTotal = sumaTotal + *it;
        longitud++;
    }
    prom = sumaTotal / longitud;
    return prom;
}

/* Ejercicio 3 */
template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    auto it = desde;
    typename Iterator::value_type min = *it;
    while(it != hasta){
        if(*it < min){
            min = *it;
        }
        ++it;
    }
    return min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    typename Iterator::value_type prom = 0;
    typename Iterator::value_type sumaTotal = 0;
    int longitud = 0;

    for(auto it = desde; it != hasta; ++it){
        sumaTotal = sumaTotal + *it;
        longitud++;
    }
    prom = sumaTotal / longitud;
    return prom;

}

/* Ejercicio 4 */
template<class Contenedor>
void filtrar(Contenedor& c, const typename Contenedor::value_type& elem){
    typename Contenedor::const_iterator it = c.begin();
    while(it != c.end()){
        if(*it == elem){
            it = c.erase(it);
        } else {
            ++it;
        }
    }
}

/* Ejercicio 5 */
template<class Contenedor>
bool ordenado(Contenedor& c){
    auto itElemActual = c.begin();
    auto itSigElemActual = ++c.begin();
    while((itSigElemActual != c.end()) && (*itElemActual < *itSigElemActual)) {
        ++itElemActual;
        ++itSigElemActual;
    }

    if(itSigElemActual != c.end()){
        return false;
    } else {
        return true;
    }
}

/* Ejercicio 6 */
template<class Contenedor>
std::pair<Contenedor,Contenedor> split(const Contenedor& c, const typename Contenedor::value_type& elem){
    Contenedor menores;
    Contenedor mayoresIguales;
    auto itMenores = menores.begin();
    auto itMayoresIguales = mayoresIguales.begin();

    for(auto it = c.begin(); it != c.end(); ++it){
        if(*it < elem){
            /* Insertar en el contenedor de menores */
            itMenores = menores.insert(itMenores,*it);
            ++itMenores;
        } else {
            /* Insertar en el contenedor de mayores */
            itMayoresIguales = mayoresIguales.insert(itMayoresIguales,*it);
            ++itMayoresIguales;
        }
    }
    std::pair<Contenedor,Contenedor> menoresyMayores = std::make_pair(menores,mayoresIguales);
    return menoresyMayores;
}

/* Ejercicio 7 */

/* Ejercicio 8 */

#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
