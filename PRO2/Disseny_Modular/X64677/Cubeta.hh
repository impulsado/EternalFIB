/** @file Cubeta.hh
    @brief Especificación de la clase Cubeta
*/

#ifndef _CUBETA_HH_
#define _CUBETA_HH_

#include "Prenda.hh" // redundante, pero necesario para el diagrama modular
#include "Lavadora.hh"

#ifndef NO_DIAGRAM // ver explicacion en Prenda.hh
#include <stack>
#endif


/** @class Cubeta
    @brief Representa una cubeta de ropa. 

    Puede contener prendas blancas y de color. Puede usarse para intentar llenar una lavadora; en ese caso, las prendas se sacan de la cubeta en orden inverso al de entrada
*/
class Cubeta
{
public:
  //Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una cubeta.
      \pre <em>cierto</em>
      \post El resultado es una cubeta sin prendas de ningún tipo
      \coste Constante
  */  
  Cubeta();
 
  /** @brief Creadora copiadora. 

      Permite declarar una cubeta nueva como copia de otra ya existente.
      \pre <em>cierto</em>
      \post El resultado es una cubeta igual que c
      \coste Lineal respecto al número de prendas de c
  */  
  Cubeta(const Cubeta& c);


  //Modificadoras

  /** @brief Añade una prenda a la cubeta
      \pre <em>cierto</em>
      \post El parámetro implícito pasa a contener sus prendas originales más p 
      \coste Constante
  */
  void anadir_prenda(const Prenda& p);

  /** @brief Completa una lavadora con las prendas de la cubeta
      \pre lav está inicializada
      \post Se han eliminado del parámetro implícito y se han añadido a lav las prendas del parámetro implícito del color adecuado que más se acercan entre todas al peso máximo de lav sin pasarse, elegiéndose primero las que se introdujeron en último lugar
      \coste Lineal respecto al número de prendas del parámetro implícito 
  */
  void completar_lavadora(Lavadora& lav);

  // Escritura de una cubeta

  /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida
       \coste Lineal respecto al número de prendas del parámetro implícito 
  */
  void escribir() const;

  // de momento no documentamos los elementos privados; se hará en otro ejemplo

private:
  stack<Prenda> ropacolor;
  stack<Prenda> ropablanca;
  static void completar_lavadora_pila_rec(stack<Prenda>& p, Lavadora& l);
  static void completar_lavadora_pila_it(stack<Prenda>& p, Lavadora& l);
  static void escribir_pila_prenda(const stack<Prenda>& p);
};
#endif
