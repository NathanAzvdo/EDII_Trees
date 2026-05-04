//#include <iostream>
#include "genBST.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//using namespace std;

int main(int argc, char** argv) {
	BST <int> arv; //instacia de forma estática um objeto árvore de dados inteiro
	arv.insert(5);
	arv.insert(4);
	arv.insert(8);
	arv.insert(7);
	arv.insert(10);
	arv.displayTree(); //desenha a árvore
	arv.inorder(); //travessias...
	cout<<endl;
	arv.preorder();
	cout<<endl;
	arv.postorder();
	cout<<endl;
	arv.findAndDeleteByCopying(5); //encontra e remove nó-dado com valor chave, se encontrar, pelo antecessor imediato
	arv.displayTree();
	system("pause");
	return 0;
}
