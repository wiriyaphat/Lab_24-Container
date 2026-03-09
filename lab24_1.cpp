#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

//Write List::remove() here
void List::remove(int idx){
	if(root == NULL) return;

    if(idx == 0){
        Node *temp = root; // temp = 0
        root = root->next; // 0 -> 1
        delete temp;
        size--;
        return;
    }

    Node *current = root; // ตัว current = ตัว root (idx 0)
    // ไป node ก่อนหน้าตัวที่จะลบ
    for(int i = 0; i < idx-1; i++){
        current = current->next; // 10 20 30 40 ต้องการลบ 30 -> current 10 กลายเป็น (current 20) 
    }

    Node *temp = current->next;   // temp = current 30
    current->next = temp->next;   // current next คือ 20->30 = temp next คือ 30->40 (30 กลายเป็น 40)
    delete temp;
    size--;
}