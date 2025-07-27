#define true 1
#define false 0

void test_and_print (
		unsigned int address,
		unsigned int byte,
	       	unsigned int linea_mp,
		unsigned int linea_mc,
		unsigned int tag,
		unsigned int miss,
		unsigned int replacement,
	        unsigned int tag_out);

void init_cache ();

void reference (unsigned int address);

float GetTime(void);

float totaltime;
