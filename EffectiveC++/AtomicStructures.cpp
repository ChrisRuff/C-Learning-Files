#include <atomic>
#include <array>

/**
 * Information gathered from: https://youtu.be/ZQFzMfHIxng
 * Chris Ruff
 * Author: Fedor Pikus
 * Comments: Chris Ruff
 */

//QUEUE
std::array<int, 5> q; //Array that represents the queue
std::atomic<size_t> front; //Atomic variable that represents the front of the queue

void push(int x)
{
	size_t my_slot = front.fetch_add(1); //Atomically find the value of x, return it and then add 1. 
	q[my_slot] = x;											 //This means that my_slot will only be a value once --No matter what--
}

//LIST
struct node { int value; node* next; }; //Create the nodes for the linked list
std::atomic<node*> head; //Create a atomic variable that is pointer to the current head

void listPush(int x)
{
	node* new_n = new node; //Create a new node that holds the value x
	new_n->value = x;
	node* old_h = head; //Create a new variable that stores the old value of head(atomically loaded)
	do
	{
		new_n->next = old_h; //Places the new node as the new head
	}while(!head.compare_exchange_strong(old_h, new_n)); //This compares the values of old head and new node and swaps them according to the below method

	/** Sudo code for compare_exchange_strong
	 * x.compare_exchange_strong(old_x, new_x);
	 * 
	 * if(x == old_x) //If x hasn't changed then this is the first thread to access it
	 * {
	 *	 x = new_x; //So write the value of new_x onto x and return that it made the change
	 *	 return true;
	 * }
	 * else //If this wasn't the first thread to access x then
	 * {
	 *	 old_x = x; //Assign old_x to x to keep the data updated and return that it didn't make any changes
	 *	 return false;
	 * }
	 */

}


//Memory Barriers
/**
 * Memory Barriers are the order at which processes happen in memory
 * Types:
 *	Relaxed - No guarentees of any order 
 *	Aquire - Nothing that is before the barrier in program order can be observed before the store operation 
 *	Release - Nothing that is after the barrier in program order can be observed after the store operation
 *	Bidirectional - Aquire-Release
 *	Sequential consistency - Strictest
 *
 *	Often these are used incombination, so thread 1 will write atomic variable x using release barrier 
 *	and thread 2 will read atomic variable x with the aquire barrier
 *
 *	Memory Barriers are expensive, but increase performance.
 */

//			std::atomic<int> x{0};
//			x.store(1, std::memory_order_release); //Release memory barrior on the store

std::atomic<size_t> count; //Creates an atomic that counts
size_t out = count.fetch_add(1, std::memory_order_relaxed); //Adds one to that variable atomically and the order of the memory does not matter
//What this means:
//Count is incremented concurrently, not used to index any memory or as a reference count( no other memory access depends on it)


std::atomic<size_t> count2;
size_t out2 = count2.fetch_add(1, std::memory_order_release);
//What this means:
//count indexes some memory that was prepared by this thread and is now released to other threads

int main()
{
	return 0;
}

