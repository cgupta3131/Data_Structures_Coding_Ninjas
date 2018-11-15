#include<iostream>
#include<string>


using namespace std;

//Space Optimization!!
//Fast Searching!!


class TrieNode
{
public:
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data)
	{
		this->data =  data;
		children  = new TrieNode*[26];

		for(int i=0;i<26;i++)
			children[i] = NULL;

		isTerminal = false;
	}
};


class Trie
{
	TrieNode *root;

public:
	Trie()
	{
		root = new TrieNode('\0');

	}

private:
	void insertWord(TrieNode*root,string word)
	{
		//base case
		if(word.size() == 0)
		{
			root->isTerminal = true;
			return;
		}
		//Calculation
		int index = word[0] -'a';
		TrieNode *child;

		if(root->children[index] != NULL)
			child = root->children[index];
		else
		{
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}

		//Recursive Call
		insertWord(child,word.substr(1));
	}

public:

	void insertWord(string word)
	{
		insertWord(root,word);

	}


private:
	bool search(TrieNode*root, string word) 
	{
     	//BASE CASE
		if(word.size() == 0)
		{
			if(root->isTerminal == true)
				return true;
			else
				return false;
		}


		// Calculation

		int index = word[0] - 'a';
		if( root->children[index] == NULL )
			return false;
		else
		{
			TrieNode* child = root->children[index];
			return search( child,word.substr(1) );
		}
        
    }

public:
	bool search(string word) 
	{
        return search(root,word);
    }


private:
	void removeWord(TrieNode*root, string word)
	{
		//Base Case
		if(root == NULL)
			return;
		if( word.size() == 0 )
		{
			root->isTerminal = false;
			return;
		}

		int index = word[0] - 'a';
		TrieNode *child = root->children[index];

		removeWord( child,word.substr(1) );
		if(child != NULL && child->isTerminal == false)
		{	
			int flag = 0;

			for(int i=0;i<26;i++)
			{
				if(child->children[i] != NULL)
					flag = 1;
			}

			if(flag == 0)//this means that child have no further children and hence I can remove the child
			{	
				delete child;
				root->children[index] = NULL; //i.e we have removed the child!
			}					
		}

	}

public:
	void removeWord(string word)
	{	
		removeWord(root,word);
	}


};

int main()
{
	Trie first;
	first.insertWord("are");
	first.insertWord("and");
	first.insertWord("find");
	first.insertWord("finish");


	cout << first.search("and") << endl;
	first.removeWord("and");
	cout << first.search("and") << endl;

}