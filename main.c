#include <stdio.h>
#include "libs/libbmp.h"
#include "libs/imghelpers.h"

int main(){
  //Utilize apenas imagens .bmp com o formato 24 (true color)
  // converta em: https://online-converting.com/image/convert2bmp/
  bmp_img img;
  char filename[] = "lenna.bmp";
  printf("\n");
  IMG_TAM t = pegarTamanho(filename);
  int l = t.qtdLinhas,c = t.qtdColunas;
  int R[l][c];
  int G[l][c];
  int B[l][c]; 
  carregaImagem(t,R,G,B,filename);
  
  // manipule sua imagem aqui. 
/*Faça um programa que inverta uma imagem no eixo y ( ou seja espelhe a imagem). */
int aux=0;
int k=0;

for(int i=0;i<l;i++){
  for(int j=0, k=c-1;j<(c/2); j++, k--){
//Tentando atraves da variavel aux 

int red =  R[i][j];
int green =  G[i][j];
int blue =  B[i][j];

 R[i][j]= R[i][k];
 G[i][j]= G[i][k];
 B[i][j]= B[i][k];

    R[i][k] = red;
    G[i][k] = green;
    B[i][k] = blue;

  }
}
  
  salvaImagem(t,R,G,B,"saida.bmp");
  mostrarNoReplit("saida.bmp");
  return 0;
}
