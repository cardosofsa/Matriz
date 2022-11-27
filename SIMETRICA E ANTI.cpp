#include <stdio.h>
#include <stdlib.h>
#include <locale>

int main(){
    int n, i, j, m[500][500], mt[500][500], valor, escolha, cond=1;
    char nome[10000];
    setlocale(LC_ALL, "portuguese");
    
    //colocamos em looping para poder repetir quantas vezes quiser, junto de informa��es b�sicas
    while (cond ==1) {
        printf("\nDigite seu nome: ");
        scanf("%s", nome);
        
        printf("Digite a ordem da sua matriz: ");
        scanf("%d", &n);
    
        printf("\nDigite as entradas da matriz:\n\n");
	    for (i=1; i<=n; i++){
            for (j=1; j<=n; j++){
                printf("a%d%d = ", i, j);
                scanf("%d", &m[i][j]);
                mt[j][i] = m[i][j];
                m[i][j] = (-1)*m[i][j];
            }
        }
        
        system("cls");
        printf("Qual a matriz desejada:\n [1] Matriz Antisim�trica\n [2] Matriz Sim�trica: \n Digite aqui: ");
        scanf("%d", &escolha);
        
        switch(escolha){
        
            // Verifica��o da Antisimetrica
            case 1:{
            	system("cls");
            	
                valor=1;
                
                for (i=1; i<=n && valor==1; i++){
                    for (j=1; j<=n && valor==1; j++){
                        if (m[i][j] != mt[i][j]){
                            valor = 0;          
                        }
                    }
                }
                
                if (valor == 0){
                    printf("\nA matriz mostrada por %s n�o � antisim�trica.\n\n", nome);
         	    }
         	    else {
                    printf("\nA matriz mostrada por %s � antisim�trica.\n\n", nome);
                }
                
                break;
            }
            
            // Verifica��o da Simetrica
            case 2:{
            	system("cls");
            	
                valor=1;
                
                for(i=1; i<=n && valor==1; i++){
                    for(j=1; j<=n && valor==1; j++){
                        if(m[i][j] == m[j][i]){
                            valor=0;
                            break;
                        }
                    }
                }
                
                if (valor == 0){
                    printf("\nA matriz mostrada por %s n�o � sim�trica.\n\n", nome);
         	    }
         	    else {
                    printf("\nA matriz mostrada por %s � sim�trica.\n\n", nome);
                }
                break;
            }
        }
    
        
        //mensagem para confirmar processo de looping
        printf("Digite [1] para verificar outra MATRIZ, ou qualquer outra tecla para encerrar o programa: ");
        scanf("%d", &cond);
        system("cls");
    }

    system("PAUSE");
}

