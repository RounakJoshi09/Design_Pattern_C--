#include<bits/stdc++.h>
using namespace std;
class ImageCompression{
public:
    string compression;
    string filter;
    ImageCompression()
    {
        this->compression = compression;
        this->filter = filter;
    }
void store(string fileName)
{
    if(compression == "jpeg")
    {
        cout<<"Applying JPEG Algorithm"<<endl;
    }
    else if(compression == "png")
    {
        cout<<"Applying PNG Algorithm"<<endl;
    }

    if(filter == "B&W")
    {
        cout<<"Applying B&W Filter"<<endl;
    }
    else if(filter == "High Contrast")
    {
        cout<<"Applying High Contrast Filter"<<endl;
    }
}
};
int main()
{

}