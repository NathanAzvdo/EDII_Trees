#include "abb.h"

ArvBB::ArvBB(){
    this->root = abb_criavazia(); 
}

ArvBB::~ArvBB(){
    reiniciaTree(); 
}

void ArvBB::insere(int v){
    if (this->root != NULL) 
        abb_insere(this->root, v); 
    else
        this->root = abb_insere(this->root, v); 
}

void ArvBB::displayTree(){ 
    NoArv* a = this->root; 
    stack<NoArv*> globalStack; 
    globalStack.push(a);
    int nBlanks = 32;
    bool isRowEmpty = false;
    cout << "Viso encadeada de rvore: " << endl;
    
    while (isRowEmpty == false){
        stack<NoArv*> localStack; 
        isRowEmpty = true;
    
        for (int j=0; j<nBlanks; j++)
            cout << " ";
    
        while (globalStack.empty()== false){
            NoArv* temp = globalStack.top(); 
            globalStack.pop(); 
            
            if (temp != NULL){
                cout << temp->info;
                localStack.push(temp->esq);
                localStack.push(temp->dir);
                
                if ((temp->esq != NULL) || (temp->dir != NULL)){
                    isRowEmpty = false;
                }   
            }else{
                cout << "-";    
                localStack.push(NULL);
                localStack.push(NULL);  
            }
            int fim = nBlanks*2 - 1;
            for (int j=0; j<fim; j++)
                cout << " ";
        } 
        cout << endl;
        nBlanks = nBlanks / 2;
        while (localStack.empty() == false){
            globalStack.push(localStack.top()); 
            localStack.pop(); 
        }
    } 
    cout << endl;
}

NoArv* ArvBB::getRoot(){
    return this->root;  
}

void ArvBB::reiniciaTree(){
    this->root = abb_libera(this->root);
}

bool ArvBB::vazia(){
    return no_abb_vazio(this->root);
}

void ArvBB::displayRoot(){
    if (this->root != NULL) 
        cout << "Root -> info: " << this->root->info << endl;
    else
        cout << "rvore vazia! \n";
}

NoArv* ArvBB::abb_criavazia(){
    return NULL;
}

NoArv* ArvBB::abb_cria(int c, NoArv* sae, NoArv* sad){
    NoArv* p=(NoArv*)malloc(sizeof(NoArv));
    if(p==NULL){
        cout << "FALHA DE ALOCAO EM MEMRIA!\n";
        exit(1);
    } 
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

NoArv* ArvBB::abb_insere(NoArv* a, int v){
    if (a == NULL) 
        a = abb_cria (v, NULL, NULL);
    else if (v < a->info)
        a->esq = abb_insere(a->esq,v); 
    else 
        a->dir = abb_insere(a->dir,v); 
    return a;
}

NoArv* ArvBB::abb_libera(NoArv* a){
    if (!no_abb_vazio(a)){
        abb_libera(a->esq); 
        abb_libera(a->dir); 
        free(a); 
    }
    return NULL;
}

bool ArvBB::no_abb_vazio(NoArv* a){
    return a == NULL;
}