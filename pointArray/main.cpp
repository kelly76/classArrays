#include <iostream>

using namespace std;

class point{
private:
    int x,y;
public:
    point();
    point(int,int);
    int get_x();
    int get_y();
    point operator + (point p);
};

point::point(){
x=0;y=0;}

point::point(int _x,int _y){
x=_x; y=_y;}

int point::get_x(){
return x;}

int point::get_y(){
return y;}

std::ostream& operator << (std::ostream& output,point& p){   //imprimir puntos
output << "(" << p.get_x() << "," << p.get_y() << ")";
return output;
}

point point::operator + (const point p){    //sumar puntos
point result;
result.x= (this->x + p.x);
result.y= (this->y + p.y);
return result;
}

class pointArray{      //clase: arreglo de puntos
private:
    point *arrP;
    int s;
public:
    pointArray();
    pointArray(point p[],int _s);
    ~pointArray();
    pointArray(pointArray &o);
    void pushBack(const point &p);
    void insert(const point p,int pos);
    void remove(int pos);
    void printArray();
};

pointArray::pointArray(){
s=0;
arrP=new point[s];
}

pointArray::pointArray(point p[],int _s){
this->s=_s;
arrP=new point[s];
for(int i=0;i<s;i++){
	arrP[i]=p[i];}
}

pointArray::pointArray(pointArray &o){
arrP=new point[o.s];
for(int i=0;i<s;i++)
    arrP[i]=o.arrP[i];
}

pointArray::~pointArray(){
delete[] arrP;
}

void pointArray::insert(const point p,int pos){
this->s+=1;
point *new_arrP=new point[s];
for(int i=0;i<s;i++)
    new_arrP[i]=arrP[i];
delete[] arrP;
arrP=new_arrP;
for(int j=s-1;j>pos;j--)
    arrP[j]=arrP[j-1];
arrP[pos]=p;
}

void pointArray::remove(int pos){
for(int j=pos;j<s-1;j++)
    arrP[j]=arrP[j+1];
this->s-=1;
point *new_arr1=new point[s];
for(int i=0;i<s;i++)
    new_arr1[i]=arrP[i];
delete[] arrP;
arrP=new_arr1;
}

void pointArray::pushBack(const point &p){
this->s+=1;
point *new_arr=new point[s];
for(int i=0;i<s;i++)
    new_arr[i]=arrP[i];
new_arr[s-1]=p;
delete[] arrP;
arrP=new_arr;
}

void pointArray::printArray(){
for(int i=0;i<s;i++)
    cout<<arrP[i]<<" ";
cout<<endl;
}

int main()
{
    point p(4,2);
    point c(4,5);
    point x=p+c;    //suma de puntos
    cout<<x<<endl;

    point A[]={p,c};
    pointArray arrPo(A,2);    //arreglo de puntos
    arrPo.printArray();

    point r(1,2);
    arrPo.insert(r,1);
    arrPo.printArray();

    arrPo.remove(1);
    arrPo.printArray();

return 0;
}
