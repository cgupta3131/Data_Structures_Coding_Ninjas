#include<iostream>
#include<string>
#include<vector>

using namespace std;


int parent(int i)
{
    return (i-1)/2;
}

int leftChild(int i)
{
    return 2*i+1;
}

int rightChild(int i)
{
    return 2*i+2;
}

struct Student
{
    int _data ; 

public:
    int data() { return _data ;  }


};

// MOVE DOWN
int Min(int A[], int i, int l, int r, int HEAP_SIZE) 
{
    int smallestIndex = i;

    if(l<HEAP_SIZE && A[smallestIndex] > A[l])
        smallestIndex = l;

    if(r<HEAP_SIZE && A[smallestIndex] > A[r])
        smallestIndex = r;

    return smallestIndex;
}

void move_down(int A[], int index, int &HEAP_SIZE)
{
    int l = leftChild(index);
    int r = rightChild(index);

    int x = Min(A,index,l,r,HEAP_SIZE);
    if(x != index)
    {
        swap(A[x],A[index]);
        move_down(A,x,HEAP_SIZE);
    }   
}


//MOVE UP
void move_up(int A[], int index, int &HEAP_SIZE)
{

    while(index>=0 && A[index] < A[parent(index)])
    {
        if(index == 0)
            break;
        swap(A[index],A[parent(index)]);
        index = parent(index);
    }
}



void Insert(int A[], int element, int &HEAP_SIZE)
{
    A[HEAP_SIZE] = element;
    int i = HEAP_SIZE;

    HEAP_SIZE++;

    move_up(A,i,HEAP_SIZE);

    
}


int getMin(int A[], int &HEAP_SIZE)
{
    int answer = A[0];
    return answer;
}

void removeMin(int A[], int &HEAP_SIZE)
{
    swap(A[0],A[HEAP_SIZE-1]);
    HEAP_SIZE--;

    move_down(A,0,HEAP_SIZE);

    return;
}



int main()
{

    int n;
    cin >> n;

    int heap[1000] = {};
    int HEAP_SIZE = 0;

    string input;

    for(int i=0;i<n;i++)
    {
        cin >> input;
        
        if(input == "insert")
        {   
            int x;
            cin >> x;

            Insert(heap,x,HEAP_SIZE);

            cout << "\t Insert " << x << endl; 
            
        }


        else if(input == "getMin")
        {
            int x;
            cin >> x;

            if(x == getMin(heap,HEAP_SIZE))
            {
                cout << "\tgetMin " << heap[0] << endl;
                continue;
            }


            while(HEAP_SIZE != 0)
            {
               
                if(getMin(heap,HEAP_SIZE) == x)
                    break;

                cout << "\tremoveMin" << endl;
                removeMin(heap,HEAP_SIZE);
                
            }

            if(HEAP_SIZE == 0)
            {
                Insert(heap,x,HEAP_SIZE);
                cout << "\t Insert " << x << endl; 
            }

            cout << "\tgetMin " << heap[0] << endl;
        }

        else if(input == "removeMin")
        {
            removeMin(heap,HEAP_SIZE);
            cout << "\tremoveMin" << endl;
        }

    }

    
    


}

