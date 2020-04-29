#include "list.h"

template<typename T> class ListNode{
public:
	ListNode(T elem,ListNode<T> *next):elem(elem),next(next){

	}
	T getElem(){
		return this->elem;
	}
	void setNext(ListNode<T>* next){
		this->next=next;
	}
	ListNode<T>* getNext(){
		return next;
	}
private:
	T elem;
	ListNode<T>* next;
};

namespace ListTest{
	void testNode(){
		using namespace std;
		ListNode<int> node(1,nullptr);
		cout<<"the node value is: "<< node.getElem() <<endl;
	}
}