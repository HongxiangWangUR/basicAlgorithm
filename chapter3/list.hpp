#ifndef LIST
#define LIST
#include "../common.hpp"
#include <typeinfo>
template<typename> class ListNode;
template<typename T> class SinglyLinkedList;
template <typename T> class CircularList;
template<class T> std::ostream& operator<<(std::ostream& out,const SinglyLinkedList<T> &list);
template<class T> std::ostream& operator<<(std::ostream& out,CircularList<T>& list);
template<typename T> class DoubleLinkedList;
template<typename T> std::ostream& operator<<(std::ostream& out,DoubleLinkedList<T>& list);
namespace ListTest{
	void test();
	void testSinglyLinkedList();
	void testCircularList();
	void testDoubleLinkedList();
}
#endif