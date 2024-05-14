#pragma once
template <class type>
class linkedList{
private:
	struct Node{
		type item;
		Node*next;
	};
	Node*head;
	Node*tail;
	int size;
public:
	linkedList(){
		head = tail = NULL;
		size = 0;
	}
	bool isEmpty(){
		return size == 0;
	}
	int getSize(){
		return size;
	}
	void print(){
		if(isEmpty()) 
			cout<<"Empty linkedList\n";
		else{
		Node*current = head;
		while(current != NULL){
			cout<<current->item<<"  ";
			current = current->next;
		}
		cout<<endl;
		}	
	}
	void insertFirst(type value){
		Node*newNode = new Node();
		newNode->item = value;
		if(isEmpty()){
			head = tail = newNode;
			newNode->next = NULL;
		}else{
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
	void insertLast(type value){
		Node*newNode = new Node();
		newNode->item = value;
		newNode->next = NULL;
		if(isEmpty()){
			head = tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	void insertWithIndex(type value, int index){
		Node*newNode = new Node();
		newNode->item = value;
		if(index >= 0 && index <= size){
			if(index == 0) insertFirst(value);
			else if(index == size) insertLast(value);
			else{
				Node*current = head;
				for(int i = 1; i < index; i++)
					current = current->next;
				newNode->next = current->next;
				current->next = newNode;
				size++;
			}
		}else{
			cout<<"Can't insert, Index out of range\n";
		}
	}
	void removeFirst(){
		if(isEmpty())
			cout<<"Can't delete from empty linkedList\n";
		else{
			if(size == 1){
				delete head;
				head = tail = NULL;
			}else{
				Node*current = head;
				head = head->next;
				delete current;
			}
			size--;
		}
	}
	void removeFirst(type&store){
		if(isEmpty())
			cout<<"Can't delete from empty linkedList\n";
		else{
			type returned;
			if(size == 1){
				returned = head->item;
				delete head;
				head = tail = NULL;
			}else{
				Node*current = head;
				head = head->next;
				returned = current->item;
				delete current;
			}
			size--;
			store = returned;
		}
	}
	void removeLast(){
		if(isEmpty())
			cout<<"Can't remove from empty linkedList\n";
		else{
			if(size == 1){
				delete head;
				head = tail = NULL;
			}else{
				Node*current = head;
				while(current->next->next != NULL)
					current = current->next;
				tail = current;
				delete current->next;
				tail->next = NULL;
			}
			size--;
		}
	}
	void removeLast(type&store){
		if(isEmpty())
			cout<<"Can't remove from empty linkedList\n";
		else{
			type returned;
			if(size == 1){
				returned = head->item;
				delete head;
				head = tail = NULL;
			}else{
				Node*current = head;
				while(current->next->next != NULL)
					current = current->next;
				tail = current;
				returned = current->next->item;
				delete current->next;
				tail->next = NULL;
			}
			size--;
			store = returned;
		}
	}
	void removeWithIndex(int index){
		if(isEmpty())
			cout<<"Can't remove from empty linkedList\n";
		else if(index >= 0 && index < size){
			if(index == 0) removeFirst();
			else if(index == size - 1) removeLast();
			else{
				Node*current = head;
				for(int i = 1; i < index; i++)
					current = current->next;
				Node*removed = current->next;
				current->next = current->next->next;
				delete removed;
				size--;
			}
		}else
			cout<<"Can't remove, Index out of range\n";
	}
	void removeWithIndex(int index, type&store){
		if(isEmpty()){
			cout<<"Can't remove from empty linkedList\n";
		}else if(index >= 0 && index < size){
			type returned;
			if(index == 0) removeFirst(returned);
			else if(index == size - 1) removeLast(returned);
			else{
				Node*current = head;
				for(int i = 1; i < index; i++)
					current = current->next;
				Node*removed = current->next;
				current->next = current->next->next;
				returned = removed->item;
				delete removed;
				size--;
			}
			store = returned;
		}else
			cout<<"Can't remove, Index out of range\n";
	}
	void getWithIndex(int index, type&store){
		if(isEmpty())
			cout<<"LinkedList is empty\n";
		else if(index >= 0 && index < size){
			Node*current = head;
			for(int i = 0; i < index; i++)
				current = current->next;
			store = current->item;
		}else
			cout<<"Can't find, Index out of range\n";
		
	}
};

