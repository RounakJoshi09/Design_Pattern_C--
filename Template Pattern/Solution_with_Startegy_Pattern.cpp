#include<bits/stdc++.h>
using namespace std;
class AuditTrail{
    public:
    void record()
    {
        cout<<"Data Recorded"<<endl;
    }
};
class Task{
    public:
    virtual void execute() = 0;
};

class GenerateReport:public Task{
    public:
    void execute()
    {
        cout<<"Generate Report"<<endl;
    }

};
class ExecuteTransanction:public Task{
    public:
    void execute()
    {
        cout<<"Execute Transaction"<<endl;
    }
};
class TaskExecutor{
    private:
    AuditTrail auditTrail;
    Task* task;
    public:
    TaskExecutor(AuditTrail auditTrail,Task* task)
    {
        this->auditTrail = auditTrail;
        this->task = task;
    } 

    void executeTask()
    {
        auditTrail.record();
        task->execute();
    }

};
int main()
{
    AuditTrail auditTrail = AuditTrail();
    TaskExecutor taskExecutor = TaskExecutor(auditTrail,new GenerateReport());
    taskExecutor.executeTask();
}
