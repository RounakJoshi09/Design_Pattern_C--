#include<bits/stdc++.h>
using namespace std;
class Command{
    public:
    void virtual execute() = 0;
};
class CustomerService{
    public:
    
    void addCustomer()
    {
        cout<<"Added Customer Successfully"<<endl;
    }
};
class AddCustomerCommand:public Command{
    private:
    CustomerService customerService;

    public:
    AddCustomerCommand(CustomerService customerService)
    {
        this->customerService = customerService; 
    }
    void execute()
    {
        customerService.addCustomer();
    }
};

class Button{
private:
string label;
Command* command;
public:
Button(string label,Command* command)
{
    this->label = label;
    this->command  = command;
}
void click()
{   
    command->execute();
    //This should be according to different method commands
}

};
int main()
{
    CustomerService customerService = CustomerService();
    AddCustomerCommand* command = new AddCustomerCommand(customerService);
    Button button =  Button("Button",command);
    button.click();
}