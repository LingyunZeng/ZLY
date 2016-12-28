#include<iostream>
#include<vector>
#include <stack>

using namespace std;

static struct Option{
	int type;
	char ch;
};

class UndoRedo{
public:
	void Print();
	void Add(char);
	void Remove();
	void Undo();
	void Redo();
private:
	vector<char> storage;
	stack<Option> sUndo;
	stack<Option> sRedo;
};

void UndoRedo::Print(){
	vector<char>::iterator ite;
	cout << "Current String is ";
	for (ite = storage.begin(); ite != storage.end(); ++ite)
		cout << *ite ;
	cout << endl;
}

void UndoRedo::Add(char ch){
	Option op = { 1, ch };
	storage.push_back(ch);
	sUndo.push(op);
}

void UndoRedo::Remove(){
	if (storage.empty() == 1){
		cout << "Fail!" << endl;
	}
	else{
		vector<char>::iterator ite;
		ite = storage.end() - 1;
		char ch = *ite;
		Option op = { 2, ch };
		storage.erase(storage.end() - 1);
		sUndo.push(op);
	}
}
void UndoRedo::Undo(){
	if (sUndo.empty() == 1){
		cout << "Fail!" << endl;
	}
	else{
		Option op = sUndo.top();
		sUndo.pop();
		if (op.type == 1){
			storage.erase(storage.end() - 1);
		}
		if(op.type == 2){
			storage.push_back(op.ch);
		}
		sRedo.push(op);
	}
}
void UndoRedo::Redo(){
	if (sRedo.empty() == 1){
		cout << "Fail!" << endl;
	}
	else{
		Option op = sRedo.top();
		sRedo.pop();
		if (op.type == 1){
			storage.push_back(op.ch);
		}
		if (op.type == 2){
			storage.erase(storage.end() - 1);
		}
		sUndo.push(op);
	}
}

int main(){
	UndoRedo example;
	int a;
	char ch;
	cout << "********************************************************" << endl;
	cout << "                        1.Insert                        " << endl;
	cout << "                        2.Delete                        " << endl;
	cout << "                        3.Undo                          " << endl;
	cout << "                        4.Redo                          " << endl;
	cout << "                        5.Exit                          " << endl;
	cout << "********************************************************" << endl;
	while (1){
		cin >> a;
		if (a == 1){
			cin >> ch;
			example.Add(ch);
			example.Print();
		}
		if (a == 2){
			example.Remove();
			example.Print();
		}
		if (a == 3){
			example.Undo();
			example.Print();
		}
		if (a == 4){
			example.Redo();
			example.Print();
		}
		if (a == 5)break;
	}
	return 0;
}