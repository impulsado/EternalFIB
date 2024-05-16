/** @file Prenda.hh
    @brief Especificación de la clase Prenda 
*/


#ifndef _PRENDA_HH_
#define _PRENDA_HH_

#ifndef NO_DIAGRAM          // esto hace que el Doxyfile de la sesión no 
#include "PRO2Excepcio.hh"  // incluya estas clases en los diagramas modulares, 
#include <iostream>         // mientras que el compilador de c++ 
#endif                      // sí que las procesa correctamente  

/** @class Prenda
    @brief Representa una prenda de ropa con atributos peso y color

    Todas las operaciones son de <b>coste constante</b>
*/
class Prenda
{
public:
  //Constructoras 

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una prenda.
      \pre <em>cierto</em>
      \post El resultado es una prenda de peso 0 y color blanco
  */   
  Prenda();

  /** @brief Creadora con valores concretos. 

      \pre pes>0 
      \post El resultado es una prenda con peso "pes" y color "col"
  */   
  Prenda(int pes, bool col);
  
  //Modificadoras

  /** @brief Modificadora de los atributos
      \pre pes>0
      \post El parámetro implícito pasa a tener peso "pes" y color "col" 
  */
  void modificar(int pes, bool col);
  
  //Consultoras

  /** @brief Consultora del peso
      \pre <em>cierto</em>
      \post El resultado es el peso del parámetro implícito
  */
  int consul_peso() const;
 
  /** @brief Consultora del color
      \pre <em>cierto</em>
      \post El resultado es el color del parámetro implícito
  */
  bool consul_color() const;


  //Escritura de prenda

  /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito los atributos del parámetro implícito en el canal
      standard de salida. 
  */
  void escribir() const;

private:
  // incluimos los campos de la clase para que se vea que los elementos privados
  // no aparecen en la documentación si está así configurado el Doxyfile
  int peso;
  bool color;
};

#endif
