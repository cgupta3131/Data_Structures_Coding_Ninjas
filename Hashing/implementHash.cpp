#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


template <typename V>
class MapNode{

public:
	string key;
	V value;
	MapNode* next;

	MapNode(string key, V value)
	{
		this->key = key;
		this-value = value;
		next = NULL;

	}

};


template <typename V>

class ourmap{
	MapNode<V>** buckets; //is an array which will store the head of Linked List, Hence double pointer!!
	int count;
	int numBuckets;

	ourmap()
	{
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets]; //initializing the array of head of LL

		for(int i=0;i<numBuckets;i++)
			buckets[i] = NULL;
	}

	~ourmap()
	{
		for(int i=0;i<numBuckets;i++)
			delete buckets[i];  //first I will delete the linked List at each index of buckets array

		delete [] buckets; //then I will delete the array
	}


	int size(){
		return count;
	}


private:
	int getBucketIndex(string key)
	{
		int hashcode = 0; 

		int currentCoeff = 1;

		for(int i= key.length()-1;i>=0;i--)
		{
			hashcode += key[i]*currentCoeff;
			hashcode = hashcode % numBuckets;

			currentCoeff *= 37;
			currentCoeff = currentCoeff % numBuckets; //to make the value smaller and don't allow overflow

		// modulus has an awesome property that it can be pushed inside as many times as we want!

		}


		return hashcode % numBuckets;

	}

public:
	V getValue(string key)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V> *head = buckets[bucketIndex];

		while(head != NULL)
		{

			if(head->key == key)
				return head->value;

			head = head->next;
		}

		return 0;
	}

	void rehash()
	{
		MapNode<V> **temp = buckets;
		buckets = new MapNode<V>*[2*numBuckets];

		for(int i=0;i<2*numBuckets;i++)
			buckets[i] = NULL;


		int oldBucketCount = numBuckets;
		numBuckets *= 2;
		count = 0;

		for(int i=0;i<oldBucketCount;i++)
		{
			MapNode<V> *head = temp[i];

			while(head != NULL)
			{
				string key = head->key;
				V value = head->value;
				insert(key,value);

				head = head->next;
			}

		}

		for(int i=0;i< oldBucketCount ; i++)
		{
			MapNode<V> *head = temp[i];
			delete head; //fist deleting the Linked Lists in temp[i]
		}

		delete [] temp;	//then delete the whole temp array


	}




	void insert(string key, V value)
	{

		int bucketIndex = getBucketIndex(key);
		MapNode<V> *head = buckets[bucketIndex];

		while(head != NULL)
		{
			if(head->key == key)
			{
				head->value = value;
				return;
			}

			head = head->next;
		}

		head = buckets[bucketIndex];

		MapNode<V>* node = new MapNode<V>(key,value);
		node->next = head;
		buckets[bucketIndex] = node;
		count++;


		double loadFactor = 1.0*count/numBuckets;
		if(loadFactor > 0.7)
			rehash();
		

	}




	V remove(string key)
	{

		int bucketIndex = getBucketIndex(key);
		MapNode<V> *head = buckets[bucketIndex];
		MapNode<V> *prev = NULL;

		while(head != NULL)
		{
			if(head->key == key)
			{

				if(prev == NULL)
					buckets[bucketIndex] = head->next;
				
				else
					prev->next = head->next;

				V value = head->value;

				head->next = NULL;
				delete head;
				count--;

				return value;
			}

			prev = head;
			head = head->next;
		}

		return 0;

	}





};


int main()
{

	cout << "helloworld" << endl;
}