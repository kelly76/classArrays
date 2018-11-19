#include <iostream>

using namespace std;

class polygon{
protected:
    int w,h;
public:
    polygon(int a=0, int b=0):w(a),h(b){}
    virtual int area(){};
    void printarea(){
    cout<<this->area()<<endl;
    }
    int get_w(){return w;}
    int get_h(){return h;}
    friend std::ostream& operator << (std::ostream& output,polygon& p);
};

class triangulo : public polygon{
public:
    triangulo(int a,int b):polygon(a,b){}
    int area(){ return (w*h)/2;}
};


class rectangulo:public polygon{
public:
rectangulo(int a,int b):polygon(a,b){}
int area(){return w*h;}
};

class pArray{
    polygon *arr;
    int size;
public:
    pArray();
    pArray(const polygon p[],int s);
    pArray(pArray &o);
    ~pArray();
    void pushBack(const polygon &p);
    void insert(polygon &p,int pos);
    void remove(int pos);
    void printArray();
};

pArray::pArray(){
size=0;
arr=new polygon[size];
}

pArray::pArray(const polygon p[],int s){
this->size=s;
arr=new polygon[size];
for(int i=0;i<size;i++){
	arr[i]=p[i];}
}

pArray::pArray(pArray &o){
arr=new polygon[o.size];
for(int i=0;i<size;i++)
    arr[i]=o.arr[i];
}

pArray::~pArray(){
delete[] arr;
}

void pArray::insert(polygon &p,int pos){
size+=1;
polygon *new_arr=new polygon[size];
for(int i=0;i<size;i++)
    new_arr[i]=arr[i];
delete[] arr;
arr=new_arr;
for(int j=size-1;j>pos;j--)
    arr[j]=arr[j-1];
arr[pos]=p;
}

void pArray::remove(int pos){
for(int j=pos;j<size-1;j++)
    arr[j]=arr[j+1];
size-=1;
polygon *new_arr1=new polygon[size];
for(int i=0;i<size;i++)
    new_arr1[i]=arr[i];
delete[] arr;
arr=new_arr1;
}

void pArray::pushBack(const polygon &p){
this->size+=1;
polygon *new_arr=new polygon[size];
for(int i=0;i<size;i++)
    new_arr[i]=arr[i];
new_arr[size-1]=p;
delete[] arr;
arr=new_arr;
}

std::ostream& operator << (std::ostream& output,polygon& p){
output << "(" << p.get_w() << "," << p.get_h() << ")";
return output;
}

void pArray::printArray(){
for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
cout<<endl;
}

int main(){
/*
triangulo r(2,4);
polygon &ref=r;
ref.printarea();*/

polygon x(4,6);
polygon y(2,4);
polygon poly[]={x,y};     //arreglo de poligonos
pArray arrPoly(poly,2);

arrPoly.printArray();

polygon z(5,9);
arrPoly.insert(z,1);
arrPoly.printArray();

return 0;

}

