#include <stdio.h>
#include <time.h>

#define JOGADOR 'A'
#define PAREDE_H '-'
#define MESTRE 'X'

enum tipo_pokemon {fogo = 1, ar, terra, agua, planta};

typedef struct pokemon {
  char nome[50];
  int level;
  int tipo;
} pokemon_t;

char mapa[20][20];
char mapaAux[20][20];
int mestre1_x, mestre1_y, mestre2_x, mestre2_y, mestre3_x, mestre3_y, mestre4_x, mestre4_y, mestre5_x, mestre5_y;

void inicializaMapa() {
  int i, j;
  for (i=0; i<20; i++){
    for (j=0; j<20; j++){
      mapa[i][j] = ' ';
    }
  }
  
}

int inicializaMapaAuxiliar() {

  srand(time(NULL));

  int terreno;
  int i, j, pos_x, pos_y, terreno_key;;

  for (i=0; i<20; i++){
    for (j=0; j<20; j++){
      terreno_key = rand()%4 + 1; 
      switch (terreno_key) {
        case fogo:
          terreno = fogo;
        break;
        case ar:
          terreno = ar;
        break;
        case terra:
          terreno = terra;
        break;
        case agua:
          terreno = agua;
        break;
        case planta:
          terreno = planta;
        break;
      }
      mapaAux[i][j] = terreno;
    }
  }
  return mapaAux[i][j];
}

int sorteiaMestre() {

  srand(time(NULL));

  int linha1, coluna1, linha2, coluna2, linha3, coluna3, linha4, coluna4, linha5, coluna5;

  linha1 = rand()%17 + 1;
  coluna1 = rand()%18 + 1;
  mestre1_x = linha1;
  mestre1_y = coluna1;

  linha2 = rand()%17 + 1;
  coluna2 = rand()%18 + 1;
  mestre2_x = linha2;
  mestre2_y = coluna2;

  linha3 = rand()%17 + 1;
  coluna3 = rand()%18 + 1;
  mestre3_x = linha3;
  mestre3_y = coluna3;

  linha4 = rand()%17 + 1;
  coluna4 = rand()%18 + 1;
  mestre4_x = linha4;
  mestre4_y = coluna4;

  linha5 = rand()%17 + 1;
  coluna5 = rand()%18 + 1;
  mestre5_x = linha5;
  mestre5_y = coluna5;

  return mestre1_x;
  return mestre1_y;
  return mestre2_x;
  return mestre2_y;
  return mestre3_x;
  return mestre3_y;
  return mestre4_x;
  return mestre4_y;
  return mestre5_x;
  return mestre5_y;
}

void cadastroPoke(pokemon_t jogador[5], pokemon_t mestre[5]) {

  int i, j;

  printf("\e[H\e[2J");

  printf("\n-------\n");
  printf("JOGADOR\n");
  printf("-------\n");

  for(i=0; i<5; i++) {
    printf("\nEntre com o nome do Pokemon %d: ", i+1);
    scanf("%s", &jogador[i].nome);
    printf("Entre com o level do Pokemon %d: ", i+1);
    scanf("%d", &jogador[i].level);
    printf("Entre com o tipo Fogo(1) - Ar(2) - Terra(3) - Água(4) - Planta(5) do Pokemon %d: ", i+1);
    scanf("%d", &jogador[i].tipo);

    printf("\nNome: %s", jogador[i].nome);
    printf("\nLevel: %d", jogador[i].level);
    printf("\nTipo: ");
    switch (jogador[i].tipo) {
      case 1:
        printf("Fogo\n");
      break;
      case 2:
        printf("Ar\n");
      break;
      case 3:
        printf("Terra\n");
      break;
      case 4:
        printf("Água\n");
      break;
      case 5:
        printf("Planta\n");
      break;
    }
    printf("---------------\n");
  }

  printf("\e[H\e[2J");

  printf("\n-------\n");
  printf("MESTRES\n");
  printf("-------\n");

  for(j=0; j<5; j++) {
    printf("\nEntre com o nome do Pokemon %d: ", j+1);
    scanf("%s", &mestre[j].nome);
    printf("Entre com o level do Pokemon %d: ", j+1);
    scanf("%d", &mestre[j].level);
    printf("Entre com o tipo Fogo(1) - Ar(2) - Terra(3) - Água(4) - Planta(5) do Pokemon %d: ", j+1);
    scanf("%d", &mestre[j].tipo);
    printf("\nNome: %s", mestre[j].nome);
    printf("\nLevel: %d", mestre[j].level);
    printf("\nTipo: ");
    switch (mestre[j].tipo) {
      case 1:
        printf("Fogo\n");
      break;
      case 2:
        printf("Ar\n");
      break;
      case 3:
        printf("Terra\n");
      break;
      case 4:
        printf("Água\n");
      break;
      case 5:
        printf("Planta\n");
      break;
    }
    printf("---------------\n");
  }
}

void batalhaPoke(pokemon_t jogador[5], pokemon_t mestre[5], int **insignia, int **money, char mapaAux[20][20], int linha, int coluna){

  srand(time(NULL));

  printf("\e[H\e[2J");

  int i,j;
  int levelPoke, levelMestre;
  int numPoke = rand() % 4;
  int numMestre = rand() % 4;

  for(i = 0; i < 5; i++) {
    levelPoke = jogador[numPoke].level;
    levelMestre = mestre[numMestre].level;
  }

  printf("\n-------\n");
  printf("Batalha\n");
  printf("-------\n");

  printf("Jogador escolhe: %s\n", jogador[numPoke].nome);
  printf("Mestre escolhe: %s\n", mestre[numMestre].nome);

  if(mapaAux[linha][coluna] == jogador[numPoke].tipo){
      printf("\nTerreno do mesmo elemento de -%s- ! Jogador ganha mais 5!\n", jogador[numPoke].nome);
      levelPoke += 5;
    } else if (mapaAux[linha][coluna] == mestre[numMestre].tipo){
      printf("\nTerreno do mesmo elemento de -%s- ! Mestre ganha mais 5!\n", mestre[numMestre].nome);
      levelMestre += 5;
    } else {
      printf("\nTerreno não interfere!\n");
    }

  if(levelPoke > levelMestre){
    printf("\nVitória! Você ganhou uma insígnia!\n");
    **insignia += 1;
  } else if(levelMestre > levelPoke){
      printf("\nDerrota! Você perdeu 10 dinheiros!\n");
      **money -= 10;
  } else {
      printf("\nEmpate! Tente novamente!\n");
  }

  printf("\n-----------------\n");
  printf("Status do Jogador\n");
  printf("-----------------\n");

  printf("Insígnias: %d\nDinheiros: %d\n", **insignia, **money);
}

void imprimeMapa(int jogador_x, int jogador_y, int mestre1_x, int mestre1_y, int mestre2_x, int mestre2_y, int mestre3_x, int mestre3_y, int mestre4_x, int mestre4_y, int mestre5_x, int mestre5_y){

  int i, j;

  printf("\e[H\e[2J");

  for (i=0; i<20; i++){
    for (j=0; j<20; j++){
      if(i==0 || i==19) {
        mapa[i][j] = PAREDE_H;
        printf("%c", PAREDE_H);
      } else {
        printf(" ");
      } 
      if((j==mestre1_x && i==mestre1_y) || (j==mestre2_x && i==mestre2_y) || (j==mestre3_x && i==mestre3_y) || (j==mestre4_x && i==mestre4_y) || (j==mestre5_x && i==mestre5_y)) {
        mapa[i][j] = MESTRE;
        printf("%c", mapa[i][j]);
      } else if (j==jogador_x && i==jogador_y) {
          mapa[i][j] = JOGADOR;
          printf("%c", mapa[i][j]);
      }
    }
    printf("\n");
  }

  printf("\nW - cima S - baixo A - esquerda D - direita\n");
  

}

void comparaPosicao (int mestre1_x, int mestre1_y, int mestre2_x, int mestre2_y, int mestre3_x, int mestre3_y, int mestre4_x, int mestre4_y, int mestre5_x, int mestre5_y, int jogador_x, int jogador_y, pokemon_t jogador[5], pokemon_t mestre[5], int *insignia, int *dinheiro){

  if(mestre1_x == jogador_x && mestre1_y == jogador_y){

    batalhaPoke(jogador, mestre, &insignia, &dinheiro, mapaAux, mestre1_x, mestre1_y);
  }

  if(mestre2_x == jogador_x && mestre2_y == jogador_y){

    batalhaPoke(jogador, mestre, &insignia, &dinheiro, mapaAux, mestre2_x, mestre2_y);
  }

  if(mestre3_x == jogador_x && mestre3_y == jogador_y){

    batalhaPoke(jogador, mestre, &insignia, &dinheiro, mapaAux, mestre3_x, mestre3_y);
  }

  if(mestre4_x == jogador_x && mestre4_y == jogador_y){
    
    batalhaPoke(jogador, mestre, &insignia, &dinheiro, mapaAux, mestre4_x, mestre4_y);
  }

  if(mestre5_x == jogador_x && mestre5_y == jogador_y){
    
    batalhaPoke(jogador, mestre, &insignia, &dinheiro, mapaAux, mestre5_x, mestre5_y);
  }
}

int main(void) {
  srand(time(NULL));

  pokemon_t jogador[5];
  pokemon_t mestres[5];

  int insignia = 0, dinheiro = 100, aux, key, pos_x = 0, pos_y = 1;

  inicializaMapa();

  inicializaMapaAuxiliar();

  sorteiaMestre();

  cadastroPoke(jogador, mestres);

  imprimeMapa(pos_x, pos_y, mestre1_x, mestre1_y, mestre2_x, mestre2_y, mestre3_x, mestre3_y, mestre4_x, mestre4_y, mestre5_x, mestre5_y);
  

  while(dinheiro!=0) {
    key = getchar();

    if ((key == 'd' || key == 'D') && pos_x < 18) {
      pos_x++;

      imprimeMapa(pos_x, pos_y, mestre1_x, mestre1_y, mestre2_x, mestre2_y, mestre3_x, mestre3_y, mestre4_x, mestre4_y, mestre5_x, mestre5_y);

      comparaPosicao(mestre1_x, mestre1_y, mestre2_x, mestre2_y, mestre3_x, mestre3_y, mestre4_x, mestre4_y, mestre5_x, mestre5_y, pos_x, pos_y, jogador, mestres, &insignia, &dinheiro);
    }

    if ((key == 'a' || key == 'A') && pos_x > 0) {
      pos_x--;

      imprimeMapa(pos_x, pos_y, mestre1_x, mestre1_y, mestre2_x, mestre2_y, mestre3_x, mestre3_y, mestre4_x, mestre4_y, mestre5_x, mestre5_y);

      comparaPosicao(mestre1_x, mestre1_y, mestre2_x, mestre2_y, mestre3_x, mestre3_y, mestre4_x, mestre4_y, mestre5_x, mestre5_y, pos_x, pos_y, jogador, mestres, &insignia, &dinheiro);
    }

    if ((key == 'w' || key == 'W') && pos_y > 1) {
      pos_y--;

      imprimeMapa(pos_x, pos_y, mestre1_x, mestre1_y, mestre2_x, mestre2_y, mestre3_x, mestre3_y, mestre4_x, mestre4_y, mestre5_x, mestre5_y);

      comparaPosicao(mestre1_x, mestre1_y, mestre2_x, mestre2_y, mestre3_x, mestre3_y, mestre4_x, mestre4_y, mestre5_x, mestre5_y, pos_x, pos_y, jogador, mestres, &insignia, &dinheiro);
    }

    if ((key == 's' || key == 'S') && pos_y < 18) {
      pos_y++;

      imprimeMapa(pos_x, pos_y, mestre1_x, mestre1_y, mestre2_x, mestre2_y, mestre3_x, mestre3_y, mestre4_x, mestre4_y, mestre5_x, mestre5_y);

      comparaPosicao(mestre1_x, mestre1_y, mestre2_x, mestre2_y, mestre3_x, mestre3_y, mestre4_x, mestre4_y, mestre5_x, mestre5_y, pos_x, pos_y, jogador, mestres, &insignia, &dinheiro);
    }

  }

  printf("\e[H\e[2J");

  if(dinheiro == 0) {
    printf("\n------------\n");
    printf("Status Final\n");
    printf("------------\n");
    printf("Insígnias: %d\nDinheiros: %d\n\n", insignia, dinheiro);

    printf("Você Faliu :(\nGame Over! Encerrando jogo...");
  }

  return 0;
}