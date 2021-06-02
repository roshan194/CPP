#include<iostream>
using namespace std;
struct node{
	char data;
	node *left;
	node *right;
};

struct stacknode{
	node* data;
	stacknode* next;
};

class stack{
	stacknode* top;
	public:
		stack()
		{
			top=NULL;
		}
		node* peek()
		{
			return top->data;
		}
		int isempty()
		{
			if(top==NULL)
			 return 1;
			return 0; 
		}
		void push(node*a)
		{
			stacknode *p;
			p=new stacknode();
			p->data=a;
			p->next=top;
			top=p;
		}
		node* pop()
		{
			node* p;
			p=top->data;
			stacknode* q;
			q=top;
			top=top->next;
			delete(q);
			return p;
		}
};

node* create_post(char postfix[10])
{
	stack s;
	for(int i=0;postfix[i]!='\0';i++)
	{
		char token=postfix[i];
		if(isalnum(token))
		{
			node* p;
			p=new node;
			p->data=token;
			p->left=NULL;
			p->right=NULL;
			s.push(p);
		}
		else
		{
			node* p;
			p=new node;
			p->data=token;
			p->right=s.pop();
			p->left=s.pop();
			s.push(p);
		}
	}
	return s.pop();
}
node* create_pre(char prefix[10])
{
	stack s;
	int i;
	for(i=0;prefix[i]!='\0';i++)
	{
		char token=prefix[i];
		if(isalnum(token))
		{
			node* p;
			p=new node();
			p->data=token;
			p->left=NULL;
			p->right=NULL;
			s.push(p);
		}
		else
		{
			node* p;
			p=new node();
			p->data=token;
			p->left=s.pop();
			p->right=s.pop();
			s.push(p);
		}
	}
	return s.pop();
}

void inorder(node* root)
{
	if(root==NULL)
	 return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right); 
}
void preorder(node* root)
{
	if(root==NULL)
	 return;
	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right); 
}
void postorder(node* root)
{
	if(root==NULL)
	 return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<endl; 
}

void inorder_non_recursive(node* t)
{
	stack s;
	while(t!=NULL)
	{
		s.push(t);
		t=t->left;
	}
	while(s.isempty()!=1)
	{
		t=s.pop();
		cout<<t->data<<endl;
		t=t->right;
		while(t!=NULL)
		{
			s.push(t);
			t=t->left;
		}
	}
}
void preorder_non_recursive(node* t)
{
	stack s;
	while(t!=NULL)
	{
		cout<<t->data<<endl;
		s.push(t);
		t=t->left;
	}
	while(s.isempty()!=1)
	{
		t=s.pop();
		t=t->right;
		while(t!=NULL)
		{
			cout<<t->data<<endl;
			s.push(t);
			t=t->left;
		}
	}
}
void postorder_non_recursive(node* t)
{
	stack s,s1;
	node* t1;
	while(t!=NULL)
	{
		s.push(t);
		s1.push(NULL);
		t=t->left;
	}
	while(s.isempty()!=1)
	{
		t=s.pop();
		t1=s1.pop();
		if(t1==NULL)
		{
			s.push(t);
			s1.push((node* )1);
			t=t->right;
			while(t!=NULL)
			{
				s.push(t);
				s1.push(NULL);
				t=t->left;
			}
		}
		else
		{
			cout<<t->data<<endl;
		}
	}
}
int main()
{
	char postfix[10],prefix[10];
	node* r=NULL,r1;
	int x;
	int ch,choice;
	do
	{
		cout<<"1) Construct Tree from postfix/prefix expression 2)Inorder transversal 3)Preorder transversal 4)Postorder transversal 5)exit\n";
		cout<<"Enter your choice \n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"1)Postfix expression \n 2)Prefix expression \nenter choice\n";
				cin>>choice;
				if(choice==1)
				{
					cout<<"Enter postfix expression\n";
					cin>>postfix;
					r=create_post(postfix);
				}
				else
				{
					cout<<"Enter prefix expression\n";
					cin>>prefix;
					r=create_pre(prefix);
				}
				cout<<"tree constructed successfully \n";
				break;
			case 2:
			    cout<<"inorder transversal with recursion\n";
				inorder(r);
				cout<<"inorder transversal without recursion\n";
				inorder_non_recursive(r);
				break;
			case 3:
			    cout<<"preorder transversal with recursion\n";
				preorder(r);
				cout<<"preorder transversal without recursion\n";
				preorder_non_recursive(r);
				break;
			case 4:
			    cout<<"postorder transversal with recursion\n";
				postorder(r);
				cout<<"postorder transversal without recursion\n";
				postorder_non_recursive(r);
				break;				
		}
	}while(ch!=5);
}


