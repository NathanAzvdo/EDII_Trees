#include "genBST.h"


int main(int argc, char** argv) {
	BST <int> arv;
	arv.insert(5);
	arv.insert(4);
	arv.insert(8);
	arv.insert(7);
	arv.insert(10);
	arv.displayTree();
	arv.inorder();
	cout<<endl;
	arv.preorder();
	cout<<endl;
	arv.postorder();
	cout<<endl;
	arv.findAndDeleteByCopying(5);
	arv.displayTree();
	system("pause");
	return 0;
}
