#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Component{
public:
	Component(string str){name = str;}
	virtual ~Component(){}
	virtual void Add(Component* ) = 0;
	virtual void Remove(Component* ) = 0;
	virtual Component* GetChild(int) = 0;
	virtual string GetName(){return name;}
	virtual void Print() = 0;
	string name;
};

class Leaf : public Component{
public:
	Leaf(string str) : Component(str){};
	void Add(Component* p){};
	void Remove(Component* p){};
	Component* GetChild(int n){return NULL;}
	void Print(){}
};

class Composite : public Component{
public:
	Composite(string str) : Component(str){};
	void Add(Component* p){vec.push_back(p);}
	void Remove(Component*);
	Component* GetChild(int);
	void Print(){
		for (vector<Component* >::iterator ite = vec.begin(); ite != vec.end(); ++ite)
			cout << (*ite)->GetName() << endl;
	}
private:
	vector<Component* > vec;
};

void Composite::Remove(Component* p){
	for (vector<Component*>::iterator ite = vec.begin(); ite != vec.end(); ++ite){
		if ((*ite)->GetName() == p->GetName()){
			if (*ite != NULL){
				delete* ite;
				*ite = NULL;
			}
			vec.erase(ite);
			break;
		}
	}
}

Component* Composite::GetChild(int n){
	if (n > vec.size())
		return NULL;
	return vec[n - 1];
}

int main(){
	Component* C1 = new Composite("Composite1");
	Component* L1 = new Leaf("Leaf1");
	Component* C2= new Composite("Composite2");
	Component* C3 = new Composite("Composite3");
	Component* C4 = new Composite("Composite4");
	C1->Add(L1);
	C1->Add(C2);
	C1->Add(C3);
	C1->Add(C4);
	C1->Print();
	cout << endl;
	Component* L2 = new Leaf("Leaf2");
	Component* L3 = new Leaf("Leaf3");
	Component* L4 = new Leaf("Leaf4");
	Component* L5= new Leaf("Leaf5");
	C2->Add(L2);
	C2->Add(L3);
	C2->Add(L4);
	C2->Add(L5);
	C2->Print();
	cout << endl;
	C2->Remove(L5);
	C2->Print();
	cout << endl;
	C1->Remove(C2);
	C1->Print();
	return 0;
}