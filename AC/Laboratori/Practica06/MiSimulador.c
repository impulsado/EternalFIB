#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

 struct Linea{
	unsigned int v;
	unsigned int TAG;
	char DATA[32];
 };
 
 struct Cache {
	struct Linea CACHE[128];
 };
 
 struct Cache cache_1;

 int access_counter = 0;
 int miss_counter = 0;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
	memset(&cache_1, 0, sizeof(cache_1));
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE)
{
	access_counter++;
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	unsigned int replacement;
	unsigned int tag_out;

	/* Escriu aqui el teu codi */
	byte = address&0x1F;
	bloque_m = (address&0xFFFFFFE0)>>5;
	linea_mc = (address&0xFE0)>>5;
	tag = (address&0xFFFFF000)>>12;


	// 2. Identifiquem si esta dins
	if (cache_1.CACHE[linea_mc].v == 0) {
		miss = 1; miss_counter++;
		tag_out = 0;
		replacement = 0;

		if (LE == lectura) {
			cache_1.CACHE[linea_mc].v = 1;
			cache_1.CACHE[linea_mc].TAG = tag;

			lec_mp = 1; mida_lec_mp = 32;
			esc_mp = 0; mida_esc_mp = 0; 
		}
		else {
			lec_mp = 0; mida_lec_mp = 0;
			esc_mp = 1; mida_esc_mp = 1; 
		}
	}
	else {
		// Es el mateix
		if (cache_1.CACHE[linea_mc].TAG == tag) {
			miss = 0;
			tag_out = 0;
			replacement = 0;

			if (LE == lectura) {
				lec_mp = 0; mida_lec_mp = 0;
				esc_mp = 0; mida_esc_mp = 0;
			}
			else {
				lec_mp = 0; mida_lec_mp = 0;
				esc_mp = 1; mida_esc_mp = 1;
			}
		}
		else {
			miss = 1; miss_counter++;
			
			if (LE == lectura) {
				replacement = 1;
				tag_out = cache_1.CACHE[linea_mc].TAG;
				cache_1.CACHE[linea_mc].TAG = tag;

				lec_mp = 1; mida_lec_mp = 32;
				esc_mp = 0; mida_esc_mp = 0;
			}
			else {
				tag_out = 0;
				replacement = 0;

				lec_mp = 0; mida_lec_mp = 0;
				esc_mp = 1; mida_esc_mp = 1;
			}
		}
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
	//printf("TOTAL ACCESSOS: %d | HIT: %d | MISS: %d \n", access_counter, access_counter-miss_counter, miss_counter);
}
