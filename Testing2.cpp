#include<iostream>
using namespace std;

class Sol{
    int real,comp;
    public:
    
        Sol(int a,int b){
            real=a;
            comp=b;
        }
        void addn(Sol o){
            cout<<this->real+o.comp;
        }
        void sub(Sol o){
        	cout<<this->real-o.comp;
		}
		void product(Sol o){
			cout<<this->real*o.real-this->comp*o.comp;
		}
};
int main()
{
	Sol ob(2,3),o(5,6);
	ob.addn(o);
	ob.sub(o);
	ob.product(o);
}