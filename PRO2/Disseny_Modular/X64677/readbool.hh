/** @file readbool.hh
    @brief operacion para leer booleanos del canal estandar
*/

#ifndef _READBOOL_
#define _READBOOL_

#ifndef NO_DIAGRAM
#include <iostream>
#include "PRO2Excepcio.hh"
#endif

/** @brief Lee un booleano por el canal estandar
    \pre La primera string valida del canal estandar es "true" o "false"
    \post El resultado es cierto si se ha leido "true" y falso si no
*/
inline bool readbool ()
{
  string n;
  cin >> n;
  if (n!="true" and n!="false") throw PRO2Excepcio("S'havia de llegir un boolea");
  return (n=="true");
}

#endif
