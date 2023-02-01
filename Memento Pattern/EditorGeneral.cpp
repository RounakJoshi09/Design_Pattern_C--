#include <bits/stdc++.h>
using namespace std;
class Editor
{
private:
    string content;
    int ind;
    vector<string> contentList;

public:
    Editor()
    {
        ind = 0;
    }
    void setContent(string content)
    {
        contentList.push_back(content);
        ind++;
        this->content = content;
    }
    string getContent()
    {

        return content;
    }

    void undo()
    {
        ind--;
        setContent(contentList[ind - 1]);
    }
};
int main()
{
    Editor editor = Editor();
    editor.setContent("Hello World");
    editor.setContent("Rounak");
    cout<<editor.getContent()<<endl;
    editor.undo();
    editor.setContent("Joshi");
    editor.setContent("is my Boy");
    cout<<editor.getContent()<<endl;
}