#include <iostream>
#include <stdlib.h>

using namespace std;

// Интерфейс
class Container
{
public:
    // Виртуальные методы, будут реализованы далее
    virtual void insert(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void remove(int value) = 0;
    // Это потом заменим на перегруженный оператор <<
    virtual void print() = 0;

    // Виртуальный деструктор
    virtual ~Container();
};


Container::~Container() { }

// Реализация интерфейса
typedef struct tree_element {
	int value;			// Element value
	struct tree_element* left;	// Pointer to left subtree
	struct tree_element* right;
	struct tree_element* parent;	// Pointer to right subtree
} tree_element;
// TODO

class SimpleTree: public Container
{
public:
    SimpleTree();
    ~SimpleTree();
    void insert(int value);
    bool exists(int value);
    void remove(int value);
    void print();

protected:
    tree_element* create(int i);
    tree_element* find(int i);
    tree_element* root;
};


SimpleTree::SimpleTree()
{
    this->root = NULL;
};

SimpleTree::~SimpleTree()
{

}

tree_element* SimpleTree::create(int value)
{
    tree_element* a = (tree_element*) malloc( sizeof(tree_element));
    a->value = value;
    a->left = NULL;
    a->right = NULL;
    a->parent = NULL;
    return a;
}

void SimpleTree::insert(int elem)
{
    tree_element* newTree = create(elem);
    if ((elem) < (this->root->value))
        {
        if ((this->root->left) != NULL)
            this->root->left = insert_into_tree(root -> left, elem);
        else
            this -> left = newTree;
            newTree -> parent = this;
            return this;
        }
    else
        {
        if ((root->right) != NULL)
            root->right = insert_into_tree(root->right, elem);
        else
            root -> right = elem;
            elem -> parent = root;
            return root;
        }
}

bool exists(int value)
{

}

void remove(int value)
{

}

void print()
{

}


int main()
{
    Container* c = new SimpleTree();

    for(int i = 1; i < 10; i++)
        c->insert(i*i);

    printf("List after creation:\n");
    c->print();

    if(c->exists(25))
        cout << "Search for value 25: found" << endl;

    if(!c->exists(111))
        cout << "Search for value 111: not found" << endl;

    c->remove(25);
    cout << "List after deletion of the element:" << endl;
    c->print();

    delete c;
    return 0;
}
