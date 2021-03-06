#include "list.hpp"

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

template <typename T> class CircularList{
	friend std::ostream& operator<<<T>(std::ostream& out,CircularList<T>& list);
	public:
	CircularList():tail(nullptr),size(0){}

	size_t getSize(){
		return this->size;
	}

	bool isEmpty(){
		return getSize() <= 0;
	}

	ListNode<T>* first(){
		if(tail==nullptr){
			return nullptr;
		}
		return tail->getNext();
	}

	ListNode<T>* last(){
		if(isEmpty()){
			return nullptr;
		}
		else{
			return tail;
		}
	}

	void addFirst(T elem){
		ListNode<T> *node=new ListNode<int>(elem,nullptr);
		if(this->isEmpty()){
			tail=node;
			tail->setNext(tail);
		}else{
			node->setNext(tail->getNext());
			tail->setNext(node);
		}
		size++;
	}

	void addLast(T elem){
		ListNode<T> *node=new ListNode<int>(elem,nullptr);
		if(this->isEmpty()){
			tail=node;
			tail->setNext(tail);
		}else{
			node->setNext(tail->getNext());
			tail->setNext(node);
			tail=node;
		}
		size++;
	}

	ListNode<T>* removeFirst(){
		if(isEmpty()){
			return nullptr;
		}
		ListNode<T>* ret=tail->getNext();
		if(getSize() == 1){
			ret->setNext(nullptr);
			tail=nullptr;
		}else{
			tail->setNext(tail->getNext()->getNext());
			ret->setNext(nullptr);
		}
		size--;
		return ret;
	}

	~CircularList(){
		if(tail != nullptr){
			ListNode<T>* head=tail->getNext();
			tail->setNext(nullptr);
			delete head;
		}
	}
	private:
	ListNode<T>* tail;
	size_t size;
};

template<class T> std::ostream& operator<<(std::ostream& out,CircularList<T>& list){
	ListNode<T>* cursor=list.first();
	while(cursor!=list.last() && cursor != nullptr){
		std::cout<<cursor->getElem()<<"->";
		cursor=cursor->getNext();
	}
	if(cursor!=nullptr){
		std::cout<<cursor->getElem()<<"->";
	}
	if(cursor!=nullptr){
		std::cout<<"HEAD"<<std::endl;
	}else{
		std::cout<<"END"<<std::endl;
	}
	return out;
}

template<class T> std::ostream& operator<<(std::ostream& out,DoubleLinkedList<T>& list){
	typename DoubleLinkedList<T>::Node* cursor=list.getFirst();
	out<<"doublelinkedlist current state: ";
	while(cursor != nullptr){
		out<<cursor->getElement()<<"->";
		cursor=cursor->getNext();
	}
	out<<"NULL"<<std::endl;
	return out;
}

template<typename T> class DoubleLinkedList{
	friend std::ostream& operator<<<T>(std::ostream& out,DoubleLinkedList<T>& list);
	public:
	class Node{
		private:
		T elem;
		Node* prev;
		Node* next;
		public:
		Node(T e):elem(e),prev(nullptr),next(nullptr){
			
		}
		void setPrev(Node* p){
			this->prev=p;
		}
		void setNext(Node* n){
			this->next=n;
		}
		Node* getPrev();
		Node* getNext(){
			return next;
		}
		T getElement(){
			return elem;
		}
		~Node();
	};
	DoubleLinkedList():size(0),head(nullptr),tail(nullptr){

	}
	size_t getSize(){
		return size;
	}
	bool isEmpty(){
		return this->getSize() <= 0;
	}

	Node* getFirst(){
		return head;
	}

	Node* getLast(){
		return tail;
	}

	void addFirst(Node* n);
	void addLast(Node* n);
	Node* removeFirst();
	Node* removeLast();
	Node* remove(Node* n);
	void addBetween(Node* prev,Node* next,T value);
	~DoubleLinkedList();
	private:
	size_t size;
	Node* head;
	Node* tail;
};

template<typename T> typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::Node::getPrev(){
	return this->prev;
}

template<class T> DoubleLinkedList<T>::Node::~Node(){
	std::cout<<"销毁元素: "<<this->elem<<std::endl;
	this->next=nullptr;
	this->prev=nullptr;
}

template<class T> DoubleLinkedList<T>::~DoubleLinkedList(){
	typename DoubleLinkedList<T>::Node* cursor=getLast();
	while(cursor!=this->head){
		typename DoubleLinkedList<T>::Node* temp=cursor->getPrev();
		delete cursor;
		cursor=temp;
	}
	if(cursor!=nullptr){
		delete cursor;
	}
}

template<typename T> void DoubleLinkedList<T>::addFirst(Node* n){
	if(head==nullptr || tail== nullptr){
		head=n;
		tail=n;
		n->setPrev(nullptr);
		n->setNext(nullptr);
	}else{
		n->setNext(head);
		n->setPrev(nullptr);
		head->setPrev(n);
		head=n;
	}
	this->size++;
}

template<typename T> void DoubleLinkedList<T>::addLast(Node* n){
	if(isEmpty()){
		this->head=n;
		this->tail=n;
		n->setPrev(nullptr);
		n->setNext(nullptr);
	}else{
		this->tail->setNext(n);
		n->setPrev(tail);
		n->setNext(nullptr);
		tail=n;
	}
	this->size++;
}

template<typename T> typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::removeFirst(){
	if(this->isEmpty()){
		return nullptr;
	}
	Node* ret=this->getFirst();
	if(ret->getNext() == nullptr){
		this->head=nullptr;
		this->tail=nullptr;
	}else{
		this->head=this->head->getNext();
		if(this->head==nullptr){
			this->tail=nullptr;
		}else{
			this->head->setPrev(nullptr);
		}
	}
	ret->setNext(nullptr);
	ret->setPrev(nullptr);
	this->size--;
	return ret;
}

template<class T> typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::removeLast(){
	if(this->isEmpty()){
		return nullptr;
	}
	Node* ret=this->tail;

	if(this->getSize()==1){
		this->head=nullptr;
		this->tail=nullptr;
	}else{
		ret->getPrev()->setNext(nullptr);
		this->tail=ret->getPrev();
	}
	ret->setNext(nullptr);
	ret->setPrev(nullptr);
	this->size--;
	return ret;
}

template<typename T> typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::remove(Node* n){
	if(n==nullptr){
		return nullptr;
	}
	Node* prev=n->getPrev();
	Node* next=n->getNext();

	prev->setNext(next);
	next->setPrev(prev);
	return n;
}

template<class T> void DoubleLinkedList<T>::addBetween(Node* prev,Node* next,T value){
	Node* node=new Node(value);
	prev->setNext(node);
	next->setPrev(node);
	node->setNext(next);
	node->setPrev(prev);
	this->size++;
}

namespace ListTest{
	void test(){
		//testSinglyLinkedList();
		// testCircularList();
		testDoubleLinkedList();
	}

	void testSinglyLinkedList(){
		std::cout<<">>>---------> 开始测试单链表 ------->>"<<std::endl;
		SinglyLinkedList<int> list;
		std::cout<<" 测试 addFirst() 方法 "<<std::endl;
		list.addFirst(1);list.addFirst(2);list.addFirst(3);
		std::cout<<list;
		std::cout<<" 测试 addLast() 方法 "<<std::endl;
		list.addLast(4);list.addLast(5);list.addLast(6);
		std::cout<<list;
		std::cout<<" 链表的大小: "<<list.getSize()<<std::endl;
		std::cout<<"<<--------<<  测试单点链表完成 <--------<<<"<<std::endl;
	}

	void testCircularList(){
		std::cout<<">> ----> 开始测试循环链表 >> ------>"<<std::endl;
		CircularList<int> list;
		std::cout<<"测试addLast()方法"<<std::endl;
		list.addLast(1);list.addLast(2);list.addLast(3);
		std::cout<<list;
		std::cout<<"测试removeFirst()方法"<<std::endl;
		list.removeFirst();
		std::cout<<list;
		std::cout<<"测试addFirst()方法"<<std::endl;
		list.addFirst(4);
		std::cout<<list;
		std::cout<<"<< -------<< 测试循环链表完成 << -----<<"<<std::endl;
	}

	void testDoubleLinkedList(){
		std::cout<<">> ------> 开始测试双向链表 >> ----->"<<std::endl;
		DoubleLinkedList<int> list;
		DoubleLinkedList<int>::Node* elem1=new DoubleLinkedList<int>::Node(1);
		DoubleLinkedList<int>::Node* elem2=new DoubleLinkedList<int>::Node(2);
		list.addFirst(elem1);list.addLast(elem2);
		list.addFirst(new DoubleLinkedList<int>::Node(3));list.addLast(new DoubleLinkedList<int>::Node(4));
		std::cout<<list;
		list.removeFirst();
		std::cout<<list;
		list.removeLast();
		std::cout<<list;
		list.addBetween(elem1,elem2,5);
		std::cout<<list;
		std::cout<<"<< ---------< 测试双向链表完成 << -------<<"<<std::endl;
	}
}