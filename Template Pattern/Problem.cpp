#include<bits/stdc++.h>
using namespace std;
class AuditTrail{
    public:
    void record()
    {
        cout<<"Data Recorded"<<endl;
    }
};
class GenerateReport{

    private:
    AuditTrail auditTrail;
    public:

    GenerateReport(AuditTrail auditTrail)
    {
        this->auditTrail = auditTrail;
    }

    void generate()
    {
        auditTrail.record();
        cout<<"Generating Report \n Report Generated"<<endl;

    }
};
class ExecuteTransaction{

    private:
    AuditTrail auditTrail;
    public:

    ExecuteTransaction(AuditTrail auditTrail)
    {
        this->auditTrail = auditTrail;
    }

    void execute()
    {
        auditTrail.record();
        cout<<"Executing Transaction \n Transaction Executed"<<endl;
    }
};
int main()
{

}