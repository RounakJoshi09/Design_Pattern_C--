#include<bits/stdc++.h>
using namespace std;
class EditorState{

    string content;
    public:

    EditorState(string content)
    {
        this->content = content;
    }
    string getContent()
    {
        return content;
    }
    
};
class History{

    stack<EditorState> stk;
    public:
    void push(EditorState editorState)
    {
        stk.push(editorState);
    }

    EditorState pop()
    {
           stk.pop();
        EditorState editorState = stk.top();
     
        return editorState;
    }
};
class Editor{
    string content;

    public:

    EditorState createState()
    {
        return  EditorState(content);
    }
    void restoreState(EditorState editorState)
    {
        this->content = editorState.getContent();
    }
    void setContent(string content)
    {
        this->content = content;
    }

    string getContent()
    {
        return content;
    }
    
};
int main()
{
    Editor editor =  Editor();
    History history = History();
    editor.setContent("Hello");
    history.push(editor.createState());
    editor.setContent("World");
    history.push(editor.createState());
    cout<<editor.getContent()<<endl;
    editor.restoreState(history.pop());
    cout<<editor.getContent()<<endl;
}