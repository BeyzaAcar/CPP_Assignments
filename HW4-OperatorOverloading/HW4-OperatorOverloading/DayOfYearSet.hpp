#ifndef _DAYOFYEARSET_HPP
#define _DAYOFYEARSET_HPP

#include <iostream>
#include <initializer_list>

using namespace std;

namespace  GTU
{   
    class DayOfYearSet
    {
        public:
            class DayOfYear
            {
                private : 
                    int month;
                    int day;
                public:
                    DayOfYear(int, int);
                    DayOfYear();
                    
                    int get_month() const; 
                    int get_day() const;
                    
                    void set_day(const int);
                    void set_month(const int);
            };
            DayOfYearSet(const initializer_list<DayOfYear>&);
            DayOfYearSet();
            ~DayOfYearSet();

            DayOfYear* get_days_ptr() const;
            int Size() const;

            friend ostream& operator<< (ostream&, const DayOfYearSet&)/*will print DayofYearSet details*/;
            bool operator== (const DayOfYearSet&) const;  /*for comparing DayofYearSet objects.*/
            bool operator!= (const DayOfYearSet&) const;  /*regardless of the keeping order*/
            DayOfYearSet& operator= (const DayOfYearSet); /*for assigning DayOfYearSet object to an other DayOfYearSet object*/
            DayOfYearSet operator+(const DayOfYearSet)const; /*returns the union set*/
            DayOfYearSet& operator+(const DayOfYear&);  /*adds an element to the set*/
            DayOfYearSet operator-(const DayOfYearSet);  /*returns the difference set*/
            DayOfYearSet& operator-(const DayOfYear&);  /*removes an element from the set*/
            DayOfYearSet operator^(const DayOfYearSet);  /*returns the intersection set*/
            DayOfYearSet operator!(void);  /*returns the complement set*/
            DayOfYear& operator[](int) const;  /*returns the element at given position*/
            DayOfYearSet(const DayOfYearSet&);
            void remove(int, int);
            
            void set_size(int);

        private:
            DayOfYear* days_ptr;
            int size;
    };
}

#endif
