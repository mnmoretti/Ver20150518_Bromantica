#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2

char si[]="si";

struct s_pizza {
    char nomePizza[20];
    char descrizione[50];
    char pomodoro[5];
    char mozzarella[5];
    char glutine[3];
};

struct s_pizza v[N];

void funzioneOrdinamento (struct s_pizza v[]); 

int main(int argc, char** argv) {
    
    int i;
    FILE *puntaFile;
    FILE *puntaFile2;
    int z;
    
    
    for(i = 0; i < N; i++) {
        printf("Nome pizza numero %d: ", i+1);
        scanf("%s", v[i].nomePizza);
        printf("Descrizione: ");
        scanf("%s", v[i].descrizione);
        printf("Quantita' di pomodoro espressa in grammi: ");
        scanf("%s", &(v[i].pomodoro));
        printf("Quantita' di mozzarella espressa in grammi: ");
        scanf("%s", v[i].mozzarella);
        printf("E' presente il glutine? si-no: ");
        scanf("%s", v[i].glutine);
    }
    
    funzioneOrdinamento(v);
    
    puntaFile = fopen("normale.csv", "w");
    
    puntaFile = fopen("senzaglutine.csv", "w");
    
    for(i=0;i<N;i++){       
    
    if((strcmp((v[i].glutine), si))=0){
         
    if(puntaFile != NULL) {
        fwrite(&v, sizeof(v), N, puntaFile);
        fclose(puntaFile);
    }
    }
    else 
        
         if(puntaFile != NULL) {
             fwrite(&v, sizeof(v), N, puntaFile2);
             fclose(puntaFile);
         }
    }
    
    return (EXIT_SUCCESS);
}

void funzioneOrdinamento (struct s_pizza v[]) {
    int i;
    int j;
    int Min;
    struct s_pizza temp;
  
    for(i = 0; i < N-1; i++) {
        Min = i;
        for(j = i + 1; j < N; j++) {
            if(strcmp(v[j].nomePizza, v[Min].nomePizza ) < 0) {
                Min = j;
            }
        }
        if(i != Min) {
            temp = v[i];
            v[i] = v[Min];
            v[Min] = temp;
        }
    }
}

