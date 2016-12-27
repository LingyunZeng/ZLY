#include <iostream>

using namespace std;

struct Node{
	int order;
	Node* next;
};

class Observer{
public:
	Observer(){ first = new Node(); first->order = 1; first->next = NULL; }
	void Add(int);
	void Remove(int);
	void Notify(int);
private:
	Node *first;
};

class Subject{
public:
	Subject(){ data = 0; number = 0; }
	void Add(int n);
	void Remove(int i){ ConcreteObserver->Remove(i); number--; }
	void Updata(int d){ data = d; ConcreteObserver->Notify(d); }
private:
	int data;
	int number;
	Observer *ConcreteObserver;
};

void Observer::Add(int n){
	Node* newNode = new Node();
	newNode->order = n;
	newNode->next = NULL;
	Node* current = first;
	while (current->next != NULL){
		current = current->next;
	}
	current->next = newNode;
	cout << "Observer" << n << " has been added successfully." << endl;
}

void Observer::Remove(int i){
	Node* current = first;
	Node* del = NULL;
	if (current->order == i){
		del = first;
		first = first->next;
		delete del;
		cout << "Observer" << i << " has been removed successfully." << endl;
	}
	else{
		while (1){
			if (current->next == NULL && current->order != i){
				cout << "Fail to remove Observer" << i << "." << endl;
				break;
			}
			if (current->next->order == i){
				del = current->next;
				current->next = del->next;
				delete del;
				cout << "Observer" << i << " has been removed successfully." << endl;
				break;
			}
			current = current->next;
		}
	}
}

void Observer::Notify(int d){
	Node* current = first;
	while (current != NULL){
		cout << "Observer" << current->order << " has been notified, the new data is " << d <<"."<< endl;
		current = current->next;
	}
}

void Subject::Add(int n){
	if (number == 0){
		ConcreteObserver = new Observer();
		cout << "Observer1 has been added successfully." << endl;
	}
	else
		ConcreteObserver->Add(n);
	number++;
}

int main(){
	Subject *ConcreteSubject = new Subject;
	int option, input, count = 1;
	cout << "********************************************************" << endl;
	cout << "                     1.Add Observer                     " << endl;
	cout << "                     2.Remove Observer                  " << endl;
	cout << "                     3.Update data                      " << endl;
	cout << "                     4.Exit                             " << endl;
	cout << "********************************************************" << endl;
	while (1){
		cout << "Input Option: ";
		cin >> option;
		if (option == 1){
			ConcreteSubject->Add(count);
			count++;
		}
		if (option == 2){
			cout << "Input the oder number of observer: ";
			cin >> input;
			ConcreteSubject->Remove(input);
		}
		if (option == 3){
			cout << "Input the new data: ";
			cin >> input;
			ConcreteSubject->Updata(input);
		}
		if (option == 4)break;
	}
	return 0;
}
