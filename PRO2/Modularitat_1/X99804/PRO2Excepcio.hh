#ifndef PRO2_EXCEPCIO  // per evitar fer mes d'un include d'aquest fitxer
#define PRO2_EXCEPCIO

#include <exception>

using namespace std;

/* Classe PRO2Excepcio */
class PRO2Excepcio: public exception {
  public:
   PRO2Excepcio(const char* mot) : exception(), mensaje(mot) {}
   const char* what() const throw() {return mensaje;}; 
  private:
   const char* mensaje;
};
/* Fi classe PRO2Excepcio*/

#endif

