#include<iostream>
using namespace std;
template<class x>
class ArrayADT
{
    private:
        x *p;
        int lastIndex;
        int capacity;
   public:
    ArrayADT()
    {
        int capacity;
        cout<<"Enter size of Array"<<endl;
        cin>>capacity;
       this->capacity=capacity;
       lastIndex=-1;
       p=new x[capacity];
    }
    void Append(x data)
    {
        if(lastIndex==capacity-1)
        cout<<"Overflow"<<endl;
        else 
        {
            lastIndex+=1;
            p[lastIndex]=data;
        }
    }
    int Count()
    {
        if(lastIndex==-1)
        cout<<"Underflow"<<endl;
        return lastIndex+1;
    }
    x GetItem(int index)
    {
        if(index <0 || index > lastIndex)
        
        {
            cout<<"\nInvalid Index for geting"<<endl;
            return -1;
        }
        else 
            return p[index];
    }
    void Edit(x data, int index)
    {
          if(index <0 || index > lastIndex)
        cout<<"\nInvalid Index for edit "<<endl;
        else
        {
            p[index]=data;
        }
    }
    int  Search(x item)
    {
     for(int i=0;i<capacity;i++)
     if(p[i]==item)
     return i;
     return -1;
    } 
    void Insert(x data, int index)
    {
        if(index<0 || index>lastIndex)
        cout<<"\nInvallid Index for insertion "<<endl;
        else if(capacity==lastIndex+1)
        cout<<"Overflow"<<endl;
        else
        {
            lastIndex=lastIndex+1;
          for(int i=lastIndex;i>index;i--)
          {
              p[i]=p[i-1];
          }
          p[index]=data;
        }
       
    }
    void Delete( int index)
    {
       if(index<0 || index>lastIndex)
       cout<<"\n Invalid Index for deleltion"<<endl;
       else
       {
          for(int i=index;i<lastIndex;i++)
          {
            p[i]=p[i+1];
          }
          lastIndex=lastIndex-1;
       }
    }
    void view()
    {
        cout<<endl;
        if(lastIndex==-1)
        cout<<"Array is Empty"<<endl;
        else 
        {
            for(int i=0;i<=lastIndex;i++)
            cout<<p[i]<<" ";
            cout<<endl;
        }
    }
};
int main()
{
    class ArrayADT<int> arr;
     arr.Append(10);
     arr.Append(20);
     arr.Append(30);
     arr.Append(40);
   arr.Insert(990,3);
   arr.Insert(99,0);
   arr.Delete(3);
     arr.view();
     cout<<"\n Totaaly Item :"<<arr.Count();
      cout<<"\n UR item is :"<<arr.GetItem(2);
      cout<<"\n Ur item is :"<<arr.GetItem(3);
      arr.Edit(100,3);
      arr.Edit(200,4);
      arr.Delete(0);
       arr.view();
       cout<<"\n Ur item after searching "<<arr.Search(20);
       cout<<"\n Ur item After searching is :"<<arr.Search(3);
       arr.Delete(1);
       arr.view();
 return 0;        
}