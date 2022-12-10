#include <stdio.h>

	#define clear printf("\e[1;1H\e[2J");
	#define predefinito printf("\x1b[0m");
	#define bianco printf("\x1b[47m");
	#define rosso printf("\x1b[41m");
	#define verde printf("\x1b[42m");
	
void porta(){
	bianco;
	printf("\n\t+-----------------+\n\t||");
	predefinito;
	printf(" 1           2 ");
	bianco;
	printf("||\n\t||");
	predefinito;
	printf("       4       ");
	bianco;
	printf("||");
	predefinito;
	printf("\n________");
	bianco;
	printf("||");
	predefinito;
	printf("_3___________5_");
	bianco;
	printf("||");
	predefinito;
	printf("________\n\n\t");
	predefinito;
	printf("         o");
}


int scelta_attacante(char nome_attaccante[]){
	int att=0;
	porta();
		do{
		printf("\n\n\t%s scelga dove tirare:\n\n\t>>", nome_attaccante);
		scanf("%d", &att);
		}while(att<1 || att>5 && printf("\n\n\tSi prega di selezionare un valore da 1 a 5"));
		return att;
}


int scelta_portiere(char nome_portiere[]){
	int por=0;
	porta();
		do{
		printf("\n\n\t%s scelga dove parare:\n\n\t>>", nome_portiere);
		scanf("%d", &por);
		}while(por<1 || por>5 && printf("\n\n\tSi prega di selezionare un valore da 1 a 5"));
		return por;
}


void controllo(int att, int por, char n_att[], char n_por []){
	porta();
	char qual;
	printf("\n\n\t%s ha tirato in %d e %s ha parato in %d", n_att, att, n_por, por);
	if(att==por){
			printf("\n\n\tNON E' GOAL!");
		}else if(att!=por){
			printf("\n\n\tE' GOAL!");
		}
}

void stampa_risultati(char vet[], char nome[], char vet2[], char nome2[]){
	printf("\n\n\t\t\t1       2       3       4       5");
	int e=0;
	
		printf("\n\n\t%s\t\t", nome);
		int i=0;
		for(i=0; i<5;i++){
			if(vet[i]=='v'){
				verde;
				printf("    ");
			}else if(vet[i]=='r'){
				rosso;
				printf("    ");
			}else{
				printf("    ");
			}
		
			predefinito;
			printf("    ");
		}
		
		printf("\n\n\t%s\t\t", nome2);
		for(i=0; i<5;i++){
			if(vet2[i]=='v'){
				verde;
				printf("    ");
			}else if(vet2[i]=='r'){
				rosso;
				printf("    ");
			}else{
				printf("    ");
			}
		
			predefinito;
			printf("    ");
		}
}



int main(){
	
	char bot[7]={"Bot642"};
	char qual, gioc1[7], gioc2[7];
	int num_gioc=0, ruolo1, att=0, por=0, i=0;
	char r1[5], r2[5];
	
	printf("\n\tCIAO, BENVENUTO IN \"CALCI DI RIGORE\"!\n\n\tQuesto gioco e' molto semplice: un giocatore decide dove tirare il pallone mentre l'altro\n\tdecide dove parare e viceversa. Ci saranno 5 tiri a testa. Buon divertimento!");
	
	printf("\n\n\n\tPremere invio per continuare...");
	scanf("%c", &qual);
	
	clear;

	do{	
		printf("\n\n\tIn quante persone si desidera giocare?\n\n\t\t1. singleplayer\n\t\t2. multiplayer\n\n\t>> ");
		scanf("%d", &num_gioc);
	}while(num_gioc!=1 && num_gioc!=2 && printf("\n\tSi prega di scegliere uno o due giocatori"));
	
	if(num_gioc==1){
		printf("\n\n\tInserire il prorpio nome (massimo 7 caratteri)\n\n\t\t>> ");
		getchar();
		gets(gioc1);
		getchar();
		
		for(i=0;i<7;i++){
			gioc2[i]=bot[i];
		}
		
		printf("\n\n\tIl tuo avversario si chiamera' \"%s\"", bot);
		sleep(3);
		
	}else if(num_gioc==2){
		printf("\n\n\tInserire il nome del giocatore 1 (massimo 7 caratteri)\n\n\t\t>> ");
		getchar();
		gets(gioc1);
		getch();
		
		printf("\n\n\tInserire il nome del giocatore 2 (massimo 7 caratteri)\n\n\t\t>> ");
		gets(gioc2);
	}
	
	clear;
	
	ruolo1=1;
	
	
	for(i=1; i<11; i++){
		
		att=0;
		por=0;
		
		printf("\n\n\tRIGORE %d\n\n", i);
		
		if(num_gioc==1){
			if(ruolo1==2){
				att=rand()%5+1;
				printf("\t%s sta scegliendo dove tirare...", bot);
				sleep(3);
			}else if(ruolo1==1){
				att=scelta_attacante(gioc1);
			}
		}else if(num_gioc==2){
			if(ruolo1==1){
				att=scelta_attacante(gioc1);
			}else if(ruolo1==2){
				att=scelta_attacante(gioc2);
			}
		}
		
		clear;
		printf("\n\n\tRIGORE %d\n\n", i);
		
		if(num_gioc==1){
			if(ruolo1==1){
				por=rand()%5+1;
				printf("\t%s sta scegliendo dove parare...", bot);
				sleep(3);
			}else if(ruolo1==2){
				por=scelta_portiere(gioc1);
			}
		}else if(num_gioc==2){
			if(ruolo1==2){
				por=scelta_portiere(gioc1);
			}else if(ruolo1==1){
				por=scelta_portiere(gioc2);
			}
		}


		clear;
		printf("\n\n\tRIGORE %d\n\n", i);
		
		if(i%2==1){
			if(att!=por){
				r1[(i/2)-1/2]='v';
			}else{
				r1[(i/2)-1/2]='r';
			}
		}if(i%2==0){
			if(att!=por){
				r2[(i/2)-1]='v';
			}else{
				r2[(i/2)-1]='r';
			}
		}
		
		if(ruolo1==1){
			controllo(att, por, gioc1, gioc2);
		}else if(ruolo1==2){
			controllo(att, por, gioc2, gioc1);
		}
		
		stampa_risultati(r1, gioc1, r2, gioc2);
		printf("\n\n");
		
		printf("\n\n\n\tPremere invio per continuare...");
		getchar();
		scanf("%c", &qual);
		clear;
		
		if(ruolo1==1){
			ruolo1=2;
		}else if(ruolo1==2){
			ruolo1=1;
		}
	}
	
	clear;
	
	printf("\n\n\tIL RISULTATO FINALE E'");
	stampa_risultati(r1, gioc1, r2, gioc2);
	printf("\n\n");
	
	int g1=0, g2=0;
	
	for(i=0; i<5;i++){
		if(r1[i]=='v'){
			g1++;
		}
	}
	
	for(i=0; i<5;i++){
		if(r2[i]=='v'){
			g2++;
		}
	}
	
	if(g1>g2){
		printf("\n\n\tHa vinto %s con %d goal\n\n", gioc1, g1);
	}if(g1<g2){
		printf("\n\n\tHa vinto %s con %d goal\n\n", gioc2, g2);
	}if(g1==g2){
		printf("\n\n\t%s e %s hanno pareggiato\n\n", gioc1, gioc2);
	}
	sleep(6);
	
	return 0;
}
