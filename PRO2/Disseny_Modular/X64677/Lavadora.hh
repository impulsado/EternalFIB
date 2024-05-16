/** @file Lavadora.hh
    @brief Especificación de la clase Lavadora 
*/

#ifndef _LAVADORA_HH_
#define _LAVADORA_HH_

#include "Prenda.hh"

#ifndef NO_DIAGRAM  // ver explicacion en Prenda.hh
#include <list>
#endif

/** @class Lavadora
    @brief Representa una lavadora 

    Dispone de dos estados posibles (inicializada / no inicializada); si está inicializada tiene un peso máximo y un color y puede contener prendas de dicho color hasta alcanzar dicho peso máximo; si no está inicializada no contiene ninguna prenda y solo se puede inicializar

    Todas las operaciones son de <b>coste constante</b> salvo las indicadas */
class Lavadora
  {

public:
  //Constructoras 

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una lavadora.
      \pre <em>cierto</em>
      \post El resultado es una lavadora no inicializada
  */  
  Lavadora();
 
  //Modificadoras

  /** @brief Inicializa la lavadora
      \pre El parámetro implícito no está inicializado, pmax>0
      \post El parámetro implícito es una lavadora vacía inicializada con peso máximo "pmax" y color "col" 
  */
  void inicializar(int pmax, bool col);

  /** @brief Añade una prenda a la lavadora
      \pre El parámetro implícito (L) está inicializado, color de p = color de L, peso de L + peso de p <= peso máximo de L
      \post El parámetro implícito contiene su carga original más p 
  */
  void anadir_prenda (const Prenda& p);

  /** @brief Realiza un lavado

      Representa que se realiza el lavado, se retiran la prendas que contiene la lavadora y ésta queda en estado de volver a usarse
      \pre El parámetro implícito está inicializado
      \post El parámetro implícito no está inicializado 
      \coste Lineal respecto al número de prendas del parámetro implícito
  */
  void lavado ();

  // Consultoras

  /** @brief Consultora del estado de la lavadora

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito está inicializado 
  */
  bool esta_inicializada() const;

  /** @brief Consultora del color de la lavadora

      \pre El parámetro implícito está inicializado
      \post El resultado es el color del parámetro implícito 
  */
  bool consultar_color() const;

  /** @brief Consultora del peso actual de la lavadora

      \pre El parámetro implícito está inicializado
      \post El resultado es la suma de los pesos de las prendas del parámetro implícito 
  */
  int consultar_peso() const;

  /** @brief Consultora del peso máximo de la lavadora

      \pre El parámetro implícito está inicializado
      \post El resultado es el peso máximo del parámetro implícito 
  */
  int consultar_peso_maximo() const;

  // Escritura de la lavadora

  /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida 
      \coste Lineal respecto al número de prendas del parámetro implícito
  */
  void escribir() const;

private:
  list<Prenda> prendas;
  bool col;
  int pes;
  bool ini;
  int pesmax;
};
#endif
