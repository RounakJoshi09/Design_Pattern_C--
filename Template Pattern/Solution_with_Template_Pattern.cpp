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
    private:
    AuditTrail auditTrail;
    protected:
     void virtual doExecute() = 0;
     
    public:
    Task(AuditTrail auditTrail)
    {
        this->auditTrail = auditTrail;
    }
   void executeTask(){
        auditTrail.record();
        doExecute();
    }
     
};
class GenerateReport:public Task{
    public:
    GenerateReport(AuditTrail auditTrail):Task(auditTrail){
    }
    
    void doExecute()
    {
        cout<<"Generate Report"<<endl;
    }
};
int main()
{
    AuditTrail auditTrail = AuditTrail();
    GenerateReport generateReport =  GenerateReport(auditTrail);
    generateReport.executeTask();
}