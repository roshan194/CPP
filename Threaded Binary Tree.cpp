#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
        Node* left;
        Node* right;
        int leftthread;
        int rightThread;
        Node(int val)
        {
        	this->data = val;
		}
};
class DoubleThreadedBinaryTree
{
	private:
		Node* root;
	public:
	    DoubleThreadedBinaryTree()
		{
			root = new Node(INT_MAX);
			root->left = root->right = root;
            root->leftthread = 0;
            root->rightThread = 1;
		}
		void insert(int data)
		{
			 Node* newnode = new Node(data);
             if(root->left == root && root->right == root)
             {
             	newnode->left = root;
             	root->left = newnode;
                newnode->leftthread = 0;
                newnode->rightThread = 0;
                root->leftthread = 1;
                newnode->right = root;
                return;
			 }
			 else
			 {
			 	Node* current = root->left;
			 	while(true)
			 	{
			 		if(current->data > data)
			 		{
			 			if(current->leftthread == 0 )
			 			{
			 				newnode->left = current->left;
			 				current->left = newnode;
                            newnode->leftthread = current->leftthread;
                            newnode->rightThread = 0;
                            current->leftthread = 1;
                            newnode->right = current;
                            break;
						}
						else
						{
							current = current->left;
						}
					}
					else
					{
						if(current->rightThread == 0)
						{
							newnode->right = current->right;
							current->right = newnode;
                            newnode->rightThread = current->rightThread;
                            newnode->leftthread = 0;
                            current->rightThread=1;
                            newnode->left = current;
                            break;
						}
						else
						{
							current = current->right;
						}
					}
				}
			 }
		}
		Node* findnxtinorder(Node* current)
		{
			if(current->rightThread == 0)
			{
				 return current->right;
			}
			 current = current->right;
			 while (current->leftthread != 0)
			 {
			 	 current = current->left;
			 }
			  return current;
		}
		void inordertraversal()
		{
			 Node* current = root->left;
			 while(current->leftthread == 1)
			 {
			 	 current = current->left;
			 }
			 while(current != root)
			 {
			 	cout<<current->data<<" ";
			 	current = findnxtinorder(current);
			 }
			 cout<<"\n";
		}
		void preordertraversal()
		{
			Node* current = root->left;
			while(current != root)
			{
				cout<<current->data<<" ";
				if(current->left != root && current->leftthread != 0)
				{
					current= current->left;
				}
				else if(current->rightThread == 1)
				{
					 current = current->right;
				}
				else
				{
					 while (current->right != root && current->rightThread == 0)
					 {
					 	 current = current->right;
					 }
					  if(current->right == root)
					  {
					  	break;
					  }
					  else
					  {
					  	 current=current->right;
					  }
				}
			}
			 cout<<"\n";
		}
};
int main()
{
	 DoubleThreadedBinaryTree x;
	 x.insert(31);
     x.insert(14);
     x.insert(3);
     x.insert(9);
     x.insert(45);
     x.insert(29);
     x.insert(38);
     x.insert(85);
     x.inordertraversal();
     x.preordertraversal();
     return 0;
}
