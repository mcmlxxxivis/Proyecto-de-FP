#include<stdlib.h>
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE*ap;

struct Usuarios{
	char nombre[20];
	char contra[20];
	int jj,jg,jp,puntos;
};

Usuarios U[100];
void registrar();
void iniciar();
int buscar(char N[],char C[]);

main(){
	
	int op;
	
	printf("1. Registrar\n");
	printf("2. Iniciar Sesion\n");
	scanf("%d",&op);
	
	switch(op){
		
		case 1: registrar();break;
		case 2: break;
	}
	
}

void registrar(){
	char nom[20];
	char con[20];
	int j=0,g=0,p=0,pun=0;
	
	
	
	printf("Dame tu nombre: ");
	fflush(stdin);
	gets(nom);
	printf("Dame tu contra: ");
	fflush(stdin);
	gets(con);
	if(buscar(nom,con)==1)
	printf("Este usuario ya esta registrado");
	else{
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
