#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Tree struct
typedef struct Tree {
	char key[100];
	struct Tree* firstchild;
	struct Tree* sibling;
}Tree;

// create new node
Tree* new_node(char key[]) {
	Tree* temp = (Tree*)malloc(sizeof(Tree));
	strcpy(temp->key, key);
	temp->firstchild = NULL;
	temp->sibling = NULL;

	return temp;
}

// find null node
Tree* find_node(Tree* root, char key[]) {
	if (root == NULL) {
		return NULL;
	}

	if (strcmp(root->key, key) == 0) {
		return root;
	}

	Tree* foundNode = find_node(root->firstchild, key);
	if (foundNode) {
		return foundNode;
	}

	return find_node(root->sibling, key);
}

// create child node of parent node
void add_node(Tree** root, char key[], char child_key[]) {
	if (*root == NULL) {
		*root = new_node(key);
	}
	
	// if child_key already exist
	if (find_node(*root, child_key)) {
		return;
	}


	Tree* parent = find_node(*root, key);
	if (parent != NULL) {
		if (parent->firstchild == NULL) {
			parent->firstchild = new_node(child_key);
		}
		else {
			Tree* tmp = parent->firstchild;
			while (tmp->sibling != NULL) {
				tmp = tmp->sibling;
			}
			tmp->sibling = new_node(child_key);
		}
	}
}

// convert general tree to binary tree
// firstchild and sibling are each converted to left and right
void generalToBinary(Tree* root) {
	if (root == NULL) {
		return;
	}

	if (root->firstchild == NULL) {
		return;
	}
	if (root->firstchild->sibling && root->firstchild->firstchild == NULL) {
		root->firstchild->firstchild = root->firstchild->sibling;
		root->firstchild->sibling = NULL;
	}
	
	generalToBinary(root->firstchild);
	generalToBinary(root->sibling);
	
}

// print by preorder traversal
void preorderTraversal(Tree* root) {
	if (root != NULL) {
		printf("%s ", root->key);
		preorderTraversal(root->firstchild);
		preorderTraversal(root->sibling);
	}
}

void print_result(Tree *root) {
	generalToBinary(root);
	preorderTraversal(root);
}

 
int main() {
	Tree* root_1 = NULL; // Tree 1
	add_node(&root_1, "100", "200");
	add_node(&root_1, "100", "75");
	add_node(&root_1, "100", "300");
	add_node(&root_1, "75", "25");
	add_node(&root_1, "75", "50");
	add_node(&root_1, "75", "30");
	add_node(&root_1, "75", "150");
	add_node(&root_1, "30", "120");
	add_node(&root_1, "30", "55");
	

	Tree* root_2 = NULL; // Tree 2
	add_node(&root_2, "person", "doctor");
	add_node(&root_2, "person", "soldier");
	add_node(&root_2, "person", "engineer");
	add_node(&root_2, "doctor", "surgeon");
	add_node(&root_2, "doctor", "internist");
	add_node(&root_2, "engineer", "HW engineer");
	add_node(&root_2, "engineer", "SW engineer");
	add_node(&root_2, "SW engineer", "designer");
	add_node(&root_2, "SW engineer", "developer");
	add_node(&root_2, "SW engineer", "tester");

	print_result(root_1);
	printf("\n");
	print_result(root_2);
	

	
	
}