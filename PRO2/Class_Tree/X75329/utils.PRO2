#ifndef UTILS_PRO2  // per evitar fer mes d'un include
#define UTILS_PRO2

#include <exception>
#include <iostream>

using namespace std;

/* Clase PRO2Excepcio */
class PRO2Excepcio: public exception {
  public:
   PRO2Excepcio(const char* mot) : exception(), mensaje(mot) {}
   const char* what() const throw() {return mensaje;}; 
  private:
   const char* mensaje;
};
/* Fi clase PRO2Excepcio*/


/** Funcions per fer lectures de tipus basics. **/

inline int
readint ()
{
  int n;
  cin >> n;
  return n;
}
inline char
readchar ()
{
  char n;
  cin >> n;
  return n;
}

inline bool
readbool ()
{
  string n;
  cin >> n;
  if (n!="true" and n!="false") throw PRO2Excepcio("S'havia de llegir un boolea");
  return (n=="true");
}
inline double
readdouble ()
{
  double n;
  cin >> n;
  return n;
}
inline string
readstring ()
{
  string s;
  cin >> s;
  return s;
}

#endif

