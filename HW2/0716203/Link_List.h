#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
using namespace std;

template <typename T>
struct Int_Node
{
    T value;
    Int_Node<T> *pre, *next;
};

template <typename T>
class Link_List
{
    template <typename U>
    friend ostream &operator<<(ostream &, const Link_List<U> &);  	// print all integers in the list
    template <typename U>
    friend istream &operator>>(istream &, Link_List<U> &);			// input a value at the back of the list, like insert_node(val);

public:
    Link_List();										// default constructor
    Link_List(const Link_List &);						// copy constructor
    ~Link_List();
    int getSize() const;

    const Link_List &operator=(const Link_List &);		// assignment operator
    bool operator==(const Link_List &) const;			// equality operator
    bool operator!=(const Link_List &right) const		// inequality operator
    {
        return !(*this == right);
    }

    T &operator[](int index);							// subscript operator for non-const objects
    T operator[](int index) const;						// subscript operator for const objects

    bool insert_node(T value);							// insert an integer at the back of link list
    bool delete_node();									// delete the last node
    bool insert_node(int index, T value);				// insert an integer after the i_th position
    bool delete_node(int index);						// delete the i_th node

private:
    int size;
    Int_Node<T> *head, *tail;								// pointer to the first and the last element of Link_List
};

template <typename U>
ostream &operator<<(ostream &output, const Link_List<U> &linkList)
{
    if(linkList.getSize()!=0)
    {
        Int_Node<U> *current;
        current=linkList.head;
        while(current!=nullptr)
        {
            output<<current->value<<" ";
            current=current->next;
        }
    }
    return output;
}  	// print all integers in the list

template <typename U>
istream &operator>>(istream &input, Link_List<U> &linkList)
{
    if(linkList.getSize()!=0)
    {
        Int_Node<U> *current =linkList.tail;
        current->next=linkList.tail=new Int_Node<U>;
        input>>linkList.tail->value;
        linkList.tail->next=nullptr;

    }
    else if(linkList.getSize()==0)
    {
        linkList.head=linkList.tail=new Int_Node<U>;
        input>>linkList.head->value;
        linkList.tail->next=nullptr;
    }

    linkList.size+=1;
    return input;
}			// input a value at the back of the list, like insert_node(val);

template <typename U>
Link_List<U>::Link_List()
    :head(nullptr),tail(nullptr),size(0)
{

}// default constructor

template <typename T>
Link_List<T>::Link_List(const Link_List &linkList)
{
    size=linkList.size;
    head=new Int_Node<T>;
    tail=new Int_Node<T>;
    if(size==0)
    {
        head=nullptr;
        tail=nullptr;
        return;
    }
    else
    {
        head->value=linkList.head->value;
        Int_Node<T> *current=linkList.head;
        Int_Node<T> *newptr=head;
        for(int i=1; i<size; i++)
        {
            newptr->next=new Int_Node<T>;
            newptr=newptr->next;
            current=current->next;
            newptr->value=current->value;
        }
        tail=newptr;
        tail->next=new Int_Node<T>;
        tail->next=nullptr;
    }


}					// copy constructor

template <typename T>
Link_List<T>::~Link_List()
{
    if(getSize()!=0)
    {
        Int_Node<T> *current=head;
        Int_Node<T> *temp;

        while(current!=nullptr)
        {
            temp=current;
            current=current->next;
            delete temp;
        }
    }
}

template <typename T>
int Link_List<T>::getSize() const
{
    return size;
}

template <typename T>
const  Link_List<T> &Link_List<T>::operator=(const Link_List &linkList)
{
    size=linkList.size;
    head=new Int_Node<T>;
    tail=new Int_Node<T>;
    if(size==0)
    {
        head=nullptr;
        tail=nullptr;
    }
    else
    {
        head->value=linkList.head->value;
        Int_Node<T> *current=linkList.head;
        Int_Node<T> *newptr=head;
        for(int i=1; i<size; i++)
        {
            newptr->next=new Int_Node<T>;
            newptr=newptr->next;
            current=current->next;
            newptr->value=current->value;
        }
        tail=newptr;
        tail->next=new Int_Node<T>;
        tail->next=nullptr;
    }
    return *this;

}	// assignment operator

template <typename T>
bool Link_List<T>::operator==(const Link_List &linkList) const
{
    if(size==linkList.size)
    {
        Int_Node<T> *current=linkList.head;
        Int_Node<T> *newptr=head;
        while(current!=nullptr)
        {
            if(newptr->value!=current->value)
                return false
            else
            {
                current=current->next;
                newptr=newptr->next;
            }
        }
        return true;
    }
    return false;
}			// equality operator


template <typename T>
T &Link_List<T>::operator[](int index)
{
    Int_Node<T> *current=head;
    for(int i=1; i<=index; i++)
    {
        if(i==index)
            return current->value;
        else
        {
            current=current->next;
        }
    }
}							// subscript operator for non-const objects

template <typename T>
T Link_List<T>::operator[](int index) const
{

        Int_Node<T> *current=head;
        for(int i=1; i<=index; i++)
        {
            if(i==index)
                return current->value;
            else
            {
                current=current->next;
            }
        }


}
// subscript operator for const objects

template <typename T>
bool Link_List<T>::insert_node(T value)
{
    if(this->getSize()==0)
    {
        head=new Int_Node<T>;
        tail=new Int_Node<T>;
        head->value=tail->value=value;
        tail->next=nullptr;
    }
    else if(this->getSize()!=0)
    {
        Int_Node<T> *current;
        current=this->tail;
        current->next=tail=new Int_Node<T>;
        tail->value=value;
        tail->next=nullptr;
    }
    size++;
    return true;
}							// insert an integer at the back of link list

template <typename T>
bool Link_List<T>::delete_node()
{
    if(this->getSize()==0)
        return false;
    else
    {
        Int_Node<T> *temp=tail;
        Int_Node<T> *current=head;
        while(current->next!=tail)
            current=current->next;
        tail=current;
        current->next=nullptr;

        delete temp;
        size--;
        return true;
    }
}									// delete the last node

template <typename T>
bool Link_List<T>::insert_node(int index, T value)
{
    if(index>getSize())
        return false;
    else if(getSize()==0&&index==1)
    {
        head=tail=new Int_Node<T>;
        head->value=tail->value=value;
        tail->next=nullptr;
        size++;
        return true;
    }
    else
    {
        Int_Node<T> *current=head;
        Int_Node<T> *newPtr=new Int_Node<T>;
        newPtr->value=value;
        for(int i=1; i<=index; i++)
        {
            if(i!=index-1)
            {
                current=current->next;
            }
            else
            {
                newPtr->next=current->next;
                current->next=newPtr;
                newPtr->pre=current;
                newPtr->next->pre=newPtr;
            }
        }
        size++;
        return true;
    }
}				// insert an integer after the i_th position

template <typename T>
bool Link_List<T>::delete_node(int index)
{
    if(index>size||head==tail)
        return false;
    else if(index==size)
    {
        delete_node();
        return true;
    }
    else if(index==1)
    {
        Int_Node<T> *temp=head;
        if(size==1)
            head=tail=nullptr;
        else
        {
            head=head->next;
            delete temp;
        }
        size--;
        return true;
    }
    else
    {
        Int_Node<T> *current=new Int_Node<T>;
        current=head;
        Int_Node<T> *newptr=new Int_Node<T>;
        for(int i=1; i<index; i++)
        {
            newptr=current;
            current=current->next;
        }
        newptr->next=current->next;
        newptr->next->pre=newptr;
        delete current;
        size--;
        return true;
    }
}
// delete the i_th node

#endif // LINK_LIST


