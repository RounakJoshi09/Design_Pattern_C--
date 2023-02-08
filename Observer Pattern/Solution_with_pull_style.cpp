#include<bits/stdc++.h>
using namespace std;
class Observerable{
    public:
    void virtual update() = 0;
};
class Subject{
    private:
    vector<Observerable*> observables;
    public:
    void addObservable(Observerable* obs)
    {
        observables.push_back(obs);
    }
    void remove(Observerable* obs)
    {
        int i=0;
        for(i=0;i<observables.size();i++)
        {
            if(observables[i] == obs)
            {
                break;
            }
        }
        for(int j = i;j<observables.size()-1;j++)
        {
            swap(observables[j],observables[j+1]);
        }
    }
    void notifyListener()
    {
        for(auto x:observables)
        {
            x->update();
        }
    }
};
class DataSource : public Subject{
    private:
    int value;
    public:
    int get()
    {
        return value;

    }
    void set(int val)
    {
        this->value = val;
        notifyListener();
    }

};

class SpreadSheet: public Observerable{
    private:
    DataSource dataSource;
    public:
    SpreadSheet(DataSource dataSource)
    {
        this->dataSource = dataSource;
    }
    void update()
    {
        cout<<"SpreadSheet Got Notified "<<dataSource.get()<<endl;
    }
};
class PieChart: public Observerable{
    private:
    DataSource dataSource;
    public:
    PieChart(DataSource dataSource)
    {
        this->dataSource = dataSource;
    }
    void update()
    {
        cout<<"PieChart got notified "<<dataSource.get()<<endl;
    }
};

int main()
{
    DataSource dataSource = DataSource();
    SpreadSheet* spreadSheet1 = new SpreadSheet(dataSource);
    SpreadSheet* spreadSheet2 = new SpreadSheet(dataSource);
    PieChart* pieChart = new PieChart(dataSource);
    dataSource.addObservable(spreadSheet1);
    dataSource.addObservable(spreadSheet2);
    dataSource.addObservable(pieChart);
    dataSource.set(8);
}