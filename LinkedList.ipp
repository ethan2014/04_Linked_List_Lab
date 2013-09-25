//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
// Constructor
LinkedList<T>::LinkedList(){
  numItems = 0;
  dummyNode = new Node();
  dummyNode->next = dummyNode;
  dummyNode->prev = dummyNode;

}

template <class T>
// Destructor
LinkedList<T>::~LinkedList() {
  while (numItems > 0) {
	remove(0);
	}
	delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	
// Test to make sure that i is a legal position in 
// the list, if not throw an exception
	if (i > numItems || i < 0)
		throw std::string("Item not valid!");
// Create a node pointer that can hold the item address
	Node* item;
	if (i < numItems/2) {
		item = dummyNode->next;
		for (int j = 0; j < i; j++) {
			item = item->next;
		} 
	 } else {
		item = dummyNode;
		for (int k = numItems; k > i; k--) {
			item = item->prev;
		}
	  }
	return item;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  //TODO
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
// Test to make sure that the placing the variable x
// in position i is legal
	if (i > numItems || i < 0) {
		throw std::string("Couldn't place item in the list!");
	}
// If i is a position in the list then go ahead and add item
	Node* temp = new Node();
	Node* cur = find(i);
	temp->next = cur;
	temp->prev = cur->prev;
	temp->data = x;
	temp->prev->next = temp;
	temp->next->prev = temp;

}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  //TODO
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  //TODO -- The code that is here is a useless stub, you probably
  // want to delete it
  Node junkNode;
  return junkNode.data; //This is unitialized data
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
  // Return the number of items in the list by calling numItems
  return numItems;
}
