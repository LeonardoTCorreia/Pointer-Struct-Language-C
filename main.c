#include <stdio.h>

struct Alunos {
int matricula;
char nome [50];
float notas [3];
};

void receberDados(struct Alunos *aluno) {

  printf ("\nDigite a matrícula do aluno: ");
  scanf ("%d", &aluno->matricula);
  
  printf("Digite o nome do aluno: ");
  scanf("%s", aluno->nome);

  for(int i =0;i<3;i++){
    printf("Digite a nota da prova %d: ", i+1);
    scanf("%f", &aluno->notas[i]);
  }
}

void mostrarDados(struct Alunos aluno){
  printf("\nMatrícula: %d - Nome: %s - Notas: %.2f, %.2f, %.2f\n", aluno.matricula, aluno.nome, aluno.notas[0], aluno.notas[1], aluno.notas[2]);
}

float calcularMedia(struct Alunos aluno) {
    float soma = 0;
    for(int i = 0; i < 3; i++) {
        soma += aluno.notas[i];
    }
    return soma / 3.0;
}

int main(void) {

  struct Alunos aluno [5];

  //Dados dos 5 alunos
  for(int i = 0; i < 5; i++){
    printf("\nDados do aluno %d: ", i+1);
    receberDados(&aluno[i]);
  }
  
  float maiorNotaPrimeiraProva = aluno[0].notas[0];
  int indiceMaiorNotaPrimeiraProva = 0;
  for(int i = 1; i < 5; i++){
    if(aluno[i].notas[0] > maiorNotaPrimeiraProva){
      maiorNotaPrimeiraProva = aluno[i].notas[0];
      indiceMaiorNotaPrimeiraProva = i;
    }
  }

  printf("\nAluno com maior nota na primeira prova: \n");
  printf("\nMaior nota na Primeira Prova: %.2f\n", maiorNotaPrimeiraProva);
  mostrarDados(aluno[indiceMaiorNotaPrimeiraProva]);

 float maiorMedia = calcularMedia(aluno[0]);
  int indiceMaiorMedia = 0;
  for(int i = 1;i <5;i++){
    if(calcularMedia(aluno[i])>maiorMedia){
      maiorMedia =  calcularMedia(aluno[i]);
      indiceMaiorMedia = i;
    }
  }

  printf("\nAluno com a maior média geral: \n");
  printf("\nMédia: %.2f\n", maiorMedia);
  mostrarDados(aluno[indiceMaiorMedia]);


  float menorMedia = calcularMedia(aluno[0]);
  int indiceMenorMedia = 0;
  for(int i = 1;i < 5;i++){
    if(calcularMedia(aluno[i])<menorMedia){
      menorMedia = calcularMedia(aluno[i]);
      indiceMenorMedia = i;
    }
  }
  
  printf("\nAluno com a menor média geral: \n") ;
  printf("\nMédia: %.2f\n", menorMedia);
  mostrarDados(aluno[indiceMenorMedia]);

  printf("\nSituação dos alunos:\n\n");
    for(int i = 0;i < 5;i++) {
      float media = calcularMedia(aluno[i]);;
      printf("Aluno %s: %s\n", aluno[i].nome, media >= 6 ? "Aprovado" :       "Reprovado");
    }
  return 0;
}



