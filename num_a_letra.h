#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100


extern char revisada[MAX]; //LA ENTRADA UNA VEZ REVISADA PARA Q EL USUARIO NO ENTRE LETRAS
extern char opcio[MAX]; //OPCION SELECCIONADA 1 CASTELLANO 2 CATALAN
char * traduce_a_letras(char revisada[]); //FUNCION Q "TRADUCE" AL CASTELLANO
/*********************************MAIN DEL PROGRAMA**************************************/

char * convertir(char entrada[]){
         return traduce_a_letras(entrada);
}
char * traduce_a_letras(char revisada[]){

	char unidades[MAX][MAX]={"uno ","dos ","tres ","cuatro ","cinco ","seis ","siete ","ocho ","nueve "};
	char decenas[MAX][MAX]={"diez ","veinte ","treinta ","cuarenta ","cincuenta ","sesenta ","setenta ","ochenta ","noventa "};
	char centenas[MAX][MAX]={"ciento ","doscientos ","trescientos ","cuatrocientos ","quinientos ","seiscientos ","setecientos ","ochocientos ","novecientos "};
	char decenasespeciales[MAX][MAX]={"diez ","once ","doce ","trece ","catorce ","quince ","dieciseis ","diecisiete ","dieciocho ","diecinueve "};

	int numerito;
	int numeritoposterior;
	int i;
	int bandera;
	int posicionactual;
   int longitud;//LONGITUD DE LA CADENA ENTRADA
   char actualposterior[MAX];//VALOR DEL NUMERO POSTERIOR
   char salida[MAX];//SALIDA YA CONVERTIDA A LETRAS
   char actual[MAX];//VALOR DEL NUMERO ACTUAL
   strcpy(salida,"");

	longitud = strlen(revisada);

	for (i=longitud;i >= 1 ;i--){
		bandera = longitud - i;
		posicionactual = longitud - bandera;

		switch(posicionactual){
			case 1:case 4:case 7: //unidades

				actual[0] = revisada[bandera];actual[1] = '\0';
				numerito = atoi(actual);
				if (numerito != 1){
					strcat(salida,unidades[numerito-1]);
				}
				else{
					if (longitud == 4 && posicionactual == 4){
					}
					else if(longitud == 7 && posicionactual == 7){
						strcat(salida,"un ");
					}else{
						strcat(salida,unidades[numerito-1]);
					}
				}
				break;

			case 2:case 5:case 8: //decenas

				actual[0] = revisada[bandera];actual[1] = '\0';
				numerito = atoi(actual);
				actualposterior[0] = revisada[bandera+1];actualposterior[1] = '\0';
				numeritoposterior = atoi(actualposterior);
				if (numerito == 1){
					if (numeritoposterior != 0){
						strcat(salida,decenasespeciales[numeritoposterior]);
						i--;
					}else{
						strcat(salida,decenas[numerito-1]);
					}
				}
				else{
					strcat(salida,decenas[numerito-1]);
					if (numeritoposterior !=0 && numerito != 0) strcat(salida,"y ");
				}

				break;

			case 3:case 6: //centenas

				actual[0] = revisada[bandera];actual[1] = '\0';
				numerito = atoi(actual);
				if (posicionactual == 6 && longitud > 6){
					if (longitud == 7 && revisada[bandera-1] == '1'){
						strcat(salida,"millon ");
					}else{
					strcat(salida,"millones ");
					}
				}
				else if (posicionactual == 3 && longitud > 3){
					if(revisada[bandera-1] =='0' && revisada[bandera-2] == '0' && revisada[bandera-3] == '0'){
					}else{
					strcat(salida,"mil ");}
				}
				if (numerito == 1 && revisada[bandera+1] == '0' && revisada[bandera+2] == '0'){
					strcat(salida,"cien ");
				}else{
					strcat(salida,centenas[numerito - 1]);
				}
				break;

		}//fin del switch

	}//fin del for
   return salida;
} //fin de funcion

