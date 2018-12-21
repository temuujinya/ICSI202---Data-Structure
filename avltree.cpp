#include <iostream>

using namespace std;

struct AVLNode {
	int data;
	int height;
	AVLNode* left;
	AVLNode* right;
};

//ihiin oloh
int max(int a, int b) {
	return (a > b)? a : b;
}

//rootiin undur
int height(AVLNode* root) {
	if (root == NULL)
		return 0;
	return root->height;
}

//balance bodoh left - right
int getBalance(AVLNode* root) {
	if (root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

// new node
AVLNode* CreateNewNode(int data) {
	AVLNode* newNode = new AVLNode();
	newNode->data = data;
	newNode->height = 1;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

//RR
AVLNode* rightRotate(AVLNode* root) {
	AVLNode* temp = root->left;
	AVLNode* temp2 = temp->right;

	temp->right = root;
	root->left = temp2;

	root->height =  max(height(root->left), height(root->right)) + 1;
	temp->height =  max(height(root->left), height(root->right)) + 1;

	return temp;
}

//LR
AVLNode* leftRotate(AVLNode* root) {
	AVLNode* temp = root->right;
	AVLNode* temp2 = temp->left;

	temp->left = root;
	root->right = temp2;

	root->height =  max(height(root->left), height(root->right)) + 1;
	temp->height = max(height(root->left), height(root->right)) + 1;

	return temp;
}

//Insert a Node BST
AVLNode* Insert(AVLNode* root, int data) {
	if (root == NULL)
		{return CreateNewNode(data);}

	if (data < root->data)
		root->left = Insert(root->left, data);
	else if (data > root->data)
		root->right = Insert(root->right, data);
	else
		return root;
	

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = getBalance(root);



	//LL
	if (balance > 1 && data < root->left->data)
		return rightRotate(root);
	

	//RR
	if (balance < -1 && data > root->right->data)
		return leftRotate(root);
	
	//LR
	if (balance > 1 && data > root->left->data) {
		root->left = leftRotate(root);
		return rightRotate(root);
	}

	//RL
	if (balance < -1 && data < root->right->data) {
		root->right = rightRotate(root);
		return leftRotate(root);
	}

	return root;

}

void inOrderPrint(AVLNode* root) {
	if (root != NULL) {
		inOrderPrint(root->left);
		cout << root->data << " ";
		inOrderPrint(root->right);
	}
}

AVLNode* search(AVLNode* root, int val)
{
    if (root == NULL || root->data == val)
       return root;

    if (root->data < val)
       return search(root->right, val);

    return search(root->left, val);
}

AVLNode* deleteNode(AVLNode* root, int val)
{

    if (root == NULL)
        return root;

    if ( val < root->data )
        root->left = deleteNode(root->left, val);

    else if( val > root->data )
        root->right = deleteNode(root->right, val);

    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            AVLNode *temp = root->left ? root->left :
                                             root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
             *root = *temp; 
            delete temp;
        }
        else
        {
            AVLNode* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
      return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

	//ll
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

	//lr
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


AVLNode* minValueNode(AVLNode* node)
{
    AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}


int main() {

	int inputs [] = {6,17,20,41,45,52,57,65,71,76,79,87,92,95,99};
	int size = *(&inputs + 1) - inputs;
	
	AVLNode* root;
	for (int i = 0; i < size; i++) {
		root = Insert(root,inputs[i]);
	}

	inOrderPrint(root);

	cout << endl;

	return 0;
}
