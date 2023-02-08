#include<bits/stdc++.h>
using namespace std;
class Compression
{
    public:
    virtual void compress() = 0;
};

class JpegCompressor:public Compression
{
    public:
    void compress()
    {
        cout<<"Compressing using JPEG Compressor"<<endl;
    }
};
class PngCompressor:public Compression
{
    public:
    void compress()
    {
        cout<<"Compressing using PNG Compressor"<<endl;
    }
};

class Filter{
    public: 
    virtual void apply() = 0;
    
};

class BlackAndWhite:public Filter{

    public:
    void apply()
    {
        cout<<"Applying Black and White Filter"<<endl;
    }
};
class HighContrast :public Filter{
    public:
    void apply()
    {
        cout<<"Applying High Contrast Filter"<<endl;
    }
};
class ImageStore
{
    public:
    // Compression* compression;
    // Filter* filter;

    void storeImage(string fileName,Compression* compression,Filter* filter)
    {
        compression->compress();
        filter->apply();

    }
};
int main()
{
    ImageStore imageStore =  ImageStore();
    imageStore.storeImage("Hello World",new JpegCompressor(),new HighContrast());
    imageStore.storeImage("Hare Krsna",new PngCompressor(),new BlackAndWhite());

}