#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm> //this for subtask e) :OOO O: :OOO OOO: no way

void print(const std::string& s){
    std::cout << s << std::endl;
}

void print_vec(const std::vector<double>& v){
    int size = v.size();
    if (size == 0){print("no elements");}
    else {
        std::string k = "( "; //init elems output
        for (int i = 0; i < size-1; i++){ //(int i : v) => no (a,b,c) display
            k +=std::to_string(v[i]) +  ", ";
        }
        k += std::to_string(v.back()) + " )"; //add last element
        std::cout << k << std::endl;
    }
}

std::vector<double> pair(const std::vector<double>& v){
    int size = v.size();
    double max = 0;
    double min = 0; //init return vals
    for (int i = 0; i < size; i++){
        if (v[i] > max){ //check if elem > previous max, eventually replace
            max = v[i];
            //print(std::to_string(max));
        } else if (v[i] < min){ //check if elem < previous min, eve repl
            min = v[i];
        }//nothing if equal
    }
    return {min,max}; //return as vector to print
}

std::vector<double> reversed(const std::vector<double>& v){
    std::vector<double> v_rev = v;
    int size = v.size();
    for (int i = 0; i < std::floor(size/2); i++){
        //iterates through half the vectors size, if uneven (2n+1) round to 2n (floor, round down)
        std::iter_swap(v_rev.begin()+i,v_rev.rbegin()+i); //swaps elements from the outside to inside abcd => dbca => dcba
    }
    return v_rev;
}

std::vector<double> vec_round(std::vector<double>& v){
    int size = v.size();
    for (int i = 0; i < size-1; i++){
        v[i] = std::round(v[i]); //rounds every elem of vector
    }
    return v;
}

std::vector<double> reversed2(std::vector<double>& v){ //i accidentally did it like this before sooo, well, copied & del const pepega
    int size = v.size();
    for (int i = 0; i < std::floor(size/2); i++){
        //iterates through half the vectors size, if uneven (2n+1) round to 2n (floor, round down)
        std::iter_swap(v.begin()+i,v.rbegin()+i); //swaps elements from the outside to inside abcd => dbca => dcba
    }
    return v;
}


void ex(char a){ //method for subtask
    //vector examples
    std::vector<double> v1;
    std::vector<double> v2(10);
    //std::cout << v1 << std::endl;
    std::vector<double> v3{3,8,7,5,9,2};
    std::vector<double> va{24,40,-13.04,-13.01,43,0,100};

    if (a == 'a'){
        print_vec(v1);
        print("^ unassigned");
        print_vec(v2);
        print("^ no vals");
        print_vec(v3);
        //v1: error when printing, when cast into std, empty ''
        //v2: 0 as float
    }
    if (a == 'b'){
        print("Min and Max:");
        std::vector<double> a = pair(va);
        print_vec(pair(v1));
        print_vec(pair(v2));
        print_vec(pair(va));
    }
    if (a == 'c'){
        print("vec + reversed vec:");
        print_vec(va);
        print_vec(reversed(va));
        print("");
        print_vec(v1);
        print_vec(reversed(v1));
    }
    if (a == 'd'){
        print("rounded vector:");
        print_vec(vec_round(va)); //not mentioned to return int, so no new method shrugggs
        print_vec(vec_round(v3));
    }
    if (a == 'e'){
        print("vec + reversed vec:");
        print_vec(va);
        print_vec(reversed2(va));
        print("");
        print_vec(v3);
        print_vec(reversed2(v3));
    }
}

int main(int argc, char** argv){
    ex('e');
    return 0;
}