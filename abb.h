#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stack> 

using namespace std;

struct noArv  
{
    int info;
    struct noArv* esq; 
    struct noArv* dir; 
};
typedef struct noArv NoArv; 

class ArvBB{
    private:
        NoArv* root; 
    
    public:
        ArvBB(); 
        ~ArvBB(); 
        void insere(int v);
        void displayTree();
        NoArv* getRoot();
        void reiniciaTree();
        bool vazia();
        void displayRoot();
        
    private:
        NoArv* abb_criavazia();
        NoArv* abb_cria (int c, NoArv* e, NoArv* d);
        NoArv* abb_insere(NoArv* a, int v);
        NoArv* abb_libera(NoArv* a);
        bool no_abb_vazio(NoArv* a);
};