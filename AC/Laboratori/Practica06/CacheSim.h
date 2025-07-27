#include <string.h>
#include <stdio.h>

#define true 1
#define false 0

#define lectura 0
#define escriptura 1

void test_and_print (
		unsigned int address,
		unsigned int LE,
		unsigned int byte,
	       	unsigned int linea_mp,
		unsigned int linea_mc,
		unsigned int tag,
		unsigned int miss,
		unsigned int lec_mp,
		unsigned int mida_lec_mp,
		unsigned int esc_mp,
		unsigned int mida_esc_mp,
		unsigned int replacement,
	        unsigned int tag_out);

void init_cache ();

void reference (unsigned int address, unsigned int LE);
