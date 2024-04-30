#include "Estudiant.hh"

// Redondear, version funcion

Estudiant redondear_e_f(const Estudiant& est)
/* Pre: est tiene nota */
/* Post: el resultado es un estudiante como est pero con la nota redondeada */
{
  Estudiant est2(est.consultar_DNI());
  double notaR = ((int) (10.0 * (est.consultar_nota() + 0.05))) / 10.0;
  est2.afegir_nota(notaR);
  return est2;
}

// Redondear, version accion

void redondear_e_a(Estudiant& est)
/* Pre: est tiene nota */
/* Post: est pasa a tener su nota original redondeada */
{
  est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}

int main()
{
  Estudiant est;
  cout << "Escribe un estudiante <DNI nota>" << endl;
  est.llegir();
  if (est.te_nota()) { // comprobamos la precondicion
    //est=redondear_e_f(est);	// version funcion, en este caso es ineficiente
    redondear_e_a(est);    // version accion
  }
  cout << "El estudiante con la nota redondeada, o NP: " <<endl;
  est.escriure();
}