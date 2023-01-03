#include <stdlib.h>
#include <iostream>

class smartArray 
{
public:
    double *elements;
    int length();
    smartArray(){
        this->size = 0;
        this->elements = NULL;
    }
    smartArray(int size){
        this->size = size;
        if (this->size != 0)
            this->elements = new double [this->size];
        else this->elements = NULL;
    }
    smartArray(const smartArray &obj){
        this->size = obj.size;
        this->elements = new double [this->size];        
        for (int i = 0; i < this->size; i++)
            this->elements[i] = obj.elements[i];
    }
    ~smartArray(){
        if (elements != NULL) delete [] this->elements;
    }

    double& operator[](int i){
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
            new_arr.elements = new double [new_arr.size];
            for(int i = 0; i < this->size; i++) {
                if (i >= obj.size)
                    new_arr[i] = this->elements[i] + 0;
                else
                    new_arr[i] = this->elements[i] + obj.elements[i];
            }
        }
        else {
            new_arr.size = obj.size;
            new_arr.elements = new double [new_arr.size];
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
            new_arr.elements = new double [new_arr.size];
            for(int i = 0; i < this->size; i++) {
                if (i >= obj.size)
                    new_arr[i] = this->elements[i] * 1;
                else
                    new_arr[i] = this->elements[i] * obj.elements[i];
            }
        }
        else {
            new_arr.size = obj.size;
            new_arr.elements = new double [new_arr.size];
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
        this->elements = new double [this->size];
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
        double* new_arr = new double [newsize];
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
    smartArray s1(15);
    std::cin >> s1;
    smartArray s2(10);
    std::cin >> s2;
    smartArray s3;
    s3 = s1 + s2;
    std::cout << s3;
    smartArray s4;
    s4 = s1 - s2;
    std::cout << s4;
    smartArray s5;
    s5 = s1 * s2;
    std::cout << s5;
    smartArray s6;
    s6 = s1 / s2;
    std::cout << s6;
    std::cout << (s1 != s2) << std::endl;
    s2.resize(15);
    for (int i = 10; i < 15; i++)
        s2[i] = i + 1;
    smartArray s7;
    s7 = s1 & s2;
    std::cout << s7;

}

int smartArray::length(){
    return this->size;
}
smartArray smartArray::operator-(const smartArray& obj){
    smartArray new_arr;
    if (this->size >= obj.size) {
        new_arr.size = this->size;
        new_arr.elements = new double [new_arr.size];
        for(int i = 0; i < this->size; i++) {
            if (i >= obj.size)
                new_arr[i] = this->elements[i] - 0;
            else
                new_arr[i] = this->elements[i] - obj.elements[i];
        }
    }
    else {
        new_arr.size = obj.size;
        new_arr.elements = new double [new_arr.size];
        for(int i = 0; i < obj.size; i++) {
            if (i >= this->size)
                new_arr[i] = obj.elements[i] - 0;
            else
                new_arr[i] = this->elements[i] - obj.elements[i];
        }
    }
    return new_arr;
}
smartArray smartArray::operator/(const smartArray& obj){
    smartArray new_arr;
    if (this->size >= obj.size) {
        new_arr.size = this->size;
        new_arr.elements = new double [new_arr.size];
        for(int i = 0; i < this->size; i++) {
            if (i >= obj.size)
                new_arr[i] = this->elements[i] / 1;
            else
                new_arr[i] = this->elements[i] / obj.elements[i];
        }
    }
    else {
        new_arr.size = obj.size;
        new_arr.elements = new double [new_arr.size];
        for(int i = 0; i < obj.size; i++) {
            if (i >= this->size)
                new_arr[i] = obj.elements[i] / 1;
            else
                new_arr[i] = this->elements[i] / obj.elements[i];
        }
    }
    return new_arr;
}