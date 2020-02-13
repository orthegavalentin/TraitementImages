/*#include <stdio.h>
#include "image_ppm.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
  char cNomImgLue[250];
  int nH, nW, nTaille;
  int occurence[255] = {0};

  if (argc != 2)
     {
       printf("Usage: ImageIn.pgm \n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue);

   OCTET *ImgIn;
   fstream output("BearHisto.dat",fstream::out);

   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;

   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);

  for (int i=0; i < nTaille; i++){
    occurence[ImgIn[i]]++;
   }

  for(int i = 0; i < 256; i++) {
    output<<i<<" "<<occurence[i]<<endl;
  }


   free(ImgIn);
   return 1;
}

*/
