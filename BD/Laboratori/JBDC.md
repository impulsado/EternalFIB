# EXECUCIÓ 1
Cap perquè hi ha un c.rollback() que esta fent que tots els canvis temporals (Inserció del professor) no s'acabin executant en la BD.

# EXECUCIÓ 2
Ara si que s'ha realitzat perquè finalment, a l'estructura "statement" hem executat el mètode "commit" i s'han aplicat els canvis en la BD.

# EXECUCIÓ 3
## PREGUNTA 1
Donat que ara ja existeix, i el mètode commit està inclòs dins un "try catch", ha detectat l'error "SQLException" --> Ha fet saltar el catch i ha mostrar:
"""
Excepcio: 

El getSQLState es: 23505

El getMessage es: ERROR: duplicate key value violates unique constraint "professors_pkey"
  Detail: Key (dni)=(555                                               ) already exists.
"""

## PREGUTNA 2
No ha tingut cap efecte donat que no s'ha executat res.

## PREGUTNA 3
Canviant el catch per això:
```java
	catch (SQLException se) {
		if (se.getSQLState().equals("23505")) {
			System.out.println ("El professor ja existeix"); System.out.println ();
		}
		else {
           System.out.println ("Excepcio: ");System.out.println ();
           System.out.println ("El getSQLState es: " + se.getSQLState());
           System.out.println ();
           System.out.println ("El getMessage es: " + se.getMessage());	   
		}
	}
```

# EXECUCIÓ 4
## Codi
```java
// IMPLEMENTAR
       // printar el dni i el nom dels professors que tenen els tel fons amb n mero inferior al que s'indica en la variable buscaTelf
       // en cas que no hi hagi cap professor amb aquest tel fon printar "NO TROBAT" 
       String buscaTelf="3334";  //3334 
       
       // 1. Crear la query en una string
       String query = "SELECT dni, nomProf FROM professors WHERE telefon < ?";
       
       // 2. Preparem les variables
       PreparedStatement ps = c.prepareStatement(query);  // Creem una preparedStatement amb la query
       ResultSet rs = null;  // Definim l'estructura de dades per guardar els resultats
       boolean found = false;  // Trobat o no
       
	   ps.setString(1, buscaTelf);  // Canviem al paràmetre que volem
	   rs = ps.executeQuery();  // Executem la query i la guardem en l'estructura de dades
       
	   while(rs.next()) {  // Mentre hi hagi un next() sig. que tenim files retornades
		   // NO hem de tornar a executar la query aqui dins perque ja tenim les dades en rs.
		   found = true;
		   // .trim() per a treure l'espai restant pq no han fet servir VARCHAR >:(
           String res_dni = rs.getString("dni").trim();
           String res_nom = rs.getString("nomProf").trim();
           System.out.println("DNI: '"+res_dni+"' NOM: '"+res_nom+"'n");
       }
       
	   if (!found) {
		   System.out.println("NO TROBATn");
	   }
	   
	   // Rollback i desconnexio de la base de dades
	   c.commit();  // Canviat en exercici 3
	   c.close();
	   System.out.println ("Commit i desconnexio realitzats correctament.");
	}
	catch (SQLException se) {
		if (se.getSQLState().equals("23505")) {
			System.out.println ("El professor ja existeix"); System.out.println ();
		}
		else {
           System.out.println ("Excepcio: ");System.out.println ();
           System.out.println ("El getSQLState es: " + se.getSQLState());
           System.out.println ();
           System.out.println ("El getMessage es: " + se.getMessage());	   
		}
	}
  }
}
```

## Resultat
"""
DNI: '111' NOM: 'ruth'

DNI: '222' NOM: 'ona'

DNI: '333' NOM: 'anna'
"""