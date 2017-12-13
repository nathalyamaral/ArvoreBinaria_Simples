#include "BinaryTree.h"

#include <stdio.h>
#include <stack>

int main()
{
	BinaryTree* bt = new BinaryTree();

    // Insere elementos na árvore
	bt->add(50);
	bt->add(25);
	bt->add(75);
	bt->add(12);
	bt->add(37);
	bt->add(0);

    // Mostra resultado da aplicação dos percursos
	printf("Percurso em pré-ordem(Recursivo): \n");
	bt->preOrder(bt->getRoot());
	printf("\nPercurso em pré-ordem(Iterativo): \n");
	bt->iterativePreOrder(bt->getRoot());
	printf("\nPercurso em in-ordem(Recursivo): \n");
	bt->inOrder(bt->getRoot());
	printf("\nPercurso em in-ordem(Iterativo): \n");
	bt->iterativeInOrder(bt->getRoot());
	printf("\nPercurso em pós-ordem(Recursivo): \n");
	bt->posOrder(bt->getRoot());
	printf("\nPercurso em pós-ordem(Iterativo): \n");
	bt->iterativePosOrder(bt->getRoot());

    // Mostra a altura da árvore
    printf("\n\nAltura = %d", bt->height(bt->getRoot()));

    // Remove alguns nós, como exemplo
    if (bt->remove(50))
        printf("\n Remoção feita com sucesso!");

    if (bt->remove(12))
        printf("\n Remoção feita com sucesso!");

    printf("\n");

    // O destrutor da classe será chamado
	delete bt;

	return 0;
}
