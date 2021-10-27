#include <iostream>

using namespace std;




string days[7]={ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};




int month(int i, int year);
int firstdayofthemonth(string firstday, string days[]);
void calender(int year, int **dates, int &row);
void calenderprint(int **dates, int &beginning, int year);

int main()
{
    int year; string firstday;
    cout<<"Input year: ";
    cin>>year;
    cout<<"Input first day of the year: ";
    cin>>firstday;

    int beginning=firstdayofthemonth(firstday, days);
    int row=12;
    int **dates= new int*[row];

    calender(year, dates, row);
    calenderprint(dates, beginning, year);


    return 0;
}


int firstdayofthemonth(string firstday, string days[])
{
    for(int i=0; i<7; i++)
    {
        if(firstday==days[i])
            return i;
    }
}


int month(int i, int year)
{
    if(i==0 || i==2 || i==4 || i==6 || i==7 || i==9 || i==11)
        return 31;
    else if(i==1)
    {
        if(year%4==0)
            return 29;
        else
            return 28;
    }
    else
        return 30;
}



void calender(int year, int **dates, int &row)
{
    for(int i=0; i<row; i++)
    {
       dates[i]=new int[month(i,year)];
       for(int j=0; j<month(i,year); j++)
            dates[i][j]=j+1;
    }

}





void calenderprint(int **dates, int &beginning, int year)
{
    string shortdays[7]={ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

     for(int i=0; i<12; i++)
    {
        int counter=0;
        if(beginning==7)
            beginning=0;

        cout<<endl<<"\t\t----"<<months[i]<<"----"<<endl;

        for(int m=0; m<7; m++)
        {
            cout<<shortdays[m]<<"\t";
        }
        cout<<endl;

            for(int j=0; j<6; j++)
            {
                    for(int k=0; k<7; k++)
                    {
                        if(j==0 && k<beginning)
                        {
                            cout<<"  \t";

                        }
                        else if(j==0 && k>=beginning)
                        {
                            cout<<dates[i][counter]<<"  \t";
                            counter++;
                        }
                        else if(j>0)
                        {
                            if(month(i,year)>counter)
                            {
                                if(dates[i][j]<10)
                                    {
                                        cout<<dates[i][counter]<<"  \t";
                                        counter++;
                                    }
                                else
                                    {
                                        cout<<dates[i][counter]<<"  \t";
                                        counter++;

                                    }
                                    beginning=k+1;

                            }

                        }
                    }
                    cout<<endl;

            }

    }
}
