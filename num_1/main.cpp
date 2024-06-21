#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class encoder{
    unsigned char *key;
    int size_key;
public:
    int get_size_key(){return size_key;} //геттер
    encoder(char const *arr, int size_k){
        key = new unsigned char[256];
        size_key=size_k;
        set_key(arr, size_k); //хотим сгенерировать ключ на основе массива arr
        cout<<"constructor"<<endl;
    }
    void set_key(char const * new_key, int size_k){ //setter
        for (int i = 0; i < 256; i++){
            key[i] = i;
        }
        int j = 0;
        for (int i = 0; i < 256; i++)
        {
            j = (j + key[i] + new_key[i%size_k]) % 256;
            swap(key[i], key[j]); //меняем местами значения по индексам i и j
        }
        cout<<"mutator"<<endl;
    }
    encoder(encoder const & other){ //конструктор копий
        key = new unsigned char[256];
        memcpy(key, other.key, 256);
        cout<<"copy constructor"<<endl;
    }
    ~encoder(){
        delete[] key;
        cout<<"destructor"<<endl;
    }
    encoder & operator=(encoder const &other){
        if (this != &other) {
            memcpy(key, other.key, 256 * sizeof(unsigned char));
        }
        return *this;
    }
    void encode(char const * path1, char const *path2, bool flag){
        ifstream fiI;
        ofstream fiO;
        fiI.open(path1, ios::binary);
        fiO.open(path2, ios::binary);
        if(!fiI || !fiO){
            throw std::logic_error("file open error"); //КАК ЭТО ДЕЛАЕТСЯ??!!
        }
        char data[BUFSIZ] = "", out[BUFSIZ] = "";
        data[BUFSIZ-1] = out[BUFSIZ-1] = '\0';
        int i = 0, j = 0;
        unsigned char c;
        while(!fiI.eof()){
            fiI.read(data, BUFSIZ-1);
            for (int k = 0; k < sizeof(data); k++)
            {
                i = (i + 1) % 256;
                j = (j + key[i]) % 256;
                swap(key[i], key[j]);
                c = key[(key[i] + key[j]) % 256];
                //cout << c;
                out[k] = c ^ data[k];
            }
            fiO.write(out, fiI.gcount());
        }
        fiI.close();
        fiO.close();

    }
};

int main() {
    char const *ptr="hello";
    encoder t(ptr,3);

    try {
        t.encode("1.txt", "2.txt", true);
    }
    catch (std::logic_error &err){
        std::cout<<err.what()<<endl;
    }


    return 0;
}
