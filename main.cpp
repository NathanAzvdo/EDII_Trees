#include "abb.h"
#include <conio.h>
using namespace std;

void mensagem_arvore_vazia(bool t){
    cout << "rvore est ";
    if(t)
        cout << "vazia\n";
    else
        cout << "no-vazia\n";
}

int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "Portuguese");
    cout<<"PROGRAMA RVORE BINRIA DE BUSCA OO\n";

    ArvBB tree; 
    
    mensagem_arvore_vazia(tree.vazia());
    
    cout << "Inserindo dados na rvore...\n";   
    tree.insere(5); 
    tree.insere(2); getch();
    tree.insere(3); 
    tree.insere(1); 
    tree.insere(9); 
    tree.insere(7); 
    tree.insere(8); 
    tree.insere(10); 
    
    tree.displayRoot();
    
    cout << "Mostrando estrutura de rvore:\n";
    tree.displayTree();
    mensagem_arvore_vazia(tree.vazia());

    cout << "Reiniciando a rvore!\n";
    tree.reiniciaTree();
    mensagem_arvore_vazia(tree.vazia());
    tree.displayTree();
    
    tree.displayRoot();
    system("pause");
    cout << "Inserindo dados na rvore...\n";   
    tree.insere(9); 
    tree.insere(1); 
    tree.insere(11); 
    tree.insere(2); 
    tree.insere(4); 
    tree.insere(9); 
    cout << "Mostrando estrutura de rvore:\n";
    tree.displayTree();
    mensagem_arvore_vazia(tree.vazia());
    
    cout << "Fim de programa!" << endl;
    tree.~ArvBB(); 
    cout << "rvore destruda (desalocada)\n";
    system("pause");

    return 0;
}