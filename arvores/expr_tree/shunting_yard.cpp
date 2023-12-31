
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

int eh_operador(char c){
    char operadores[] = {'(',')','*', '/', '+', '-'};
    int i;

    for(i = 0; i < 6; i++){
        if(c == operadores[i])
            return 1;
    }

    return 0;
}

//Retorna se o caractere c1 tem precedencia menor que o caractere c2
int menor_precedencia(char c1, char c2){
    if(c1 == '*' || c1 == '/'){
        return 0;
    }

    if(c1 == '+' || c1 == '-'){
        return (c2 == '*' || c2 == '/') ? 1 : 0;
    }
    return 0;
}

char* shunting_yard(const char* expression){
    char* saida, *numstring;
    int i, j;
    int k = 0;
    int nk = 0;
    int elen;
    char c, t;

    saida = new char[strlen(expression)*3]; //(char*) malloc(sizeof(char) * strlen(expression) * 3);
    numstring = new char[strlen(expression)*3]; //(char*) malloc(sizeof(char) * strlen(expression) * 3);

    //CSTACK *operadores;
    std::stack<char> operadores;

    //operadores =  CSTACK_Criar(10);

    elen = strlen(expression);

    for(i = 0; i < elen; i++){
        c = expression[i];

        if(isblank(c))
            continue;

        if(isdigit(c)){
            numstring[nk] = c;
            nk++;
        }   

        if(eh_operador(c)){

            if(nk > 0){
                for(j = 0; j < nk; j++)
                    saida[k+j] = numstring[j];
                saida[k+j] = ' ';
                k+=nk+1;
                nk = 0;
            }

            if(!operadores.empty()){
            //if(!CSTACK_Vazia(operadores)){
                //t = CSTACK_Topo(operadores);
                t = operadores.top();
                if(c == ')'){
                    //printf("pilha: ");
                    //CSTACK_Imprimir(operadores);
                    while(t != '('){
                        //t = CSTACK_Desempilhar(operadores);
                        t = operadores.top();
                        operadores.pop();
                        saida[k] = t;
                        saida[k+1] = ' ';
                        k+=2;
                        //t = CSTACK_Topo(operadores);
                        t = operadores.top();
                    }
                    operadores.pop();
                    //CSTACK_Desempilhar(operadores);
                    continue;
                }
                else{
                    if(c != '('){
                        while(menor_precedencia(c, t) && !operadores.empty()){
                            //t = CSTACK_Desempilhar(operadores);
                            t = operadores.top();
                            operadores.pop();
                            saida[k] = t;
                            saida[k+1] = ' ';
                            k+=2;
                            //t = CSTACK_Topo(operadores);
                            t = operadores.top();
                        }
                    }
                }
            }
            //CSTACK_Empilhar(operadores, c);
            operadores.push(c);
        }
    }

    if(nk > 0){
        for(j = 0; j < nk; j++)
            saida[k+j] = numstring[j];
        saida[k+j] = ' ';
        k+=nk+1;
        nk = 0;
    }    

    // while(!CSTACK_Vazia(operadores)){
    //     t = CSTACK_Desempilhar(operadores);
    while(!operadores.empty()){
        t = operadores.top();
        operadores.pop();
        saida[k] = t;
        saida[k+1] = ' ';
        k+=2;
    }
    saida[k] = '\0';

    //CSTACK_Destruir(operadores);
    //free(operadores);
    free(numstring);

    return saida;
}