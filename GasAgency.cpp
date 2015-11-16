#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define print(c,num) for(int i=0 ; i<num ; i++) printf("%c",c)
#define ADMIN_UNAME "admin"
#define ADMIN_PASS  "admin"
using namespace std ;

int a_id = 1 ;

class GasAgency{
	public :
		string connection ;
		int customer;
		static int num;

};


int GasAgency::num = 1;

//INHERITANCE 
class HP : public GasAgency{
	public :
		void thanks_notice()
		{
			cout<<"WELCOME ! THANKS FOR CHOOSING HP !\n";
			cout<<"YOUR BOOKING IS CONFIRMED WITH NUMBER : "<<connection<<endl;
	
		}
};

class Indane : public GasAgency{
	public :
		void thanks_notice()
		{
			cout<<"WELCOME ! THANKS FOR CHOOSING Indane !\n";
			cout<<"YOUR BOOKING IS CONFIRMED WITH NUMBER : "<<connection<<endl;
	
		}
};


class Bharat : public GasAgency{
	public :
		void thanks_notice()
		{
			cout<<"WELCOME ! THANKS FOR CHOOSING Bharat !\n";
			cout<<"YOUR BOOKING IS CONFIRMED WITH NUMBER : "<<connection<<endl;
		}
};


class Account {
	public :
	int account_number ;
	int cust_id ;
	
	Account(int val,int i) {
		account_number = val;
		cust_id = i;
	}
};


class Customer{
	public :
		string name      ;
		string address   ;
		string telephone ;
		string password  ;
		int cust_id ;
};


class Booking{
	
	public :
		string connection_number ;
		string agent ;
		Customer c;
};

Booking current_bookings[10] ;
int count;
// Node for customer

struct c_node{
	
	Customer customer ;
	struct c_node * left ;
	struct c_node * right ;
	c_node(Customer  c) : left(NULL) , right(NULL) , customer(c) {}

};

// node for Account

struct node{
	Account account ;
	struct node * left ;
	struct node * right ;
	int height ;
	node(Account  acc) : left(NULL) , right(NULL) ,height(1) , account(acc) {}
};


struct node * root = NULL    ;
struct c_node * root1 = NULL ;


struct c_node * insert(struct c_node * t, Customer c)
{
	if(t==NULL)
	{
		t = new c_node(c);
		return t ;
	}
	if(c.name > t->customer.name)
		t->right = insert(t->right , c);
	else if(c.name <= t->customer.name)
		t -> left = insert(t->left, c);
	return t;
}

// OVERLOADED FUNCTIONS


struct c_node * search(struct c_node * root , int cid)
{
	if(root == NULL)
		return NULL ;
	
	if(root -> customer.cust_id == cid)
		return root ;
	struct c_node * l = search(root->left , cid) ;
	struct c_node * r =  search(root->right , cid) ;

	return (l!=NULL) ? l : r ;
}

struct c_node * search(struct c_node * root , string s)
{
	if(root == NULL)
		return NULL ;
	if(root -> customer.name == s)
		return root ;
	if(root->customer.name < s)
		return search(root->right,s);
	else
		return search(root->left,s);
}



void inorder(struct c_node * root)
{
	if(root)
	{
		inorder(root->left) ;
		
		cout<<root->customer.cust_id<<" "<<root->customer.name <<" "<<root->customer.address<<" "<<root->customer.telephone<<endl;
		
		inorder(root->right) ;
	}
}



struct c_node * minValueNode(struct c_node* node)
{
    struct c_node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct c_node* deleteNode(struct c_node* root, string key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->customer.name)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->customer.name)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct c_node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct c_node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct c_node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->customer.name = temp->customer.name;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->customer.name);
    }
    return root;
}

int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
struct node* insert(struct node* t,Account key)
{
    /* 1.  Perform the normal BST rotation */
    if (t == NULL){
 		 t = new node(key);
		 return t;
	}
    if (key.account_number < t->account.account_number)
        t->left  = insert(t->left, key);
    else
        t->right = insert(t->right, key);
 
    /* 2. Update height of this ancestor node */
    t->height = max(height(t->left), height(t->right)) + 1;
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(t);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key.account_number < t->left->account.account_number)
        return rightRotate(t);
 
    // Right Right Case
    if (balance < -1 && key.account_number > t->right->account.account_number)
        return leftRotate(t);
 
    // Left Right Case
    if (balance > 1 && key.account_number > t->left->account.account_number)
    {
        t->left =  leftRotate(t->left);
        return rightRotate(t);
    }
 
    // Right Left Case
    if (balance < -1 && key.account_number < t->right->account.account_number)
    {
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }
 
    /* return the (unchanged) node pointer */
    return t;
}




void admin_functions()
{
	cout<<endl;
	print('*',50);
	print('\n',1);
	print(' ',20);
	cout<<"ADMIN\n";
	
	
	bool login = true ;
	do{
	print('-',50);
	print('\n',1);
	print(' ',20);
	cout<<"1. Add Customer Details\n";
	print(' ',20 );
	cout<<"2. Update Customer Details\n";
	print(' ',20) ;
	cout<<"3. Delete Customer Details\n";
	print(' ',20);
	cout<<"4. View Customer Details\n";
	print(' ',20);
	cout<<"5. Logout \n";
	


	int n ; cin>>n ;
	switch(n)
	{
		case 1 : {
				string name , address , phone ;
			Customer c ;
		
			cout<<" Name   : ";
			cin>>c.name ;
			cout<<" Address: ";
			cin>>c.address ;
			cout<<" Phone  : ";
			cin>>c.telephone;
			
			cout<<" Passwrd " ;
			cin>>c.password ;
			c.cust_id = ++a_id;
			root1 = insert(root1,c);
			
			cout<<"\nADDED\n"<<endl;
			break;
		}
		case 2 :{
				string name , address , phone ;
			cout<<"Name of the Customer : "; 
			cin>>name;
			struct c_node * n = search(root1,name);
			if(n==NULL)
			{
				cout<<"\n NO such customer "<<endl;
				break;
			}
			else{
				cout<<"\n New name    : "; cin>>n->customer.name ;
				cout<<"\n New Address : "; cin>>n->customer.address ;
				cout<<"\n New Phone   : "; cin>>n->customer.telephone ;
				
				string name , address , phone;
			}
			cout<<"\nUPDATED\n";
			break;
		}
		case 3:{
			
		
			string name;
			cout<<"Name of the Customer : "; 
			cin>>name;
			root1 = deleteNode(root1,name);
			
			
			cout<<"\nDELETED\n";
			break;
		}
		case 4:{
			inorder(root1);
			break;
		}
		case 5:{
			login = false;
			break;
		}
	}
}while(login==true);
	
}


string to_string(int num)
{
	string s ;
	while(num > 0)
	{
		s =  ((char)((num%10) + '0')) +  s;
		num /= 10; 
	}
	return s;
}


void customer_functions(Customer c)
{
	cout<<c.name<<endl;
	
	
	bool login = true ;
	do{
	print('-',50);
	print('\n',1);
	print(' ',20);
	cout<<"1. Register new  Account \n";
	print(' ',20 );
	cout<<"2. Booking \n";
	print(' ',20) ;
	cout<<"3. View My Booking Details\n";
	print(' ',20);
	cout<<"4. Logout \n";
	
	int n ; cin>>n ;
	switch(n)
	{
		case 1 : 
		{
				 cout<<"NEW ACCOUNT FOR "<<c.name <<endl;
				 int acc_no ; cout<<"ACCOUNT NUMBER "<<endl;
				 cin>>acc_no ;
				 Account a (acc_no , c.cust_id) ;
				 root = insert(root , a);
				 
				 cout<<"NEW ACCOUNT CREATED"<<endl;
				 break;
		}
		case 2 :{
			if(count == 10)
				{
					cout<<"Server error\n" ;
					break;
				}
			cout<<"BOOKING .. "<<endl;
			cout<<"1.HP\n2.Indane\n3.Bharat\n?";
			int ch ; cin>>ch;
			switch(ch)
			{
				case 1:{
					
					HP hp;
					hp.connection = "251-" + to_string(hp.num);
					
					hp.thanks_notice() ;
					
					current_bookings[count].connection_number = hp.connection ;
					current_bookings[count].agent = "HP" ;
					current_bookings[count].c = c;
					
					count++;
					break;
				}
				case 2:{
					Indane in;
					
					in.connection = "368-" + to_string(in.num);
					in.thanks_notice() ;
					
					current_bookings[count].connection_number = in.connection ;
					current_bookings[count].agent = "INDANE" ;
					current_bookings[count].c = c;
					
					count++;
					break;
				}
				case 3:{
					Bharat b;
					
					b.connection = "459-" + to_string(b.num);
					
					b.thanks_notice() ;
					
					current_bookings[count].connection_number = b.connection ;
					current_bookings[count].agent = "BHARAT GAS" ;
					current_bookings[count].c = c;
					
					count++;
					break;
				}
			}
			GasAgency::num++;
			break;
		} 
		case 3:{
			
			cout<<"MY BOOKINGS "<<endl ;
			
			for(int i=0 ; i<count ; i++)
			{
				if(current_bookings[i].c.cust_id ==  c.cust_id)
				{
					cout<<" AGENT "<<current_bookings[i].agent<<endl;
					cout<<" Connection_Number "<<current_bookings[i].connection_number<<endl;
				}
			}
			break;
		}
		case 4:{
			login = false ;
			break;
		}
				 
	}
}while(login==true);
}


int main()
{
	bool run = true;
	do{
	//GAS AGENCY
	print('*',50);
	cout<<endl<<"\n";
	print(' ',20);
	cout<<"1. Admin"<<endl;
	print(' ',20);
	cout<<"2. Customer"<<endl;
	print(' ',20);
	cout<<"3. Exit"<<endl;
	print(' ',20);
	cout<<"Your Choice : ";
	int n ; cin>>n;
	string u_name , pass ;
	switch(n)
	{
		
		case 1:
			
			cout<<"\nEnter admin username : ";
			cin>>u_name ;
			cout<<"Enter password : ";
			cin>>pass   ;
			
			if(u_name==ADMIN_UNAME && pass == ADMIN_PASS)
			
				admin_functions();
			else
			{
				cout<<"\nInvalid! .."<<endl;
			}
			break;
		case 	2:{
			int pid ;
			cout<<"\nEnter ID : ";
			cin>>pid ;
			cout<<"Enter password : ";
			cin>>pass   ;
			
			//search
			struct c_node * n   = search(root1 , pid) ;
			if(n==NULL || n->customer.password != pass)
				cout<<"Error"<<endl;
			else 
				customer_functions(n->customer);
				
			break;
		}case 3:
			
			run = false;
			break;
}}while(run==true);
}
