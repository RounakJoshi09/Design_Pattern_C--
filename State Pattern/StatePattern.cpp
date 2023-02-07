#include<bits/stdc++.h>
using namespace std;
class Tool{
    public:
    virtual void mouseUp() = 0;
    virtual void mouseDown() = 0;
};
class SelectionTool:public Tool{
     void mouseUp()
     {
        cout<<"Selection Tool Selected"<<endl;
     }
     void mouseDown()
     {
        cout<<"Select the Area"<<endl;
     }

};
class CursorTool :public Tool{
    void mouseUp()
    {
        cout<<"Cursor Tool Selected"<<endl;
    }
    void mouseDown()
    {
        cout<<"Draw a line"<<endl;
    }
};

class Canvas{
    public:
    Tool* currentTool;
    Canvas(Tool* tool)
    {
        currentTool = tool;
    }
    void mouseUp()
    {
        currentTool->mouseUp();
    }
    void mouseDown()
    {
        currentTool->mouseDown();
    }
    


};

int main()
{
    Canvas canvas =  Canvas(new CursorTool());
        canvas.mouseUp();
        canvas.mouseDown();
        canvas = Canvas(new SelectionTool());
        canvas.mouseUp();
        canvas.mouseDown();
}
