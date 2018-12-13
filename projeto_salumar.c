#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#define MAX 200

HANDLE hConsole;
	
	char assentos[MAX];
	int lugares;
	int colunas;
	int codReserva[MAX];
	int numReserva = 0;
	int idade,qtdCliente = 1;
	int indice = 0;
	float valorPassagem,totalVendido = 0;
	char destino[50];
	int flagConfirmacao = 0;
	int idades[MAX];	

void reservar(int qtdPassagens,float valorP);
void cancelarReserva(int qtdPassagens, int valorP, int *idades);
void confirmarReserva(int qtdPassagens, int valorP, int *idades);
void leValidaDestino(char destino[50]);
void leValidaAssento(char destino[50]);
void imprimeLugares();
int leValidaIdade(int contador);
void leValidaValor(float *valorP);
float calculaPassagem(float valorP, int *idades, int qtdPassagens);
int menu(char comando, int *qtdPassageiros, float valorP);
void verificaVoo();
int leValidaQtdPassageiros();
char desejaComprar();





void verificaVoo(){
	int disponivel = 0, reservado = 0, confirmado = 0;
	
	int i;
	
	for( i = 0; i < lugares; i++){
		
			if(assentos[i] == 'D')
				disponivel += 1;
			if(assentos[i] == 'R')
				reservado += 1;
			if(assentos[i] == 'C')
				confirmado += 1;	 		
			}
	system("cls");
	printf("SITUAÇÂO DO VÔO\n\n");
	printf("\n\nASSENTOS DISPONÍVEIS: %d\n",disponivel);
	printf("ASSENTOS RESERVADOS: %d\n",reservado);
	printf("ASSENTOS CONFIRMADOS: %d\n\n",confirmado);
	
	printf("TOTAL EM REAIS DE VENDAS CONFIRMADAS: R$ %.2f\n\n",totalVendido);
system("pause");
	
}

void confirmarReserva(int qtdPassagens, int valorP, int *idades){
		system("cls");

	int i,j, num,flag = 1,cr;
	char continuar;
	float total;

total = calculaPassagem( valorP,idades,qtdPassagens);
 do{
 
printf("DESEJA CONFIRMAR UMA RESERVA DE %d PASSAGEM(NS) NO TOTAL DE R$ %.2f COM DESTINO A %s?(S/N)\n\n",qtdPassagens,total,destino);
continuar = getch();
continuar = toupper(continuar);
if(continuar != 'S' && continuar != 'N') printf("\n OPÇÃO INVÁLIDA, TENTE NOVAMENTE!\n\n");

}while(continuar != 'S' && continuar != 'N');
if(continuar == 'S'){
	totalVendido += total;
	for(j = 0;j< qtdPassagens;j++){

	do{
		printf("IFORME SEU CÓDIGO DE RESERVA DO PASSAGEIRO %d: ", j + 1);
		scanf("%d", &cr);
		
			if(cr > qtdCliente || cr < 1){
				  printf("\nCÓDIGO NÂO ENCONTRADO, INSIRA OUTRO!\n");				
			}
			
					
	}while(cr > qtdCliente || cr < 1);
	 cr -= 1;
	 num = codReserva[cr];
	assentos[num] = 'C';
	system("cls");
	printf("RESERVA CONFIRMADA COM SUCESSO.\n\n");

}
system("pause");
}else{
	return;
}

}
void reservar(int qtdPassagens,float valorP){
	float total;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		 	
	int i,j,x,y,z,flag = 1;

		
		
			for(i = 0; i < qtdPassagens; i++){
				idades[i] = leValidaIdade(i + 1);
				}
				system("cls");
				
		
		for(j = 0;j< qtdPassagens;j++){
			
		imprimeLugares();
	do{
		do{
		
		printf("DIGITE O CÓDIGO FILEIRA ASSENTO QUE VOCÊ DESEJA  PASSAGEIRO(A) %d: ",j+1);
		scanf("%d", &x);
		printf("\nDIGITE O CÓDIGO COLUNA ASSENTO QUE VOCÊ DESEJA  PASSAGEIRO(A)  %d: ",j+1);
		scanf("%d", &y);
		z = ((x)*9) + (y);
		if(z > lugares || z < 0) printf("\nESTE ASSENTO NÃO EXISTE, INSIRA OUTRO!\n");
		
		}while(z > lugares || z < 0);
	
	
	if(assentos[z] != 'C' && assentos[z] != 'R'){
		flag = 0;
			
		assentos[z] = 'R';
		
		numReserva += 1;
		
				 codReserva[indice] =  z;
		
	}else{
		printf("\nASSENTO NÃO DISPONÍVEL, SELECIONE OUTRO!\n");
	}
		
	}while(flag != 0);
	
	system("cls");
	printf("SEU CÓDIGO DE RESERVA É: %d\n\n",numReserva);
printf("_______________________________________________\n\n");
		indice +=1;
		}

total = calculaPassagem(valorP,idades,qtdPassagens);
printf("\n\n\nO VALOR DA(S) PASSAGEM(S) É %.2f\n",total);
printf("\n_______________________________________________\n");
system("pause");
}

void cancelarReserva(int qtdPassagens, int valorP, int *idades){
			system("cls");

	int i, j, flag = 1,cr;
char continuar;
float total;
total = calculaPassagem( valorP,idades,qtdPassagens);
do{

printf("DESEJA CANCELAR UMA RESERVA DE %d PASSAGEM(NS) NO TOTAL DE R$ %.2f COM DESTINO A %s?(S/N)\n\n",qtdPassagens,total,destino);
continuar = getch();
continuar = toupper(continuar);
if(continuar != 'S' && continuar != 'N') printf("\n OPÇÃO INVÁLIDA, TENTE NOVAMENTE!\n\n");

}while(continuar != 'S' && continuar != 'N');
if(continuar == 'S'){

for(j = 0;j< qtdPassagens;j++){
	do{
		printf("INFORME SEU CÓDIGO DE RESERVA DO PASSAGEIRO %d: ", j + 1);
		scanf("%d", &cr);
		
	
			if(cr > qtdCliente || cr < 1){
				  printf("\nCÓDIGO NÃO ENCONTRADO, INSIRA OUTRO!\n");				
			}
			
					
	}while(cr > qtdCliente || cr < 1);
	 cr -= 1;
	 i = codReserva[cr];
	
	assentos[i] = 'D';
numReserva = numReserva - qtdPassagens;
		system("cls"); 
	printf("RESERVA CANCELADA COM SUCESSO.\n\n");
	
}
system("pause");
}else{
	return;
}
}

void leValidaDestino(char destino[50]){
	do{
	
	printf("\nQUAL SERÁ O DESTINO? ");
	gets(destino);
	if(strcmp(destino,"")==0)
		printf("CAMPO OBRIGATÓRIO*\n");
	}while(strcmp(destino,"")==0);
	
}

void leValidaAssento(char destino[50]){
	
	do{
		printf("\nQUAL É A QUANTIDADE DE ASSENTOS EXISTENTES PARA O VOO COM DESTINO A %s? ",destino);
		scanf("%d", &lugares);
		
		if(lugares < 90 || lugares > 200) 
			printf("ESTE VALOR É INVÁLIDO, INSIRA NOVAMENTE!\n");
		
	}while(lugares < 90 || lugares > 200);
	
	int i;
				
	for( i = 0; i < lugares; i++){
				assentos[i] = 'D'; 
					
			}	
}

void imprimeLugares(){
 //Cores 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

	int n, i, numLinhas = 0,j = 9;
		//imprime o numero das colunas
		printf("   %s", "012345678\n");
		//imprime o numero das linhas
		printf("%d  ",numLinhas);
		
		for(n = 0;n < lugares;n++){
			
			if(n == j){
				if(assentos[n] == 'D'){
				printf("\n%d  ",++numLinhas);
				SetConsoleTextAttribute(hConsole, 10);
				printf("%c",assentos[n]);
				SetConsoleTextAttribute(hConsole, saved_attributes);
				}else if(assentos[n] == 'R'){
				printf("\n%d  ",++numLinhas);	
				SetConsoleTextAttribute(hConsole, 12);								
				printf("%c",assentos[n]);
				SetConsoleTextAttribute(hConsole, saved_attributes);	
				}else{
					printf("\n%d  ",++numLinhas);
					SetConsoleTextAttribute(hConsole,  9);								
					printf("%c",assentos[n]);
					SetConsoleTextAttribute(hConsole, saved_attributes);
				}
				
				j += 9;
			}else{
				if(assentos[n] == 'D'){
					SetConsoleTextAttribute(hConsole, 10);								
					printf("%c",assentos[n]);
					SetConsoleTextAttribute(hConsole, saved_attributes);
				}else if(assentos[n] == 'R'){
					SetConsoleTextAttribute(hConsole, 12);								
					printf("%c",assentos[n]);
					SetConsoleTextAttribute(hConsole, saved_attributes);
				}else{
					SetConsoleTextAttribute(hConsole,  9);								
					printf("%c",assentos[n]);
					SetConsoleTextAttribute(hConsole, saved_attributes);
				}
			}
		}
	
	printf("\n\n");
		SetConsoleTextAttribute(hConsole, 10);								
		printf("D - DISPONÍVEL ");
		SetConsoleTextAttribute(hConsole, saved_attributes);
		SetConsoleTextAttribute(hConsole,  12);								
		printf(" R - RESERVADO ");
		SetConsoleTextAttribute(hConsole, saved_attributes);
		SetConsoleTextAttribute(hConsole,  9);								
		printf(" C - CONFIRMADO\n\n");
		SetConsoleTextAttribute(hConsole, saved_attributes);
}

int leValidaIdade(int contador){
	int idade;
	do{
		printf("\nQUAL É A IDADE DO PASSAGEIRO %d? ",contador);
		scanf("%d", &idade);
		
		if(idade < 1 || idade > 125) printf("ESTA IDADE É INVÁLIDO, TENTE NOVAMENTE!\n");
	}while(idade < 1 || idade > 125);	
	return idade;	
}

void leValidaValor(float *valorP){
	
	do{
		printf("\nQUAL É O VALOR DA PASSAGEM? ");
		scanf("%f",valorP);
		if(*valorP < 1) printf("ESTE VALOR É INVÁLIDO, TENTE NOVAMENTE!\n");	
		
	}while(*valorP < 1);
}

float calculaPassagem(float valorP, int *idades, int qtdPassagens){
	int ih,contador = 0;
	float acumulador,total = 0;
	for(ih = 0; ih< qtdPassagens;ih++){
		if(idades[ih] <= 5) contador++;
	}
	
	if(contador > 0){
		qtdPassagens = qtdPassagens - contador;
		acumulador = (valorP * 0.5) * contador;
	}
	
	return total =  acumulador + qtdPassagens * valorP;
		
	
}
int leValidaQtdPassageiros(){
	int qtd;
	do{
	printf("QUANTAS PASSAGENS O SENHOR(A) DESEJA? ");
	scanf("%d",&qtd);
	if(qtd < 1 || qtd > lugares) printf("\n QUANTIDADE INVÁLIDA.");
	}while(qtd < 1 || qtd > lugares);
	return qtd;
}

int menu(char comando, int *qtdPassageiros, float valorP){

	
	
	switch(comando){
		
		case 'v':
			verificaVoo();
			return 0;
		case 'r':
			system("cls");	
			if(flagConfirmacao >= 1){
				printf("VOCÊ JÀ FEZ A RESERVA!\n");
				system("pause");
				return 0;
			}
			reservar(*qtdPassageiros,valorPassagem);
			flagConfirmacao = 1;
			return 0;
		case 'c':
			system("cls");	
			if(flagConfirmacao == 0){
			printf("VOCÊ DEVE FAZER UMA RESERVA PRIMEIRO!\n");
			reservar(*qtdPassageiros,valorPassagem);	
			}else if(flagConfirmacao == 2){
			printf("VOCÊ JÀ FEZ A CONFIRMAÇÂO E NÂO PODE CANCELAR\n\n");
			system("pause");
			return 0; 
			}
			cancelarReserva(*qtdPassageiros, valorP, idades);	
			flagConfirmacao = 0;
			return 0;
		case 'e':
			system("cls");	
			if(flagConfirmacao == 0){
			printf("VOCÊ DEVE FAZER UMA RESERVA PRIMEIRO!\n");
			reservar(*qtdPassageiros,valorPassagem);	
			}else if(flagConfirmacao == 2){
			printf("VOCÊ JÀ FEZ A CONFIRMAÇÂO\n\n");
			system("pause");
			return 0;
			}
			confirmarReserva(*qtdPassageiros, valorP, idades);
			flagConfirmacao = 2;
			return 0;
		case 'n':
			system("cls");
			desejaComprar();
			*qtdPassageiros = leValidaQtdPassageiros();
			qtdCliente =  qtdCliente + *qtdPassageiros;
			flagConfirmacao = 0;
			return 0;	
		case 'm':
			system("cls");
			imprimeLugares();
			system("pause");
			return 0;
		case 'd':
			system("cls");
			leValidaDestino(destino);
 			leValidaValor(&valorPassagem);
			leValidaAssento(destino);
			return 0;		
		case 'f':
			return 1;
		
	}
	
	
}
char desejaComprar(){
	char deseja;
	do{
	
	printf("DESEJA COMPRAR UMA PASSAGEM COM DESTINO A %s POR %.2f REAIS? (S/N)\n",destino,valorPassagem);
	deseja = getch();
	
	deseja = toupper(deseja);
	if(deseja != 'S' && deseja != 'N') printf("OPÇÂO INVÀLIDA!, TENTE NOVAMENTE\n\n");
	}while(deseja != 'S' && deseja != 'N');
	return deseja;
	
}
char leValidaOpcao(){
	char comando;
	printf("DIGITE:\n");
	printf("   V - VERIFICAR A OCUPAÇÃO DE VOO\n");
	printf("   R - EFETUAR UMA RESERVA\n");
	printf("   C - CANCELAR UMA RESERVA\n");
	printf("   E - EFETIVAR A CONFIRMAÇÃO DE VENDA DA RESERVA\n");
	printf("   M - MOSTRAR A SITUAÇÃO DOS ASSENTOS DO VOO\n");
	printf("   N - INSERIR UM NOVO CLIENTE\n");
	printf("   D - INSERIR UM NOVO DESTINO\n");
	printf("   F - FINALIZAR\n");
	do{
		comando = getch();
		comando = tolower(comando);
		if(comando != 'v' && comando != 'r' && comando != 'c' && comando != 'e' && comando != 'm' && comando != 'n' && comando != 'd' && comando != 'f') printf("OPÇÂO INVÀLIDA, TENTE NOVAMENTE!\n\n");
	}while(comando != 'v' && comando != 'r' && comando != 'c' && comando != 'e' && comando != 'm' && comando != 'n' && comando != 'd' && comando != 'f');
	return comando;
	
}


int main(){
	char deseja,comando;
	int i, qtdPassageiros,contador;	
	
	//Cores
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    
	
	SetConsoleTitle("SALUMAR LINHAS AEREAS");
	
	setlocale(LC_ALL, "Portuguese");
	
				
				
 	leValidaDestino(destino);
 	leValidaValor(&valorPassagem);
	leValidaAssento(destino);
	system("cls");
	SetConsoleTextAttribute(hConsole, 14);
	printf("_______________________________________________\n\n");
	printf("             SALUMAR LINHAS AEREAS             \n\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);
	
	deseja = desejaComprar();
	
	if(deseja == 'S'){
	qtdPassageiros = leValidaQtdPassageiros();
	qtdCliente = qtdPassageiros;	
	

	do{
	system("cls");	
	SetConsoleTextAttribute(hConsole, 14);
	printf("_______________________________________________\n\n");
	printf("             SALUMAR LINHAS AEREAS             \n\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	
	
	comando = leValidaOpcao();	
	
	i = menu(comando,&qtdPassageiros,valorPassagem);
	SetConsoleTextAttribute(hConsole, saved_attributes);
	}while(i != 1);
	}else
		return 0;
}
