/*#include <stdio.h>
#include <iostream>
#include "image_ppm.h"
using namespace std;

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille, nTaille3, nR = 0,nG = 0,nB = 0;
  int moyR, moyG, moyB, cpt = 0;

  if (argc != 3)
     {
       printf("Usage: ImageIn.ppm ImageOut.ppm \n");
       exit (1) ;
     }

   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);

   OCTET *ImgIn, *ImgOut, *R, *G, *B;

   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
   nTaille3 = nTaille * 3;

   allocation_tableau(ImgIn, OCTET, nTaille3);
   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille3);

   allocation_tableau(R, OCTET, nTaille);
   allocation_tableau(G, OCTET, nTaille);
   allocation_tableau(B, OCTET, nTaille);

   planR(R,ImgIn,nTaille);
   planV(G,ImgIn,nTaille);
   planB(B,ImgIn,nTaille);

 for (int i = 0; i < nTaille; i++) {

    for(int a = -1; a < 4; a++) {

      for(int b = -1; b < 4; b++) {
            int val=i+(a*nW)+b;
if(val>0&&val<nTaille)
       {

        moyR+= R[val];
      // cout<<"merde"<<endl;
        moyG+= G[val];
        moyB+= B[val];}
      }
    }

  ImgOut[cpt] = moyR/25;
  ImgOut[cpt+1] = moyG/25;
  ImgOut[cpt+2] = moyB/25;
  moyR = 0;
  moyG = 0;
  moyB = 0;
  cpt+=3;
 }

 ecrire_image_ppm(cNomImgEcrite, ImgOut,  nH, nW);
 free(ImgIn);
 return 1;
}

*/
