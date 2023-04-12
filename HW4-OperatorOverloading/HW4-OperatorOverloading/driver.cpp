#include"DayOfYearSet.hpp"

using namespace std;

int main()
{
    char wait;
    GTU::DayOfYearSet::DayOfYear d1(6,18), d2(5,12), d3(8,26), d4(8,26), d5(1,1), d6(2, 24), d7(4,20);
    GTU::DayOfYearSet obj({d1, d2, d3}), obj2({d4, d5});
    GTU::DayOfYearSet obj3({d4, d5});
    cout<<"first, you are going to see << operator"<<endl<<"first set is :"<<endl;
    cout<<obj<<endl<<"and the second set is : "<<endl<<obj2<<endl<<"the third set is :"<<endl<<obj3<<endl;
    cout<<"Please enter a character to continue";
    cin>>wait;

    cout<<"OPERATOR == and OPERATOR !="<<endl<<"set1 == set2 : ";
    if(obj == obj2) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    cout<<"set2 == set3 : ";
    if(obj2 == obj3) cout<<"true "<<endl;
    else cout<<"false"<<endl;
    cout<<"set1 != set2 : ";
    if(obj != obj2) cout<<"true "<<endl;
    else cout<<"false"<<endl;
    cout<<"set2 != set3 : ";
    if(obj2 != obj3) cout<<"true "<<endl;
    else cout<<"false"<<endl;
    cout<<"Please enter a character to continue";
    cin>>wait;

    cout<<"REMOVE FUNCTION "<<endl<<"remove May 12th from the first set "<<endl<<"first set1 : "<<endl<<obj;
    obj.remove(5,12);
    cout<<endl<<"last set 1 : "<<obj<<endl;
    cout<<"remove June 18th from the first set"<<endl<<"first set1  : "<<obj<<endl;
    obj.remove(6,18);
    cout<<endl<<"last set 1 : "<<obj<<endl;
    cout<<"Please enter a character to continue";
    cin>>wait;

    cout<<endl<<"SIZE FUNCTION : "<<endl<<"size of set1 = "<<obj.Size()<<endl<<"size of the set2 = "<<obj2.Size()<<endl;
    cout<<"Please enter a character to continue";
    cin>>wait;

    cout<<endl<<"------------- OPERATOR + (adds an element) -------------"<<endl<<"adding February 24th to set2"<<endl<<"first set2 : "<<obj2<<endl;
    obj2 = obj2 + d6;
    cout<<"last set 2 : "<<obj2<<endl;
    cout<<"adding March 20th to set3"<<endl<<"set3 : "<<obj3;
    obj3 = obj3 + d7;
    cout<<"last set3 : "<<obj3;
    cout<<"Please enter a character to continue";
    cin>>wait;

    cout<<"------------- OPERATOR - (remove an element) we already did that with remove------------- "<<endl;
    cout<<"Please enter a character to continue";
    cin>>wait;

    cout<<endl<<"------------- OPERATOR + (returns the union of sets) -------------"<<endl<<"set1 and set2(in order) "<<endl<<obj<<obj2<<"union of set1 and set2  : "<<endl<<obj+obj2<<endl;
    cout<<"Please enter a character to continue";
    cin>>wait;
    cout<<endl<<"set2 and set3 : (in order)"<<endl<<obj2<<obj3<<"union of set2 and set 3 : "<<obj2+obj3<<endl;
    cout<<"Please enter a character to continue";
    cin>>wait;

    cout<<"------------- OPERATOR - (returns the difference set) -------------"<<endl<<"set1 and set2(in order) "<<endl<<obj<<obj2<<"difference of set1 and set2 ..: "<<endl<<obj-obj2;
    cout<<"Please enter a character to continue";
    cin>>wait;
    cout<<endl<<"set2 and set3 : (in order)"<<endl<<obj2<<obj3<<"difference of set2 and set3 .. "<<obj2-obj3<<endl;
    cout<<"Please enter a character to continue";
    cin>>wait;

    cout<<"------------- OPERATOR ^ (returns the intersect of sets) -------------"<<endl;
    cout<<"set1 and set2(in order) "<<endl<<obj<<obj2;
    cout<<"the intersect of set1 and set2 .. : "<<endl;
    cout<<(obj^obj2);
    cout<<"Please enter a character to continue";
    cin>>wait;
    cout<<"set2 and set3(in order) "<<endl<<obj2<<obj3;
    cout<<"the intersect of set2 and set3 .. : "<<endl;
    cout<<(obj2^obj3);
    cout<<"Please enter a character to continue";
    cin>>wait;

    cout<<"------------- OPERATOR ! (returns the complement set ) -------------"<<endl<<"set1 = "<<obj;
    cout<<"Please enter a character to continue";
    cin>>wait;
    cout<<"the complement of set1 ..: "<<!obj<<endl;
    cout<<"Please enter a character to continue";
    cin>>wait;
    cout<<"set2  = "<<obj2;
    cout<<"Please enter a character to continue";
    cin>>wait;
    cout<<"the complement of set2 ..:"<<!obj2<<endl;
    cout<<"Please enter a character to continue";
    cin>>wait;

    cout<<"------------- OPERATOR [] (returns the element at given position(index)) -------------"<<endl<<"the second element in the set3 is .. :"<<obj3[1].get_month()<<"."<<obj3[1].get_day()<<endl;
    cout<<"first element of set2 is ...:" <<obj2[0].get_month()<<"."<<obj2[0].get_day()<<endl;

    return 0;
}
