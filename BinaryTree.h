#ifndef __BinaryTree_h
#define __BinaryTree_h

class Node {
public:
    int value;
    Node* lft;
    Node* rgt;
    Node* parent;

    Node(int value, Node* parent = 0) {
        this->value = value;
	this->parent = parent;
        lft = rgt = 0;
    }
};

class BinaryTree {

public:

    BinaryTree() {
        root = 0;
        numberOfNodes = 0;
    }

    ~BinaryTree() {
        clear();
    }

    bool contains(int value) { 
        Node* t; 
        return findNode(value,t) != 0;
    }

    int size() const {
        return numberOfNodes;
    }

    bool isEmpty() const {
        return root == 0;
    }
    Node * getRoot()const{
    	return root;
    }

    void print();
    bool add(int);
    bool remove(int);
    Node* findNode(int, Node*&);
    int minValue(Node*);
    int maxValue(Node*);
    Node* minimum(Node*);
    Node* maximum(Node*);

    void preOrder(Node*);
    void inOrder(Node*);
    void posOrder(Node*);
    void iterativePreOrder(Node*);
    void iterativeInOrder(Node*);
    void iterativePosOrder(Node*);

    void visit(Node*);
    

    Node * suc(int);
    Node * pred(int);

    void height();
    void printNode(Node*);
    int height(Node*);

    void inLevel(Node*, int, int);
    void deleteLeaf(Node* &);
    void completa();
    void cheia();
    bool zig(Node*);
    void espelho(Node*);

private:
    Node* root;
    int numberOfNodes;

    void removeNode(int, Node*);
    void addNode(int, Node*);
    
    void clear();
    void deleteTree(Node*);

};

#endif
