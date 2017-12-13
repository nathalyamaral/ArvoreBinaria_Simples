#ifndef __BinaryTree_h
#include "BinaryTree.h"
#endif

#include <stdio.h>
#include <stack>

int max(int a, int b) {
    return a > b ? a : b;
}

bool BinaryTree::add(int value)
{

    Node* parent = 0;
    Node* cur = findNode(value,parent);

    if(cur == 0)
    {	
        addNode(value,parent);
        return true;
    }
    return false;

}

void BinaryTree::addNode(int value, Node* parent) {

    if(parent != 0) 
    {
	Node* node = new Node(value, parent);
	if(parent->value > value)
              parent->lft = node;
        else
              parent->rgt = node;
    }
    else
    	      root = new Node(value,0);
    
    numberOfNodes++;
}


bool BinaryTree::remove(int value) {

    Node* parent = 0;

    Node* node = findNode(value,parent);

    if(node != 0)
    {
    	removeNode(value,node);
	return true;
    }
    return false;
}


void BinaryTree::removeNode(int value, Node* node) 
{

    // node é o nó que deve ser removido

    // caso onde node possui dois filhos 
    if (node->lft != 0 && node->rgt !=0 )
    {    
             // nesse caso, vamos fazer a remoção por cópia

            Node* tmp = node->rgt;
            Node* ant = node;

            // busca sucessor de node
            while(tmp->lft != 0) {
                ant = tmp;
                tmp = tmp->lft;
            }
            // nesse momento, tmp é o sucessor de node e vamos copiar o campo value de tmp para o campo value de node 

            node->value = tmp->value;             // caso haja outros campos no nó, todos deverão ser copiados
            // removeNode (tmp->value, tmp);
            node = tmp; 
    }

    
	if (node->parent == 0)
             root = node->rgt == 0? node->lft:node->rgt;
	           
        else 
        {
             Node *aux;
             if(node->parent->value > node->value)   // atualiza ponteiro esquerdo ou direito do nó pai de node             using namespace std;
             {
		    // node->parent->lft = node->rgt == 0? node->lft:node->rgt;  
                    aux = node->rgt == 0? node->lft:node->rgt;  
                    node->parent->lft = aux;
                    
             }
             else                   
             {       // node->parent->rgt = node->rgt == 0? node->lft:node->rgt;
                    aux = node->rgt == 0? node->lft:node->rgt;  
                    node->parent->rgt = aux;
       
             }            
             if (aux !=0) aux->parent = node->parent;        

        }
        delete node;
        numberOfNodes --;
   

}   



void BinaryTree::clear() {
    deleteTree(root);
    root = 0;
    numberOfNodes = 0;
}

void BinaryTree::print() {
    printNode(root);
}

void BinaryTree::deleteTree(Node* node) {
    if (node == 0)
            return;

    deleteTree(node->lft);
    deleteTree(node->rgt);
    delete node;
}

Node* BinaryTree::findNode(int value, Node*& parent) {
    Node* cur = root;

    parent = 0;

    while (cur != 0) {
        if (cur->value == value)
            return cur;

        parent = cur;
        cur = cur->value > value? cur->lft : cur->rgt;
    }

    return cur;
}

void BinaryTree::printNode(Node* node) {
    if (node == 0)
        return;

    if(node->parent) 
          printf("%d , pai->%d   ", node->value, node->parent->value);
     else 
            printf("%d \n", node->value);

    printNode(node->lft);
    printNode(node->rgt);
}



int BinaryTree::minValue(Node* node) {
    Node* cur = node;

    while(cur->lft != 0)
        cur = cur->lft;

    return cur->value;
}

int BinaryTree::maxValue(Node* node) {
    Node* cur = node;

    while(cur->rgt != 0)
        cur = cur->rgt;

    return cur->value;
}

Node* BinaryTree::minimum(Node* node) {
    Node* cur = node;

    while(cur->lft != 0)
        cur = cur->lft;

    return cur;
}

Node* BinaryTree::maximum(Node* node) {
    Node* cur = node;

    while(cur->rgt != 0)
        cur = cur->rgt;

    return cur;
}

void BinaryTree::height() {
    printf("O altura da árvore: %d\n", height(root));
}

int BinaryTree::height(Node* node) {
    if(node == 0)
        return 0;

    return 1 + max(height(node->lft), height(node->rgt));
}

void BinaryTree::preOrder(Node* node)
{using namespace std;
    if (node == 0)
        return;

    visit(node);
    preOrder(node->lft);
    preOrder(node->rgt);
}

void BinaryTree::inOrder(Node* node)
{
    if (node == 0)
        return;

    inOrder(node->lft);
    visit(node);
    inOrder(node->rgt);
}

void BinaryTree::posOrder(Node* node)
{
    if (node == 0)
        return;

    posOrder(node->lft);
    posOrder(node->rgt);
    visit(node);
}

void BinaryTree::visit(Node* node)
{
    printf("%d ", node->value);
}

void BinaryTree::iterativePreOrder(Node* node)
{

        std::stack<Node*> pilha;
        if (node != 0) {
             pilha.push(node);
             while (!pilha.empty()) {
                 node = pilha.top();
                 pilha.pop();
                 visit(node);
                 if (node->rgt != 0)
                      pilha.push(node->rgt);
                 if (node->lft  != 0) 
                        // filho da esquerda empilhado
                        // após o da direita
                      pilha.push(node->lft);
                        // para estar no topo da pilha;
             }
        }
}

void BinaryTree::iterativeInOrder(Node* node)
{
    std::stack<Node*> pilha;
    
    while (node != 0) {
        while(node != 0) {       // empilhar filho da direita (se houver)
          if (node->rgt != 0) // e o próprio nó quando for
              pilha.push(node->rgt); // para a esquerda;
          
          pilha.push(node);
          node = node->lft;
        }

      node = pilha.top();
      pilha.pop();   // pop em nó sem filho esquerdo
      while (!pilha.empty() && node->rgt == 0) { 
                                   // visita-lo e a todos os nós
         visit(node);                 // sem filho direito;
         node = pilha.top();
         pilha.pop();
      }
      visit(node);                  // visitar também o primeiro nó com
      if (!pilha.empty()){// um filho direito (se houver);  
        node = pilha.top();
        pilha.pop();
      }  
      else 
        node = 0;
    }

}

void BinaryTree::iterativePosOrder(Node* node)
{
    Node * q = node;
    std::stack<Node*> pilha;
    while (node != 0) {
        for ( ; node->lft != 0; node = node->lft)
            pilha.push(node);
        while (node != 0 && (node->rgt == 0 || node->rgt == q)) {
            visit(node);
            q = node;

            if (pilha.empty())
                 return;

            node = pilha.top();
            pilha.pop();
        }

        pilha.push(node);
        node = node->rgt;
    }
}

Node* BinaryTree::suc(int value) {

    Node* parent = 0;
    Node* node = findNode(value,parent);

	if(node != 0) {
		if(node->value == value) {
			if(node->rgt != 0) {
				return minimum(node->rgt);		
			}

			parent = node->parent;
			while(parent != 0 && parent->rgt == node) {
				node = parent;
				parent = parent->parent;
			}		
			
		}
	}
	return parent;
}

Node* BinaryTree::pred(int value) {
	Node* parent = 0;
    Node* node = findNode(value,parent);

	if(node != 0) {
		if(node->value == value) {
			if(node->lft != 0) {
				return maximum(node->lft);		
			}
			parent = node->parent;
			while(parent != 0 && parent->lft == node) {
				node = parent;
				parent = parent->parent;
			}
			
		}
	}
	return parent;

}
// BUSCA EM NIVEL   - EX 4
void BinaryTree::inLevel(Node* p, int level_a, int level_p)
{
	if(p!=0)
	{
		if(level_a == level_p)
			printf("%d", p->value);
		inLevel(p->lft, level_a+1, level_p);
		inLevel(p->rgt, level_a+1, level_p);
	}
}

// EX 5 - REMOVER NOS FOLHAS
void BinaryTree::deleteLeaf(Node* &p)
{
	if(p!=0)
	{
		if(p->lft== 0 && p->rgt == 0) {
			delete p;
      p = NULL;
		}
		else{
			deleteLeaf(p->lft);
			deleteLeaf(p->rgt);
		}
	}
}

// arvore é completa
void BinaryTree::completa()
{
	// calcula altura
	int h = height(getRoot());
	// busca nos com um filho do nivel != (altura-1) && altura

}


// arvore é cheia
void BinaryTree::cheia()
{
	// calcula altura
	// contar nos folhas -- so podem existir no nivel = altura
}


// arvore zigue zague
bool BinaryTree::zig(Node *p)
{
	if(p!=0)
	{
		if(p->lft != 0 && p->rgt !=0)
			return false;

		bool esq = zig(p->lft);
    bool dir = zig(p->rgt);
		return esq && dir;
	}
  return true;
}


// espelho - ex 10
void BinaryTree::espelho(Node* p)
{
	if(p!=0)
	{
		Node *lft, *rgt;

		lft = p->lft;
		rgt = p->rgt;
		p->lft = rgt;
		p->rgt = lft;
		espelho(p->lft);
    		espelho(p->rgt);
	}
}
