#include <iostream>
#include "main.hpp"
using namespace std;

int main(){
	test_chapter_3();
}

void test_chapter_1(){
	cout<<"test chapter 1"<<endl;
}

void test_chapter_3(){
	cout<<"=>> test chapter 3"<<endl;
	// ArrayTest::GameTest();
	ListTest::test();
	// CipherTest::cipherTest();
	cout<<"finish to test chapter 3 <<="<<endl;
}