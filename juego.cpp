#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

FILE*ap;

struct Usuarios{
	char nombre[20];
	char contra[20];
	int jj,jg,jp,puntos;
};

Usuarios U[100];
void registrar();
int iniciar();
int buscar(char N[],char C[]);
void aleatorios(int *nA);
void elegir(int op);
void preguntas(int nA);

int PuntosFn=0;//Variables globales

main(){
	system("title 100 mexicanos dijeron");
    int op,bucle=0,Val;
	do{
        system("cls");
        printf("1. Registrar\n");
        printf("2. Iniciar Sesion\n");
        printf("3. Salir del menu inicial\n");
        scanf("%d",&op);
        switch(op){
            case 1: 
                registrar();
            break;
            case 2: 
                Val=iniciar();
                if(Val==1)
                    bucle=1;
                if(Val==0)
                    bucle=0;
            break;
            case 3:
                bucle=1;
            break;
            default:
                printf("Opci%cn no valida\n",162);
            break;
        }
    }while(bucle==0);
    system("pause");
    system("cls");
	int *nAleatorio;
	nAleatorio=(int*)malloc(9*sizeof(int*));//memoria para 9 numeros
	aleatorios(nAleatorio);
	for(int i=0; i<4; i++){//Ronda de preguntas
		printf("Ronda %d\n",i+1);
		preguntas(nAleatorio[i]);
	}
	free(nAleatorio);
}

void registrar(){
	system("title Registro");
    char nom[20];
	char con[20];
	int j=0,g=0,p=0,pun=0;
	
	printf("Dame tu nombre: ");
	fflush(stdin);
	gets(nom);
	printf("Dame tu contra: ");
	fflush(stdin);
	gets(con);
	if(buscar(nom,con)==1){
	    printf("Este usuario ya esta registrado\n");
        system("pause");
	}else{
        ap=fopen("Usuarios.txt","a");
        fprintf(ap,"\n");
        fprintf(ap,"%s %s %d %d %d %d",nom,con,j,g,p,pun);
        fclose(ap);
	}
}

int buscar(char N[],char C[]){
	
		ap=fopen("Usuarios.txt","r");
		int i=0;
		while(feof(ap)==0)
		{
			fscanf(ap,"%s",U[i].nombre);
			fscanf(ap,"%s",U[i].contra);
			fscanf(ap,"%d",&U[i].jj);
			fscanf(ap,"%d",&U[i].jg);
			fscanf(ap,"%d",&U[i].jp);
			fscanf(ap,"%d",&U[i].puntos);
			i++;
		}
		for(int j=0;j<i;j++)
			if(strcmp(U[j].nombre,N)==0)
				if(strcmp(U[j].contra,C)==0){
					fclose(ap);
					return 1;
				}
		fclose(ap);
		return 0;
}

int iniciar(){
	system("title Inicio de sesion");
    char nom[20],Reg;
	char con[20];
	int j=0,g=0,p=0,pun=0,Desbloqueo=0,Val;
	do{
        system("cls");
        printf("Dame tu nombre: ");
        fflush(stdin);
        gets(nom);
        printf("Dame tu contra: ");
        fflush(stdin);
        gets(con);
        if(buscar(nom,con)==1){
            printf("Bienvenidoooooo %s\n",nom);
            Desbloqueo=1;
            Val=1;
        }else{
            printf("Usuario o contrase%ca incorrectos, verifica de nuevo\n",164);
            printf("Si eres nuevo usuario presiona x ");
            scanf("%c",&Reg);
            if(Reg==120 || Reg==88){
                Desbloqueo=1;
                Val=0;
            }
        }
    }while(Desbloqueo==0);
    return(Val);
}

void aleatorios(int *nA){
	
	int newN, found;
	
		srand(time(NULL));
		
	for (int i = 0; i < 9; i++) {
    found = 0;
    while (!found) {
      newN = rand() % 9+1; // Generamos un número aleatorio segun el numero de preguntas
      found = 1;
      // Comprobamos si el número ya existe en el array
      for (int j = 0; j < i; j++) {
        if (nA[j] == newN) {
          found = 0;
          break;
        }
      }
    }
    nA[i] = newN;
  }
}

void preguntas(int nA ){
	system("title Ronda de preguntas");
    int Puntos=0,Cont1=0,Cont2=0,Cont3=0,Cont4=0;
	char Res[18];
	
	switch(nA){
		case 1:
			Cont1=0,Cont2=0,Cont3=0,Cont4=0;
            for(int i=1;i<=4;i++){
                char Pos1Res[]="naranja",Pos2Res1[]="manzana",Pos3Res2[]="sandia",Pos4Res3[]="limon"; 
                printf("Especifica una fruta que tenga semillas\n");
                gets(Res);
                strlwr(Res);
                if(strcmp(Res,Pos1Res)==0){
                    if(Cont1==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 30 puntos\n",Res);
                        Puntos=Puntos+35;
                        Cont1=1;//agraga valor al conteo y no se repite la respuesta
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos2Res1)==0){
                    if(Cont2==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 25 puntos\n",Res);
                        Puntos=Puntos+25;
                        Cont2=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos3Res2)==0){
                    if(Cont3==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 10 puntos\n",Res);
                        Puntos=Puntos+10;
                        Cont3=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos4Res3)==0){
                    if(Cont4==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                       system("color A0");
                        printf("%s ........... 5 puntos\n",Res);
                        Puntos=Puntos+5;
                        Cont4=1;
                        system("color 0F");
                    }
                }
                printf("\n\n");
            }
            PuntosFn=PuntosFn+Puntos;
            printf("El total de puntos es en la ronda es de %d\n\n",Puntos);
            printf("Tu puntaje en el juego es de %d\n\n",PuntosFn);
            printf("Presiona una tecla si estas listo");
            getchar();
            system("cls");
		break;
		case 2: 
            Cont1=0,Cont2=0,Cont3=0,Cont4=0;
            for(int i=1;i<=4;i++){
                char Pos1Res[]="pescado",Pos2Res1[]="pollo",Pos3Res2[]="carne",Pos4Res3[]="papas"; 
                printf("Escribe un alimento que se frie\n");
                gets(Res);
                strlwr(Res);
                if(strcmp(Res,Pos1Res)==0){
                    if(Cont1==1){//sentencias para que no se repita la respuesta
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 35 puntos\n",Res);
                        Puntos=Puntos+35;
                        Cont1=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos2Res1)==0){
                    if(Cont2==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 25 puntos\n",Res);
                        Puntos=Puntos+25;
                        Cont2=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos3Res2)==0){
                    if(Cont3==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 15 puntos\n",Res);
                        Puntos=Puntos+15;
                        Cont3=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos4Res3)==0){
                    if(Cont4==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 10 puntos\n",Res);
                        Puntos=Puntos+10;
                        Cont4=1;
                        system("color 0F");
                    }
                }
                printf("\n\n");
            }
            PuntosFn=PuntosFn+Puntos;
            printf("El total de puntos es en la ronda es de %d\n\n",Puntos);
            printf("Tu puntaje en el juego es de %d\n\n",PuntosFn);
            printf("Presiona una tecla si estas listo");
            getchar();
            system("cls");
		break;
		case 3:
			Cont1=0,Cont2=0,Cont3=0,Cont4=0;//Reseta la repetición de respuestas
            for(int i=1;i<=4;i++){//Otra ronda de preguntas
                char Pos1Res[]="chamaco",Pos2Res1[]="bebe",Pos3Res2[]="escuincle",Pos4Res3[]="chiquillo"; 
                printf("Escribe una forma popular de decir ni%co\n",164);
            	gets(Res);
                strlwr(Res);
                if(strcmp(Res,Pos1Res)==0){
                    if(Cont1==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 35 puntos\n",Res);
                        Puntos=Puntos+35;
                        Cont1=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos2Res1)==0){
                    if(Cont2==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 20 puntos\n",Res);
                        Puntos=Puntos+20;
                        Cont2=1;
                        system("color 0F");
                    }
                }
                if( strcmp(Res,Pos3Res2)==0){
                    if(Cont3==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 15 puntos\n",Res);
                        Puntos=Puntos+15;
                        Cont3=1;
                        system("color 0F");
                    }
                }
                if( strcmp(Res,Pos4Res3)==0){
                    if(Cont4==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 10 puntos\n",Res);
                        Puntos=Puntos+10;
                        Cont4=1;
                        system("color 0F");
                    }
                }
                printf("\n\n");
            }
            PuntosFn=PuntosFn+Puntos;
            printf("El total de puntos es en la ronda es de %d\n\n",Puntos);
            printf("Tu puntaje en el juego es de %d\n\n",PuntosFn);
            printf("Presiona una tecla si estas listo");
            getchar();
            system("cls");
		break;
		case 4:
			Cont1=0,Cont2=0,Cont3=0,Cont4=0;
            for(int i=1;i<=4;i++){//Otra ronda de preguntas
                char Pos1Res[]="tacos",Pos2Res1[]="pozole",Pos3Res2[]="enchiladas",Pos4Res3[]="quesadillas"; 
                printf("Antojitos mexicanos mas populares\n");
                gets(Res);
                strlwr(Res);
                if(strcmp(Res,Pos1Res)==0){
                    if(Cont1==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 41 puntos\n",Res);
                        Puntos=Puntos+41;
                        Cont1=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos2Res1)==0){
                    if(Cont2==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 19 puntos\n",Res);
                        Puntos=Puntos+19;
                        Cont2=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos3Res2)==0){
                    if(Cont3==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 18 puntos\n",Res);
                        Puntos=Puntos+18;
                        Cont3=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos4Res3)==0){
                    if(Cont4==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 9 puntos\n",Res);
                        Puntos=Puntos+9;
                        Cont4=1;
                        system("color 0F");
                    }
                }
                printf("\n\n");
            }
            PuntosFn=PuntosFn+Puntos;
            printf("El total de puntos es en la ronda es de %d\n\n",Puntos);
            printf("Tu puntaje en el juego es de %d\n\n",PuntosFn);
            printf("Presiona una tecla si estas listo");
            getchar();
            system("cls");
		break;
		case 5:
			Cont1=0,Cont2=0,Cont3=0,Cont4=0;
            for(int i=1;i<=4;i++){//Otra ronda de preguntas
                char Pos1Res[]="cabeza",Pos2Res1[]="estomago",Pos3Res2[]="espalda",Pos4Res3[]="piernas"; 
                printf("Parte del cuerpo en donde los dolores son frecuentes\n");
                gets(Res);
                strlwr(Res);
                if(strcmp(Res,Pos1Res)==0){
                    if(Cont1==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 45 puntos\n",Res);
                        Puntos=Puntos+45;
                        Cont1=1;
                        system("color 0F");
                    }
                }
                if( strcmp(Res,Pos2Res1)==0){
                    if(Cont2==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 29 puntos\n",Res);
                        Puntos=Puntos+29;
                        Cont2=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos3Res2)==0){
                    if(Cont3==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 17 puntos\n",Res);
                        Puntos=Puntos+17;
                        Cont3=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos4Res3)==0){
                    if(Cont4==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 9 puntos\n",Res);
                        Puntos=Puntos+9;
                        Cont4=1;
                        system("color 0F");
                    }
                }
                printf("\n\n");
            }
            PuntosFn=PuntosFn+Puntos;
            printf("El total de puntos es en la ronda es de %d\n\n",Puntos);
            printf("Tu puntaje en el juego es de %d\n\n",PuntosFn);
            printf("Presiona una tecla si estas listo");
            getchar();
            system("cls");
		break;
		case 6:
			Cont1=0,Cont2=0,Cont3=0,Cont4=0;
            for(int i=1;i<=4;i++){//Otra ronda de preguntas
                char Pos1Res[]="luz",Pos2Res1[]="celular",Pos3Res2[]="computadora",Pos4Res3[]="television"; 
                printf("Algo que prendes y apagas todos los d%cas\n",161);
                gets(Res);
                strlwr(Res);
                if(strcmp(Res,Pos1Res)==0){
                    if(Cont1==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 38 puntos\n",Res);
                        Puntos=Puntos+38;
                        Cont1=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos2Res1)==0){
                    if(Cont2==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 26 puntos\n",Res);
                        Puntos=Puntos+26;
                        Cont2=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos3Res2)==0){
                    if(Cont3==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 15 puntos\n",Res);
                        Puntos=Puntos+15;
                        Cont3=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos4Res3)==0){
                    if(Cont4==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 11 puntos\n",Res);
                        Puntos=Puntos+11;
                        Cont4=1;
                        system("color 0F");
                    }
                }
                printf("\n\n");
            }
            PuntosFn=PuntosFn+Puntos;
            printf("El total de puntos es en la ronda es de %d\n\n",Puntos);
            printf("Tu puntaje en el juego es de %d\n\n",PuntosFn);
            printf("Presiona una tecla si estas listo");
            getchar();
            system("cls");
		break;
		case 7:
			Cont1=0,Cont2=0,Cont3=0,Cont4=0;
			for(int i=1;i<=4;i++){//Otra ronda de preguntas
                char Pos1Res[]="pavo",Pos2Res1[]="bacalao",Pos3Res2[]="romeritos",Pos4Res3[]="pierna"; 
                printf("Platillo t%cpico para la cena de navidad\n",161);
                gets(Res);
                
                if(strcmp(Res,Pos1Res)==0){
                    if(Cont1==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 40 puntos\n",Res);
                        Puntos=Puntos+40;
                        Cont1=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos2Res1)==0){
                    if(Cont2==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 31 puntos\n",Res);
                        Puntos=Puntos+31;
                        Cont2=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos3Res2)==0){
                    if(Cont3==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 14 puntos\n",Res);
                        Puntos=Puntos+14;
                        Cont3=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos4Res3)==0){
                    if(Cont4==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 9 puntos\n",Res);
                        Puntos=Puntos+9;
                        Cont4=1;
                        system("color 0F");
                    }
                }
                printf("\n\n");
            }
            PuntosFn=PuntosFn+Puntos;
            printf("El total de puntos es en la ronda es de %d\n\n",Puntos);
            printf("Tu puntaje en el juego es de %d\n\n",PuntosFn);
            printf("Presiona una tecla si estas listo");
            getchar();
            system("cls");
		break;
		case 8:
			Cont1=0,Cont2=0,Cont3=0,Cont4=0;
			for(int i=1;i<=4;i++){//Otra ronda de preguntas
                char Pos1Res[]="lana",Pos2Res1[]="money",Pos3Res2[]="feria",Pos4Res3[]="billete"; 
  				printf("Menciona una forma popular de decir dinero\n");
                gets(Res);
                strlwr(Res);
                if(strcmp(Res,Pos1Res)==0){
                    if(Cont1==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 40 puntos\n",Res);
                        Puntos=Puntos+40;
                        Cont1=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos2Res1)==0){
                    if(Cont2==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 31 puntos\n",Res);
                        Puntos=Puntos+31;
                        Cont2=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos3Res2)==0){
                    if(Cont3==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 14 puntos\n",Res);
                        Puntos=Puntos+14;
                        Cont3=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos4Res3)==0){
                    if(Cont4==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                       system("color A0");
                        printf("%s ........... 9 puntos\n",Res);
                        Puntos=Puntos+9;
                        Cont4=1;
                        system("color 0F");
                    }
                }
                printf("\n\n");
            }
            PuntosFn=PuntosFn+Puntos;
            printf("El total de puntos es en la ronda es de %d\n\n",Puntos);
            printf("Tu puntaje en el juego es de %d\n\n",PuntosFn);
            printf("Presiona una tecla si estas listo");
            getchar();
            system("cls");
		break;
		case 9:
            Cont1=0,Cont2=0,Cont3=0,Cont4=0;
            for(int i=1;i<=4;i++){//Otra ronda de preguntas
                char Pos1Res[]="cafe",Pos2Res1[]="jugo",Pos3Res2[]="leche",Pos4Res3[]="atole"; 
                printf("Nombra una bebida que se toma en el desayuno\n");
                gets(Res);
                strlwr(Res); 
                if(strcmp(Res,Pos1Res)==0){
                    if(Cont1==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 40 puntos\n",Res);
                        Puntos=Puntos+40;
                        Cont1=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos2Res1)==0){
                    if(Cont2==1){
                        printf("Ya usaste esa respuesta\n");
                    }else{
                        system("color A0");
                        printf("%s ........... 31 puntos\n",Res);
                        Puntos=Puntos+31;
                        Cont2=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos3Res2)==0){
                    if(Cont3==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 14 puntos\n",Res);
                        Puntos=Puntos+14;
                        Cont3=1;
                        system("color 0F");
                    }
                }
                if(strcmp(Res,Pos4Res3)==0){
                    if(Cont4==1){
                        printf("Ya usaste esa respuesta");
                    }else{
                        system("color A0");
                        printf("%s ........... 9 puntos\n",Res);
                        Puntos=Puntos+9;
                        Cont4=1;
                        system("color 0F");
                    }
                }
                printf("\n\n");
            }
            PuntosFn=PuntosFn+Puntos;
            printf("El total de puntos es en la ronda es de %d\n\n",Puntos);
            printf("Tu puntaje en el juego es de %d\n\n",PuntosFn);
            printf("Presiona una tecla si estas listo");
            getchar();
            system("cls");
		break;
    }
}
