void reduceDuplicate(Node* root)
{
    Node* curr = root;
    while (curr->getNext()){
        Node* check = curr->getNext();
        if(curr->getData() == check->getData()){
            while(curr->getData() == check->getData()){
                //Node* temp = check;
                curr->setNext(check->getNext());
                check = check->getNext();
                //delete temp;
                if(check == NULL)
                    break;
                else check = curr->getNext();
            }
        }
        if(check == NULL)
            break;
        else
            curr = curr->getNext();
    }
}

#include <iostream>
#include <list>
#include <string>
using namespace std;

class PrinterQueue
{
    public: 
        class Request{
            public:
            string fileName;
            int priority;
            
            public:
            Request(): fileName("No file to print"), priority(-1){}
    
            Request(string fileName, int priority)
            {
                this->fileName = fileName;
                this->priority = priority;
            }

        };
    // your attributes
    std::list<Request> qu;
    
public:
    // your methods

    void addNewRequest(int priority, string fileName)
    {
        // your code here
        Request temp = Request(fileName, priority); 
        qu.push_front(temp);
        qu.sort([](const Request &f, const Request &s) { return f.priority < s.priority; });
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline
      if(qu.empty()){
        cout << "No file to print" << endl;
        return;  
      }
      cout << qu.back().fileName << endl;
      qu.pop_back();
    }
    void In()
    {
        // your code here
        // After some logic code, you have to print fileName with endline
      if(qu.empty()){
        cout << "No file to print" << endl;
        return;  
      }
      std::list<Request>::iterator it;
      for (it=qu.begin(); it!=qu.end(); ++it)
      std::cout << ' ' << it->fileName;
      std::cout << '\n';
    }
};