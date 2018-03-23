#include <stdio.h>
#include<stdlib.h>

// Struct to store tree element
typedef struct tree_element {
	int value;			// Element value
	struct tree_element* left;	// Pointer to left subtree
	struct tree_element* right;
	struct tree_element* parent;// Pointer to right subtree
	int h;
} tree_element;

// Create new element, set its value to 'i', return pointer to new element
tree_element* create_tree_element(int i){
    tree_element* a = (tree_element*) malloc( sizeof(tree_element));
    a->value = i;
    a->h = 0;
    a->left = NULL;
    a->right = NULL;
    a->parent = NULL;
    return a;
};

// Insert element 'elem' into tree 'root'
/*tree_element* insert_into_tree(tree_element* root, tree_element* elem)
{
    tree_element* a = root;
    if ((elem->value) < (root->value))
        {
            if ((root->left) != NULL)
                a = root->left;
            else
            {
                root->left = elem;
                return root;
            }
        }
    else
        {
            if ((root->right) != NULL)
                a = root->right;
            else
            {
                root->right = elem;
                return root;
            }
        }
    int k;
    k = 0;
    while ( k == 0 )
    {
        if ((elem->value) < (a->value))
        {
            if ((a->left) != NULL)
                a = a->left;
            else
            {
                a -> left = elem;
                return root;
            }
        }
        else
        {
            if ((a->right) != NULL)
                a = a->right;
            else
            {
                a -> right = elem;
                return root;
            }
        }
    }
}*/

tree_element* insert_into_tree(tree_element* root, tree_element* elem)
{
    if ((elem->value) < (root->value))
        {

        if ((root->left) != NULL)
            root->left = insert_into_tree(root -> left, elem);
            if ((root->right) != NULL)
                root->h = abs(root->right->h)-abs(root->left->h);
            else
                root->h = root->left->h-1
        else
            root->h -= 1
            root -> left = elem;
            elem -> parent = root;
            return root;
        }
    else
        {
        root->h += 1;
        if ((root->right) != NULL)
            root->right = insert_into_tree(root->right, elem);
        else
            root -> right = elem;
            elem -> parent = root;
            return root;
        }
}
// Print tree
void print_tree(tree_element* cur_element)
{
    if (cur_element->left != NULL)
        print_tree(cur_element->left);
    printf("%d ", cur_element->value);
    if (cur_element->right != NULL)
        print_tree(cur_element->right);
}
// Search for given value in the tree
// Returns pointer to found element and NULL otherwise
tree_element* search_by_value(tree_element* root, int value)
{
    if (value < root->value)
    {
        if (root->left != NULL)
            search_by_value(root->left, value);
        else
            return NULL;
    }
    else if (root->value == value)
        return root;
    else
    {
        if (root->right != NULL)
            search_by_value(root->right, value);
        else
            return NULL;
    }
}

// Deletes element from the tree
tree_element* delete_from_tree(tree_element* root, tree_element* elem)
{
    tree_element* a;
    tree_element* b;
    a = search_by_value(root, elem->value);
    a = b;
    a = a->parent;
    if ((a->value) < (b->value))
    {
        a->left = b -> left;
        b->left->parent=a;
        insert_into_tree(b->left, b->right);
        printf("lol\n");
        free(b);
    }
    else
    {
        a->right = b -> right;
        b->right->parent=a;
        printf("lol1\n");
        insert_into_tree(b->right, b->left);
        printf("lol2\n");
        free(b);
    }

}

tree_element* balance (tree_element* root)
{
    if ((abs(root->h) > 1)&&(abs(root->right->h) > 1))
        root = balance(root->right);
    else if ((abs(root->h) > 1)&&(abs(root->left->h) > 1))
        root = balance(root->left);
    else
    {
        tree_element* tree0 = root;
        tree_element* treeleft = tree0->left;
        tree_element* treeright = tree0->right;\

        if (root->h > 1)
        {
            treeright->parent = tree0->parent;
            tree0->parent = treeright;
            tree0->right = treeright -> left;
            treeright->left = tree0;
        }
        if (root->h < -1)
        {
            treeleft->parent = NULL;
            tree0->parent = treeleft;
            tree0->left = treeleft -> right;
            treeleft->right = tree0;
        }
    }
}

int main()
{
	int a[7] = {-3, -1, -5, 3, 1, 5, 6};
	int i;
	tree_element* cur_elem;

	tree_element* root = create_tree_element(0);
	for(i = 0; i < 7; i++)
	{
		tree_element* elem = create_tree_element(a[i]);
		root = insert_into_tree(root, elem);
	}

	printf("Tree after creation:\n");
	print_tree(root);
	printf(" \n");
	tree_element* elem;
	elem = search_by_value(root,6);
	delete_from_tree(root, elem);

	cur_elem = search_by_value(root, 3);
	if(cur_elem != NULL)
	{
		printf("Search for value 3: found\n");
	}

	cur_elem = search_by_value(root, 111);
	if(cur_elem == NULL)
	{
		printf("Search for value 111: not found\n");
	}

	return 0;
}
