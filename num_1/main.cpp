#include <iostream>
using namespace std;

class encoder{
    unsigned char *massive;
    int size_massive;
public:
    int get_set_massive(){return size_massive;}
    encoder(unsigned char const arr[], int n){
        massive = new unsigned char[n+1];
        size_massive=n;
        cout<<"constructor"<<endl;
    }
    void mutator(unsigned char const * arr, int n){ //setter
        for (int i=0; i<n; i++){
            massive[i]=arr[i];
            cout<<massive[i]<<endl;
        }
    }
    encoder(encoder const & p){
        for (int i=0; i<p.size_massive; i++) {
            massive[i] = p.massive[i];
        }
        size_massive=p.size_massive;
    }
    ~encoder(){
        delete[] massive;
        cout<<"destructor"<<endl;
    }
};



int main() {
    unsigned char *ptr;
    encoder t(ptr,3);
    for (int i=0; i<10; i++){
        ptr[i]=i+'0';
    }
    t.mutator(ptr,10);
    return 0;
}
