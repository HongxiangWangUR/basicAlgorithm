#ifndef LIST
#define LIST
#include "../common.h"
template<typename> class ListNode;
template<typename T> class SinglyLinkedList;
template<class T> std::ostream& operator<<(std::ostream& out,const SinglyLinkedList<T> &list);
namespace ListTest{
	void test();
}
#endif