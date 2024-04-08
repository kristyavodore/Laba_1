#include <iostream>
using namespace std;

class logical_values_array{
    unsigned int  value;
public:
    unsigned int get_value(){return value;}
    logical_values_array(unsigned int  a=0){value=a;}
    void Inversia();
    logical_values_array Conjuncture(logical_values_array b);
    logical_values_array Disjunction(logical_values_array b);
    logical_values_array Implication(logical_values_array b);
    logical_values_array Coimplication(logical_values_array b);
    logical_values_array Addition_modulo_2(logical_values_array b);
    logical_values_array Equivalence(logical_values_array b);
    logical_values_array Pierce_arrow(logical_values_array b);
    logical_values_array Schaeffer_touch(logical_values_array b);
    bool equals(logical_values_array b);
    unsigned int get_bit(unsigned int n){return (value >> (31-n)) & 1u;}
    void to_binary(char* buf);
    void setMemory(char *addrs);

};


void logical_values_array::Inversia(){ //инверсия
    if (value==0) value=1;
    else value=0;
}

logical_values_array logical_values_array::Conjuncture(logical_values_array b){
    logical_values_array vrem;
    vrem=(value*b.value==0)?(0):(1);
    return vrem;
}

logical_values_array logical_values_array::Disjunction(logical_values_array b){
    logical_values_array vrem;
    vrem=(value+b.value==0)?(0):(1);
    return vrem;
}

logical_values_array logical_values_array::Implication(logical_values_array b){
    logical_values_array vrem;
    vrem.value=(value==0 and b.value>0)?(0):(1);
    return vrem;
}

logical_values_array logical_values_array::Coimplication(logical_values_array b){
    logical_values_array vrem;
    vrem.value=(value==0 and b.value>0)?(1):(0);
    return vrem;
}

logical_values_array logical_values_array::Addition_modulo_2(logical_values_array b){
    logical_values_array vrem;
    vrem = this->Equivalence(b);
    vrem.Inversia();
    return vrem;
}

logical_values_array logical_values_array::Equivalence(logical_values_array b){
    logical_values_array vrem;
    vrem.value=((value==0 and b.value==0) or (value>0 and b.value>0))?(1):(0);
    return vrem;
}

logical_values_array logical_values_array::Pierce_arrow(logical_values_array b){
    logical_values_array vrem;
    vrem=this->Disjunction(b);
    vrem.Inversia();
    return vrem;
}

logical_values_array logical_values_array::Schaeffer_touch(logical_values_array b){
    logical_values_array vrem;
    vrem=this->Conjuncture(b);
    vrem.Inversia();
    return vrem;
}

bool logical_values_array::equals(logical_values_array b){
    return (value==b.value);
}

void logical_values_array::to_binary(char* buf) {
    char *pb = buf + 32;
    *pb-- = '\0';
    //cout << this->get_bit(30) + '0' << endl;
    for (int i = 31; i >= 0; i--) {
        buf[i] = this->get_bit(i) + '0';
    }
}

void logical_values_array::setMemory(char *addrs){
        if(addrs == nullptr) return;
        for(unsigned int i = 0; i < sizeof(unsigned int)*8; i++){
            *addrs++ = '0' + get_bit(i);
        }
        *addrs = '\0';
}

int main() {
    logical_values_array a(3);
    logical_values_array b(10);
    char *arr=new char[33];
    //a.setMemory(arr);
    a.to_binary(arr);
    cout<<arr;

    a.Inversia();
    //cout<<a.get_value()<<endl;
    //cout<<a.Conjuncture(b).get_value()<<endl;
    //cout<<a.Disjunction(b).get_value()<<endl;
    //cout<<a.Implication(b).get_value()<<endl;
    //cout<<a.Coimplication(b).get_value()<<endl;
    //cout<<a.Equivalence(b).get_value()<<endl;
    //cout<<a.Addition_modulo_2(b).get_value()<<endl;
    //cout<<a.Pierce_arrow(b).get_value()<<endl;
    //cout<<a.Schaeffer_touch(b).get_value()<<endl;
    //cout<<a.equals(b)<<endl;
    //cout<<a.get_bit(29)<<endl;


    return 0;
}
