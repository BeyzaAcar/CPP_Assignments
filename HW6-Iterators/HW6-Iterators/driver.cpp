#include "PFArray.hpp"
#include "Iterator.hpp" 

using namespace std;

int main()
{
    GTU::PFArray<int> pf_obj(2);
    cout<<"container is created\nI set the initial size of the container to 2.\nThe container will be checked if its empty or not  with empty function:  \n";
    cout<<endl<<"-----------------------------------------------------"<<endl;
    sleep(3);
    if(pf_obj.empty()) cout<<"the container is empty"<<endl;
    else cout<<"the container is not empty";
    cout<<"Each time the container needs to expand, its capacity will be doubled."<<endl;
    cout<<"I will add 10 elements and print them."<<endl;
    cout<<"The elements I will add in order are: 1,2,3,5,4,7,6,8,9,10."<<endl;
    cout<<endl<<"-----------------------------------------------------"<<endl;
    sleep(3);
    pf_obj.add(1);
    pf_obj.add(2.5);
    pf_obj.add(3);
    pf_obj.add(5);
    pf_obj.add(4);
    pf_obj.add(7);
    pf_obj.add(6);
    pf_obj.add(8);
    pf_obj.add(9);
    pf_obj.add(10);

    pf_obj.print();
    
    cout<<endl<<"-----------------------------------------------------"<<endl;
    sleep(3);
    
    cout<<"the container will be sorted with std::sort function , latest version of the container is :"<<endl;
    sort(pf_obj.begin(), pf_obj.end());
    pf_obj.print();
    cout<<endl<<"-----------------------------------------------------"<<endl;
    sleep(3);
    cout<<"Now, element with value 5 will be searched in container."<<endl;
    Iterator<int> it;
    it = find(pf_obj.begin(), pf_obj.end(), 5);
    if(it == pf_obj.end())
    {
        cout<<"There is not such an element"<<endl;
    }
    else cout<<"element is found"<<endl;
    cout<<endl<<"-----------------------------------------------------"<<endl;
    sleep(3);

    cout<<"Now, element with value 11 will be searched in container."<<endl;
    Iterator<int> it2;
    it2 = find(pf_obj.begin(), pf_obj.end(), 11);
    if(it2 == pf_obj.end())
    {
        cout<<"There is not such an element"<<endl;
    }
    else cout<<"element is found"<<endl;
    cout<<endl<<"-----------------------------------------------------"<<endl;
    sleep(3);
    
    cout<<"Now, element with value 5 will be deleted and the container will be printed after that"<<endl;
    pf_obj.erase(5);
    pf_obj.print();
    cout<<endl<<"-----------------------------------------------------"<<endl;
    sleep(3);
    cout<<"Now, I'll try index operator []\n";
    cout<<"pf_obj[5] = "<<pf_obj[5]<<endl;
    cout<<endl<<"-----------------------------------------------------"<<endl;
    sleep(3);
    cout<<"Now we will try to access a cell in memory that we don't have permission to access (handled with try catch )"<<endl;
    sleep(3);
    cout<<"pf_obj[100] = "<<pf_obj[100]<<endl;
    cout<<endl<<"-----------------------------------------------------"<<endl;
    sleep(3);
    return 0;

}
