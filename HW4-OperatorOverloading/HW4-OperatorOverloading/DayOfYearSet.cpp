#include"DayOfYearSet.hpp"

using namespace std;

//Constructers :
GTU::DayOfYearSet::DayOfYear::DayOfYear(int m, int d)
{
    if(((m == 4 || m == 6 || m == 9 || m == 11) && d>30) || (m == 2 && d>29) || ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 ) && d>31))
    {
        cout<<"invalid input"<<endl;
    }
    else
    {
        month = m;
        day = d;
    }
}
GTU::DayOfYearSet::DayOfYear::DayOfYear()
{
    month = 0;
    day = 0;
}
GTU::DayOfYearSet::DayOfYearSet(const initializer_list<DayOfYear>& set)
{
    int count = 0;
    size = set.size();
    days_ptr = new DayOfYear[size];
    for(auto i = set.begin(); i!= set.end();i++)
    {
        days_ptr[count] = *i;
        count++;
    }
}
GTU::DayOfYearSet::DayOfYearSet()
{
    size = 0;
    days_ptr = nullptr;
}
GTU::DayOfYearSet::DayOfYearSet(const DayOfYearSet& obj)
{
    int i;
    this->size = obj.Size();
    days_ptr = new DayOfYear[size];
    for(i=0;i<size;i++)
    {
        days_ptr[i].set_day(obj.days_ptr[i].get_day());
        days_ptr[i].set_month(obj.days_ptr[i].get_month());
    }
}

//Destructor :
GTU::DayOfYearSet::~DayOfYearSet()
{
    if(days_ptr != nullptr)
    	delete [] days_ptr;
    days_ptr = nullptr;
}

//Getters :
int GTU::DayOfYearSet::DayOfYear::get_day() const
{
    return day;
}
int GTU::DayOfYearSet::DayOfYear::get_month() const
{
    return month;
}
GTU::DayOfYearSet::DayOfYear* GTU::DayOfYearSet::get_days_ptr() const
{
    return days_ptr;
}
int GTU::DayOfYearSet::Size() const
{
    return size;
}


//Setters :
void GTU::DayOfYearSet::DayOfYear::set_day(const int d)
{
    day = d;
}
void GTU::DayOfYearSet::DayOfYear::set_month(const int m)
{
    month = m;
}
void GTU::DayOfYearSet::set_size(int s)
{
    size = s;
}


//Operators :
namespace GTU
{
    ostream& operator<< (ostream& stream , const GTU::DayOfYearSet& obj)
    {
        int i;
        int hold;
        //stream<<"Dates are :"<<endl;
        for(i=0;i<obj.Size();i++)
        {
            hold = obj.get_days_ptr()[i].get_month();
            if(hold == 1) stream<<"January ";
            else if(hold == 2) stream<<"February ";
            else if(hold == 3) stream<<"March ";
            else if(hold == 4) stream<<"April ";
            else if(hold == 5) stream<<"May ";
            else if(hold == 6) stream<<"June ";
            else if(hold == 7) stream<<"July ";
            else if(hold == 8) stream<<"August ";
            else if(hold == 9) stream<<"September ";
            else if(hold == 10) stream<<"October ";
            else if(hold == 11) stream<<"November ";
            else if(hold == 12) stream<<"December ";
            else stream<<"There is a problem with the month ("<<hold<<") ";
            stream<<(obj.get_days_ptr())[i].get_day()<<"."<<endl;
        }
        stream<<endl<<endl;
        return stream;
    }
}
GTU::DayOfYearSet& GTU::DayOfYearSet::operator=(const GTU::DayOfYearSet obj)
{
    int i;
    this->size = obj.Size();
    delete [] days_ptr;
    days_ptr = new DayOfYear[size];
    for(i=0;i<size;i++)
    {
        days_ptr[i].set_day(obj.days_ptr[i].get_day());
        days_ptr[i].set_month(obj.days_ptr[i].get_month());
    }
    return *this;
}
bool GTU::DayOfYearSet::operator==(const GTU::DayOfYearSet& obj) const
{
    int i,j;
    if(this->size != obj.Size()) return false; /*If their sizes are different, there is no need to check them if they are true*/
    GTU::DayOfYearSet temp = obj;
    for(i=0;i<size;i++) /*The reason there are two nested loops is because I check for equality regardless of order.*/
    {
        for(j=0;j<size;j++)
        {
            if(days_ptr[i].get_day() == obj.get_days_ptr()[j].get_day() && days_ptr[i].get_month() == obj.get_days_ptr()[j].get_month())
            {
                temp.set_size(temp.Size()-1); /*if temp is empty at the end (I do not removing elements just decrease size of temp), that means they are equal sets*/
            }
        }
    }
    if(temp.Size() == 0) return true;
    else return false;

}
bool GTU::DayOfYearSet::operator!=(const GTU::DayOfYearSet& obj) const
{
    if(*this == obj) return false;
    else return true;
}
GTU::DayOfYearSet& GTU::DayOfYearSet::operator+(const DayOfYear& obj)
{
    int i; /*I'm checking whether the  dayofyear element has been repeated */
    for(i=0;i<size;i++)
    {
        if(obj.get_day() == days_ptr[i].get_day() && obj.get_month() == days_ptr[i].get_month())
        {
            //cout<<"this date is already added before"<<endl;
            return *this;
        }
    }
    DayOfYear* temp = new DayOfYear [size+1];
    for(i=0;i<size;i++)
    {
        temp[i].set_day(days_ptr[i].get_day());
        temp[i].set_month(days_ptr[i].get_month());
    }
    temp[size].set_day(obj.get_day());
    temp[size].set_month(obj.get_month());
    
    delete[] days_ptr;

    days_ptr = new DayOfYear[size+1];

    for(i=0;i<size+1;i++)
    {
        days_ptr[i].set_day(temp[i].get_day());
        days_ptr[i].set_month(temp[i].get_month());
    }
    size++;
    delete [] temp;
    return *this;
}
GTU::DayOfYearSet GTU::DayOfYearSet::operator+(const GTU::DayOfYearSet obj) const
{
    int i;
    GTU::DayOfYearSet temp;
    for(i=0;i<obj.Size();i++)
    {
        temp = temp + (obj.get_days_ptr())[i];
    }
    for(i=0;i<size;i++)
    {
        temp = temp + days_ptr[i];
    }
    return temp;
}
GTU::DayOfYearSet& GTU::DayOfYearSet::operator-(const DayOfYear& obj)
{
    this->remove(obj.get_month(), obj.get_day());
    return *this;
}
GTU::DayOfYearSet GTU::DayOfYearSet::operator-(const GTU::DayOfYearSet obj)
{
    int i,j;
    GTU::DayOfYearSet temp;
    temp = *this;
    for(i=0;i<size;i++)
    {
        for(j=0;j<obj.Size();j++)
        {
            if(this->days_ptr[i].get_day() == obj.get_days_ptr()[j].get_day() && this->days_ptr[i].get_month() == obj.get_days_ptr()[j].get_month())
            {
                temp.remove(obj.get_days_ptr()[j].get_month(), obj.get_days_ptr()[j].get_day());
            }
        }
    }
    return temp;
}
GTU::DayOfYearSet GTU::DayOfYearSet::operator^(const GTU::DayOfYearSet obj)
{
    int i,j,count=0;
    GTU::DayOfYearSet temp;
    for(i=0;i<size;i++)
    {
        for(j=0;j<obj.Size();j++)
        {
            if(days_ptr[i].get_day() == obj.get_days_ptr()[j].get_day() && days_ptr[i].get_month() == obj.get_days_ptr()[j].get_month())
            {
                temp = temp + days_ptr[i];
                count++;
            }
        }
    }
    temp.set_size(count);
    return temp;
}
GTU::DayOfYearSet GTU::DayOfYearSet::operator!(void)
{
    int i,j;
    GTU::DayOfYearSet temp_set;
    GTU::DayOfYearSet::DayOfYear temp;
    for(i=1;i<=12;i++)
    {
        for(j=1;j<32;j++)
        {
            if(i==2 && j>29) continue; /*I put these ifs because different months have variable number of days.*/
            if((i==4 || i==6 || i==9 || i==11) && j>30) continue;
            temp.set_day(j);
            temp.set_month(i);
            temp_set = temp_set + temp;
        }
    }
    for(i=0;i<size;i++)
    {
        temp_set.remove(this->days_ptr[i].get_month(), this->days_ptr[i].get_day());
    }
    return temp_set;
}
GTU::DayOfYearSet::DayOfYear& GTU::DayOfYearSet::operator[](int i) const
{
    return days_ptr[i];
}



//Other Functions :
void GTU::DayOfYearSet::remove(int m, int d)
{
    int i, flag=0,shift=0; /*if flag is equal to size, this shows us there is not an element to delete*/
    for(i=0;i<size;i++) /*I'm checking to see if there is an element to delete*/
    {
        if(d!=this->days_ptr[i].get_day() || m!=this->days_ptr[i].get_month()) flag ++;
    }

    if(flag == size)
    {
        cout<<"there is not an element to delete"<<endl;
        return;
    }

    DayOfYear* temp = new DayOfYear[size-1];

    for(i=0;i<size;i++)
    {
        if(days_ptr[i].get_day() != d || days_ptr[i].get_month() != m)
        {
            temp[i-shift].set_day(days_ptr[i].get_day());
            temp[i-shift].set_month(days_ptr[i].get_month());
        }
        else shift = 1;
    }

    delete [] days_ptr;
    days_ptr = new DayOfYear[size-1];
    this->set_size(size-1); //I am decreasing size by one because of removing an element from the set

    for(i=0;i<size;i++)
    {
        days_ptr[i].set_day( temp[i].get_day() );
        days_ptr[i].set_month( temp[i].get_month() );
    }
    delete [] temp;
}

