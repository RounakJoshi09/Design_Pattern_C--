#include<bits/stdc++.h>
using namespace std;
class Observerable{
    public:
    void virtual update(int value) = 0;
};
class SpreadSheet: public Observerable{
    public:
    void update(int value)
    {
        cout<<"SpreadSheet Got Notified "<<value<<endl;
    }
};
class PieChart: public Observerable{
    public:
    void update(int value)
    {
        cout<<"PieChart got notified "<<value<<endl;
    }
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
    void notifyListener(int val)
    {
        for(auto x:observables)
        {
            x->update(val);
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
        notifyListener(value);
    }

};
int main()
{
    SpreadSheet* spreadSheet1 = new SpreadSheet();
    SpreadSheet* spreadSheet2 = new SpreadSheet();
    PieChart* pieChart = new PieChart();
    DataSource dataSource = DataSource();
    dataSource.addObservable(spreadSheet1);
    dataSource.addObservable(spreadSheet2);
    dataSource.addObservable(pieChart);
    dataSource.set(5);
}