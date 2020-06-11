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
	~ListNode(){
		if(next!=nullptr){
			delete next;
			next=nullptr;
		}
	}
private:
	T elem;
	ListNode<T>* next;
};

template<typename T> class SinglyLinkedList{
	friend std::ostream& operator<<<T>(std::ostream& out,const SinglyLinkedList<T> &list);
	private:
	ListNode<T> *head;
	ListNode<T> *tail;
	size_t size;
	public:
	SinglyLinkedList(ListNode<T>* head=nullptr,ListNode<T>* tail=nullptr,size_t size=0):head(head),tail(tail),size(size){

	}
	size_t getSize(){
		return this->size;
	}
	bool isEmpty(){
		return this->size == 0;
	}

	ListNode<T>* first(){
		return head;
	}
	ListNode<T>* last(){
		return tail;
	}

	void addFirst(T elem);
	void addLast(T elem);
	ListNode<T>* removeFirst();

	~SinglyLinkedList(){
		if(head==nullptr){
			delete head;
			head=nullptr;
		}
		if(tail==nullptr){
			delete tail;
			tail=nullptr;
		}
	}
};

template <class T> void SinglyLinkedList<T>::addFirst(T elem){
	ListNode<T> *node=new ListNode<T>(elem,head);
	head=node;
	if(isEmpty()){
		tail=node;
	}
	size++;
}

template<typename T> void SinglyLinkedList<T>::addLast(T elem){
	ListNode<T> *node=new ListNode<T>(elem,nullptr);
	if(isEmpty()){
		head=node;
		tail=node;
	}else{
		tail->setNext(node);
		tail=node;
	}
	size++;
}

template<class T> ListNode<T>* SinglyLinkedList<T>::removeFirst(){
	if(isEmpty()){
		return nullptr;
	}
	ListNode<T> ret=head;
	head=head->getNext();
	size--;
	return ret;
}

template<class T> std::ostream& operator<<(std::ostream& out,const SinglyLinkedList<T> &list){
	ListNode<T> *cursor=list.head;
	while(cursor != nullptr && cursor!= list.tail->getNext()){
		std::cout<<cursor->getElem()<<"->";
		cursor=cursor->getNext();
	}
	std::cout<<"END"<<std::endl;
	return out;
}
namespace ListTest{
	void test(){
		std::cout<<">>>---------> 开始测试单链表 ------->>"<<std::endl;
		using namespace std;
		SinglyLinkedList<int> list;
		std::cout<<" 测试 addFirst() 方法 "<<std::endl;
		list.addFirst(1);list.addFirst(2);list.addFirst(3);
		std::cout<<list;
		std::cout<<" 测试 addLast() 方法 "<<std::endl;
		list.addLast(4);list.addLast(5);list.addLast(6);
		std::cout<<list;
		std::cout<<" 链表的大小: "<<list.getSize()<<endl;
		std::cout<<"<<--------<<  测试单点链表完成 <--------<<<"<<std::endl;
	}
}