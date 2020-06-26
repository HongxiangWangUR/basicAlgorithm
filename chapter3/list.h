#ifndef LIST
#define LIST
#include "../common.hpp"
template<typename> class ListNode;
template<typename T> class SinglyLinkedList;
template <typename T> class CircularList;
template<class T> std::ostream& operator<<(std::ostream& out,const SinglyLinkedList<T> &list);
template<class T> std::ostream& operator<<(std::ostream& out,CircularList<T>& list);
namespace ListTest{
	void test();
	void testSinglyLinkedList();
	void testCircularList();
}
#endif