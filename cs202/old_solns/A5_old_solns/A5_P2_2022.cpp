#include <stdlib.h>
#include <iostream>

template <class T>
class smartArray 
{
public:
    T *elements;
    int length();
    smartArray(){
        this->size = 0;
        this->elements = NULL;
    }
    smartArray(int size){
        this->size = size;
        if (this->size != 0)
            this->elements = new T [this->size];
        else this->elements = NULL;
    }
    smartArray(const smartArray &obj){
        this->size = obj.size;
        this->elements = new T [this->size];        
        for (int i = 0; i < this->size; i++)
            this->elements[i] = obj.elements[i];
    }
    ~smartArray(){
        if (elements != NULL) delete [] this->elements;
    }

    T& operator[](int i){
        return this->elements[i];
    }
    bool operator==(const smartArray &obj){
        if (this->size == obj.size) {
            for (int i = 0; i < this->size; i++) {
                if (this->elements[i] != obj.elements[i]) return false;
            }
            return true;
        }
        return false;
    }
    bool operator!=(const smartArray &obj){
        return !(*this==obj);
    }
    smartArray operator&(const smartArray& obj){
        int merged_size = this->size + obj.size;
        smartArray merged_arr(merged_size);
        for (int i = 0; i < merged_size; i++) {
            if (i >= this->size)
                merged_arr[i] = obj.elements[i - this->size];
            else
                merged_arr[i] = this->elements[i];
        }
        return merged_arr;
    }
    smartArray operator+(const smartArray& obj){
        smartArray new_arr;
        if (this->size >= obj.size) {
            new_arr.size = this->size;
            new_arr.elements = new T [new_arr.size];
            for(int i = 0; i < this->size; i++) {
                if (i >= obj.size)
                    new_arr[i] = this->elements[i] + 0;
                else
                    new_arr[i] = this->elements[i] + obj.elements[i];
            }
        }
        else {
            new_arr.size = obj.size;
            new_arr.elements = new T [new_arr.size];
            for(int i = 0; i < obj.size; i++) {
                if (i >= this->size)
                    new_arr[i] = obj.elements[i] + 0;
                else
                    new_arr[i] = this->elements[i] + obj.elements[i];
            }
        }
        return new_arr;
    }
    smartArray operator-(const smartArray& obj);
    smartArray operator*(const smartArray& obj){
        smartArray new_arr;
        if (this->size >= obj.size) {
            new_arr.size = this->size;
            new_arr.elements = new T [new_arr.size];
            for(int i = 0; i < this->size; i++) {
                if (i >= obj.size)
                    new_arr[i] = this->elements[i] * 1;
                else
                    new_arr[i] = this->elements[i] * obj.elements[i];
            }
        }
        else {
            new_arr.size = obj.size;
            new_arr.elements = new T [new_arr.size];
            for(int i = 0; i < obj.size; i++) {
                if (i >= this->size)
                    new_arr[i] = obj.elements[i] * 1;
                else
                    new_arr[i] = this->elements[i] * obj.elements[i];
            }
        }
        return new_arr;
    }
    smartArray operator/(const smartArray& obj);


    smartArray& operator=(const smartArray& obj){
        if (this->elements == obj.elements)
            return *this;
        else if (this->elements != NULL)
            delete [] this->elements;
        this->size = obj.size;
        this->elements = new T [this->size];
        for (int i = 0; i < this->size; i++)
            this->elements[i] = obj.elements[i];
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &output, const smartArray &obj)
    {
        output << '[';
        for (int i = 0; i < obj.size; i++) 
        {
            if (i == obj.size - 1)
                output << obj.elements[i] << "]\n";
            else
                output << obj.elements[i] << ',';
        }
        return output;
    }
    friend std::istream &operator>>(std::istream &input, smartArray &obj)
    {
        for (int i = 0; i < obj.size; i++) 
        {
            std::cout << "enter element " << i << ": ";
            input >> obj[i];
        }
        return input;
    }

    void resize(int newsize) {
        double* new_arr = new T [newsize];
        for (int i = 0; i < newsize; i++) {
            if (i >= this->size) new_arr[i] = 0;
            else new_arr[i] = elements[i];
        }
        this->size = newsize;
        delete [] elements;
        elements = new_arr;
    }

private:
    int size;

};

int main()
{
    smartArray <double> s8(5);
    for (int i = 0; i < 5; i++)
        std::cin >> s8.elements[i];
    for (int i = 0; i < 5; i++)
        std::cout << s8.elements[i];
    smartArray <double> s9(6);
    for (int i = 0; i < 6; i++)
        std::cin >> s9.elements[i];
    for (int i = 0; i < 6; i++)
        std::cout << s9.elements[i];
    return 0;
}

template <class T>
int smartArray<T>::length(){
    return this->size;
}
template <class T>
smartArray<T> smartArray<T>::operator-(const smartArray& obj){
    smartArray new_arr;
    if (this->size >= obj.size) {
        new_arr.size = this->size;
        new_arr.elements = new T [new_arr.size];
        for(int i = 0; i < this->size; i++) {
            if (i >= obj.size)
                new_arr[i] = this->elements[i] - 0;
            else
                new_arr[i] = this->elements[i] - obj.elements[i];
        }
    }
    else {
        new_arr.size = obj.size;
        new_arr.elements = new T [new_arr.size];
        for(int i = 0; i < obj.size; i++) {
            if (i >= this->size)
                new_arr[i] = obj.elements[i] - 0;
            else
                new_arr[i] = this->elements[i] - obj.elements[i];
        }
    }
    return new_arr;
}
template <class T>
smartArray<T> smartArray<T>::operator/(const smartArray& obj){
    smartArray new_arr;
    if (this->size >= obj.size) {
        new_arr.size = this->size;
        new_arr.elements = new T [new_arr.size];
        for(int i = 0; i < this->size; i++) {
            if (i >= obj.size)
                new_arr[i] = this->elements[i] / 1;
            else
                new_arr[i] = this->elements[i] / obj.elements[i];
        }
    }
    else {
        new_arr.size = obj.size;
        new_arr.elements = new T [new_arr.size];
        for(int i = 0; i < obj.size; i++) {
            if (i >= this->size)
                new_arr[i] = obj.elements[i] / 1;
            else
                new_arr[i] = this->elements[i] / obj.elements[i];
        }
    }
    return new_arr;
}