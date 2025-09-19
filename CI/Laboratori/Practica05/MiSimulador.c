#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
struct linea {
	unsigned int v;
	unsigned int TAG;
	int DATA[32];
};

struct CacheDirecta {
	struct linea CACHE[128];
};

struct CacheDirecta Cache;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
	memset(&Cache, 0, sizeof(Cache));
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla�ada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */

	// 1. Agafar Info
	byte = address&0x1F;
	bloque_m = address>>5;
	linea_mc = (address&0xFE0)>>5;
	tag = (address&0xFFFFF000)>>12;

	unsigned int bit_v = Cache.CACHE[linea_mc].v;
	unsigned int mem_tag = Cache.CACHE[linea_mc].TAG;
	// 2. Comprovar estat
	// 2.1. No hi havia res
	if (bit_v == 0) {
		miss = true;
		Cache.CACHE[linea_mc].TAG = tag;
		replacement = 0;
		tag_out = 0;
		Cache.CACHE[linea_mc].v = 1;
	}
	// 2.1. Hi ha HIT
	else if (bit_v == 1 && mem_tag == tag) {
		miss = false;
		replacement = 0;
		tag_out = 0;
	}
	// 2.2. Hi ha MISS
	else if (bit_v == 1 && mem_tag != tag) {
		miss = true;
		Cache.CACHE[linea_mc].TAG = tag;
		replacement = tag;
		tag_out = mem_tag;
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  
  
}
