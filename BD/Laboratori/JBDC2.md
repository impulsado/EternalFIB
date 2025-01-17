# APARTAT 1
## CODI
```java
	// IMPLEMENTAR CONSULTA
       String[] telfsProf = {"3111", "3222", "3333", "4444"};
       String query1 = "SELECT dni, nomProf FROM professors WHERE telefon = ?";
       PreparedStatement ps = c.prepareStatement(query1);
       ResultSet rs = null;
       
       for (String telefon : telfsProf) {
    	   ps.setString(1, telefon);
    	   rs = ps.executeQuery();
    	   
    	   if (rs.next()) {
    		   String dni = rs.getString("dni");
    		   String nomProf = rs.getString("nomProf");
    		   System.out.println("DNI: " + dni + " NOM: " + nomProf + " TELEFON: " + telefon + "n");
    	   }
    	   else System.out.println("TELEFON: " + telefon + " NO TROBATn");
       }
```

## RESULTAT
"""
DNI: 111                                                NOM: ruth                                               TELEFON: 3111

DNI: 222                                                NOM: ona                                                TELEFON: 3222

DNI: 333                                                NOM: anna                                               TELEFON: 3333

TELEFON: 4444 NO TROBAT
"""

# APARTAT 2
## CODI
```java
	   // IMPLEMENTAR CANVI BD
       // ! CUIDADO AMB ELS ESPAIS 
       String query2 = 
    		"SELECT modul, numero " + 
    		"FROM despatxos d " + 
    		"WHERE d.modul = 'omega' AND NOT EXISTS ( " +
    			"SELECT * FROM assignacions a2 " +
    			"WHERE a2.modul = d.modul AND a2.numero = d.numero AND a2.instantFi IS NULL " +
    		")";
       Statement s2 = c.createStatement();  // Perque aquesta només s'executa una vegada
       ResultSet rs2;
       rs2 = s2.executeQuery(query2);
       
       String query21 = "UPDATE despatxos SET superficie = superficie+3 WHERE modul = ? AND numero = ?";
       PreparedStatement ps2 = c.prepareStatement(query21);  // Aquesta itera sobre els multiples despatxos
       
       while (rs2.next()) {
    	   String modul = rs2.getString("modul");
    	   String numero = rs2.getString("numero");
    	   
    	   ps2.setString(1, modul);
    	   ps2.setString(2, numero);
    	   
    	   int quantitat_mod = ps2.executeUpdate();
    	   System.out.println("S'han modificat "+ quantitat_mod + " despatxosn"); 
       }
       
	   // Commit i desconnexio de la base de dades
	   c.commit();
	   c.close();
	   System.out.println ("Commit i desconnexio realitzats correctament.");
	   }
	
	catch (SQLException se) {
		if (se.getSQLState().equals("23514")) {  // check_violation
			System.out.println("ERROR: Algun despatx passaria a tenir superfície superior o igual a 25n");
			// No fa falta ficar c.abort() perque ja ho porta implicit al ser una Exception
		}
		else {
	           System.out.println ("Excepcio: ");System.out.println ();
	           System.out.println ("El getSQLState es: " + se.getSQLState());
	           System.out.println ();
	           System.out.println ("El getMessage es: " + se.getMessage());	   
		}
	}
```

## RESULTAT
Per a saber quina excepció provocaria, he mirat en el llistat de codis "https://learnsql2.fib.upc.edu/moodle/mod/resource/view.php?id=900"
i he buscat el de check_*. Això és perquè en crear la taula, ficant al costat de la columna que superfície <25, hem creat un check i si ho superàvem, seria això el que faria saltar excepció.

### OK
"""
S'han modificat 1 despatxos
"""

### KO
"""
ERROR: Algun despatx passaria a tenir superfície superior o igual a 25
"""