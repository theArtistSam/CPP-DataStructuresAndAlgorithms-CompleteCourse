#include<iostream>
using namespace std;
struct node
{
	int data;
	node*next = NULL;
};

class queue1{
	node*front = NULL;
	node*rear = NULL;
public:
    bool isOne(){
        if (front == rear && front != NULL)
        {
            return true;
        }
        return false;
        
    }
	bool isEmpty()
	{
		if (front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void enqueue(int x)
	{
		node*temp = new node();
		temp->data = x;
		if (isEmpty())
		{
			front = rear = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}
	void dequeue()
	{
		if (front == rear)
		{
			front = rear = NULL;
		}
		else
		{
			node*temp = front;
			front = front->next;
			delete temp;
		}
	}
	void display()
	{
		node*temp = front;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;

		}
		cout << endl;
	}
    int returnFront(){
        return front->data;
    }
};

queue1 reverseQueue(queue1 q){
    queue1 q2;
    queue1 q3;

    while (!q.isEmpty())
    {
        while (!q.isOne())
        {
            q2.enqueue(q.returnFront());
            q.dequeue();
        }
        q3.enqueue(q.returnFront());
        q.dequeue();

        queue1 t = q;
        q = q2;
        q2 = t;
        
    }

    return q3;
    

}


int main()
{
	queue1 abc;
	abc.enqueue(5);
	abc.enqueue(6);
	abc.enqueue(7);
	abc.display(); 
	queue1 reverse = reverseQueue(abc);
    reverse.display();
	
}

