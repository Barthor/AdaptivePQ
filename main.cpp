#include <iostream>
#include <random>

/*
 * node to be used in pq linked list implementation
 *alternatively can use a binary heap for the queue
 *some implemetations of pq use any comparable data for the priority
 *others will use a seperate priority value
 **/

struct node
{
    int data;
    struct node *next;
};

class PQ
{
private:
    node *front;
public:
    PQ()
    {
        front = NULL;
    }
    void insert_item(int item)
    {
        node *temp, *q;
        temp = new node;
        std::cout << "Inserting: "<< item << std::endl;
        temp -> data = item;
        if (front == NULL || item < front->data)
        {
            temp->next = front;
            front = temp;
        }
        else {
            q = front;
            while (q->next != NULL && q->next->data <= item) {
                q = q->next;
            }
            temp->next = q->next;
            q->next = temp;
        }
    }
    void delete_item() {
        node *temp;
        if (front == NULL) {
            std::cout << "Queue underflow\n";
        } else {
            temp = front;
            std::cout << "Deleting: " << temp->data << std::endl;
            front = front->next;
            free(temp);
        }
    }
    void print_queue()
    {
        node *temp;
        temp = front;
        if (front == NULL)
        {
            std::cout << "Queue is empty \n";
        }
        else
        {
            std::cout << "Queue is : \n";
            while (temp != NULL)
            {
                std::cout << temp->data <<std::endl;
                temp = temp->next;
            }
        }
    }

};
int main() {
    PQ pq;
    int opNum = 10;
    std::random_device rd;
    std::random_device rd2;
    std :: mt19937 eng(rd());
    std:: mt19937 eng2(rd2());
    std::uniform_int_distribution<> distr(0, 0);
    std::uniform_int_distribution<> distr2(0,100);
    int operation;
    int item;
   for (int i=0;i<opNum;i++)
   {
       operation = distr(eng);
       switch (operation)
       {
           case 0:
               item = distr2(eng2);
               pq.insert_item(item);
               break;
           case 1:
               //pq.delete_item();
               break;
           case 2:
               pq.print_queue();
               break;

       }
   }
    pq.print_queue();
    return 0;
}