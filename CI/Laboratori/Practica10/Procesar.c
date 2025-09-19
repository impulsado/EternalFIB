void procesar(unsigned char *mata, unsigned char *matb, int n) {
  int i, j; 
  
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      matb[i*n+j]=(mata[i*n+j] & 1);
      if (matb[i*n+j]>0)
	matb[i*n+j]=255;
      else
	matb[i*n+j]=0;
    }
  }
}