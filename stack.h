#pragma once
template <class type>
class stack{
private:
	int top;
	int max_size;
	type*items;
public:
	// The default size of the stack is 10
	stack(){
		max_size = 10;
		items = new type[max_size];
		top = -1;
	}
	stack(int size){
		size <= 0? max_size = 10 : max_size = size;
		items = new type[max_size];
		top = -1;
	}
	int getSize(){
		return top + 1;
	}
	void push(type element){
		if(top < max_size - 1)
			items[++top] = element;
		else
			cout<<"Can't push, Stack is full"<<endl;
	}
	void pop(){
		if (isEmpty())
			cout<<"Can't pop, Stack is Empty"<<endl;
		else
			top--;
	}
	void pop(type&store){
		if (isEmpty())
			cout<<"Can't pop, Stack is Empty"<<endl;
		else
			store = items[top--];
	}
	void print(){
		if(isEmpty())
			cout<<"Empty stack\n";
		else{
			for (int i = top; i >= 0; i--) cout<<items[i]<<" ";
			cout<<"\n";	
		}
	}
	bool isEmpty(){
		return top == -1;
	}
	void getTop(type&store){
		if (isEmpty())
			cout<<"Can't get the top, Stack is Empty"<<endl;
		else
			store = items[top];
	}
	void getTopWithIndex(type&store, int index){
		if (isEmpty())
			cout<<"Can't get the top, Stack is Empty"<<endl;
		else if(top < index)
			cout<<"Can't get the top, index is invalid"<<endl;
		else
			store = items[top - index];
	}
};

