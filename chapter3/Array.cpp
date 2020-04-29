#include "Array.h"

class GameEntry{
public:
	using score_t=unsigned int;
	GameEntry():name(""),score(0){};
	GameEntry(const std::string n,score_t s):name(n),score(s){
		
	}
	const std::string& getName(){
		return this->name;
	}
	score_t getScore(){
		return score;
	}

	std::string toString(){
		return "name: "+name+" score: ";
	}
	
private:
	const std::string name;
	score_t score;
};

class GameBoard{
public:
	GameBoard():size(0),data(nullptr),current_size(0){

	}
	GameBoard(size_t size):size(size),data(new GameEntry*[size]),current_size(0){
		for(size_t i=0;i<size;i++){
			data[i]=nullptr;
		}
	}
	~GameBoard(){
		delete [] data;
	}
	void add(GameEntry &elem);
	void remove(size_t index);
	void elements()const;
private:
	size_t size;
	GameEntry **data;
	size_t current_size;
};

void GameBoard::add(GameEntry &elem){
	std::cout<<"insert: {name: "<<elem.getName()<<", score: "<<elem.getScore()<<" }"<<std::endl;
	if( current_size >= size && elem.getScore() <= data[size-1]->getScore() ){
		return;
	}
	if(current_size==0){
		data[0]=&elem;
		current_size=1;
		return;
	}
	size_t index=0;
	while( index<current_size && elem.getScore() <= data[index]->getScore() ){
		index++;
	}
	for(int i=current_size;i>index;i--){
		if(i<size){
			data[i]=data[i-1];
		}
	}
	data[index]=&elem;
	if(current_size<size){
		current_size++;
	}
}

void GameBoard::remove(size_t index){
	std::cout<<"remove index: "<<index<<std::endl;
	if(index>=current_size || index<0){
		std::cout<<"remove index range out of bound"<<std::endl;
		return;
	}
	for(size_t i=index;i<current_size-1;i++){
		data[i]=data[i+1];
	}
	data[current_size-1]=nullptr;
	current_size--;
}

void GameBoard::elements()const{
	using namespace std;
	cout<<"GameBoard中的元素共有"<<current_size<<"个: "<<endl;
	for(size_t i=0;i<current_size;i++){
		cout<<data[i]->getName()<<" : "<<data[i]->getScore()<<endl;
	}
}

void insertSort(int *const pt,int size){
	if(pt==nullptr){
		std::cout<<"the input array is invalid"<<std::endl;
		return;
	}
	if(size<0){
		std::cout<<"array size error"<<std::endl;
		return;
	}
	int *cursor=pt+1;
	while(cursor!=(pt+size)){
		int temp=*cursor;
		for(int* p=pt;p!=cursor;p++){
			if(temp<*p){
				for(int* t=cursor;t!=p;t--){
					*t=*(t-1);
				}
				*p=temp;
				break;
			}
		}
		cursor++;
	}
}

namespace ArrayTest{
	void GameTest(){
		using namespace std;
		cout<<"begin to test Array --->"<<endl;
		GameEntry gameEntry1("zhangsan",1);
		GameEntry gameEntry2("lisi",2);
		GameEntry gameEntry3("wangwu",3);
		GameBoard gameBoard(3);
		gameBoard.add(gameEntry1);
		gameBoard.add(gameEntry2);
		gameBoard.add(gameEntry3);
		gameBoard.elements();
		GameEntry gameEntry4("zhaoqiansun",4);
		gameBoard.add(gameEntry4);
		gameBoard.elements();
		gameBoard.remove(0);
		gameBoard.elements();
		cout<<"<--- finish to test Array"<<endl;

		cout<<"begin to test insert sort -->"<<endl;
		int *p=new int[10]{9,8,7,6,5,4,3,2,1,0};
		insertSort(p,10);
		cout<<"after sort:"<<endl;
		for(auto cur=p;cur!=p+10;cur++){
			cout<<*cur<<" ";
		}
		cout<<endl;
		delete [] p;
		cout<<"<-- finish to test insert sort"<<endl;
	}
}