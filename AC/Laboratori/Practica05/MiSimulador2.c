#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

struct linea {
	unsigned int v;
	unsigned int TAG;
	unsigned int last_mod;
	int DATA[32];
};

struct via {
	struct linea conj[64];
};

struct Cache2Aso {
	struct via CACHE[2];
};

struct Cache2Aso Cache;

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
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla�ada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */

	// 1. Agafar info
	byte = address&0x1F;
	bloque_m = address>>5;
	conj_mc = (address&0x7E0)>>5;
	tag = (address&0xFFFFF800)>>11;

	// 2.
	unsigned int found = 0;
	unsigned int bit_v0 = Cache.CACHE[0].conj[conj_mc].v;
	unsigned int bit_v1 = Cache.CACHE[1].conj[conj_mc].v;
	unsigned int tag_v0 = Cache.CACHE[0].conj[conj_mc].TAG;
	unsigned int tag_v1 = Cache.CACHE[1].conj[conj_mc].TAG;
	unsigned int last_mod_v0 = Cache.CACHE[0].conj[conj_mc].last_mod;

	if (bit_v0 == 0) {
		miss = 1;
		via_mc = 0;
		tag_out = 0;
		replacement = 0;
		Cache.CACHE[0].conj[conj_mc].TAG = tag;
		Cache.CACHE[0].conj[conj_mc].v = 1;
		Cache.CACHE[0].conj[conj_mc].last_mod = 1;
		found = 1;
	}
	else {
		if (tag_v0 == tag) {
			miss = 0;
			via_mc = 0;
			tag_out = 0;
			replacement = 0;
			Cache.CACHE[0].conj[conj_mc].last_mod = 1;
			Cache.CACHE[1].conj[conj_mc].last_mod = 0;
			found = 1;
		}
	}
	
	if (bit_v1 == 0 && !found) {
		miss = 1;
		via_mc = 1;
		tag_out = 0;
		replacement = 0;
		Cache.CACHE[1].conj[conj_mc].TAG = tag;
		Cache.CACHE[1].conj[conj_mc].v = 1;
		Cache.CACHE[1].conj[conj_mc].last_mod = 1;
		Cache.CACHE[0].conj[conj_mc].last_mod = 0;
		found = 1;
	}
	else if (bit_v1 == 1 && !found) {
		if (tag_v1 == tag) {
			miss = 0;
			via_mc = 1;
			tag_out = 0;
			replacement = 0;
			Cache.CACHE[0].conj[conj_mc].last_mod = 0;
			Cache.CACHE[1].conj[conj_mc].last_mod = 1;
			found = 1;
		}
	}

	if (!found) {			
		if (last_mod_v0 == 1) {
			miss = 1;
			via_mc = 1;
			tag_out = tag_v1;
			replacement = 1;
			Cache.CACHE[0].conj[conj_mc].last_mod = 0;
			Cache.CACHE[1].conj[conj_mc].last_mod = 1;
			Cache.CACHE[1].conj[conj_mc].TAG = tag;
		}
		else {
			miss = 1;
			via_mc = 0;
			tag_out = tag_v0;
			replacement = 1;
			Cache.CACHE[0].conj[conj_mc].last_mod = 1;
			Cache.CACHE[1].conj[conj_mc].last_mod = 0;
			Cache.CACHE[0].conj[conj_mc].TAG = tag;
		}
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print2 (address, byte, bloque_m, conj_mc, via_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  
  
}
