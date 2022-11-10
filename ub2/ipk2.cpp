#include <iostream>
#include <chrono>
#include <cstdlib>

//Aufgabe 1
void collatz(int n){
    //requested output bec cool
    std::cout << "Collatz with " << n << ":" << std::endl;
    //abortion conditions
    while((n != 1) && (n != 0) && (n != -1) && (n != -5) && (n != -17)){
        //if the number is even, divide by 2
        if (n % 2 == 0){
            n = n/2;
        } else{
        //if the number is odd, multiply with 3 and add 1
            n = 3*n+1;
        }
    }
    std::cout << "Result: " << n << std::endl; //defenetly not result number -_- 
}
/*
Only 0 follows 0, 
    because x/2 = 0 <=> x=0 and 0=3n+1 <=> 3n=-1 <=> n = -1/3 which is a decimal
    and never reached by this algorithm (only ints allowed)
All positive numbers end in 1,
    to be exact, they all end in a periodic 4,2,1 cycle. negative num never reach 1,
    because dividing by 2 does not change sign and 1 = -3n+1 && n>0 <=> -3n=0 <=> n=0 but n>0
    So all numbers leading to 1 have in common that they are positive and don't prove the Collatz conjecture wrong, sadly :(
*/

int fib(int n, bool show){
    //startpoint time
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    //init para
    int f1 = 0;
    int f2 = 1;
    int f_new = 0;
    if (show == 0){
        std::cout << "n_1: " << f1 << "\nn_2: " << f2 << std::endl;
    }
    if (n == 1){
        return f1;
    } else if (n == 2){
        return f2;
    } else{
        for (int i = 3; i <= n; i++) { //recursive up to n-th term
        f_new = f1 + f2;
        f1 = f2;
        f2 = f_new;
        if (show == 0){
            std::cout << "n_" << i << ": " << f_new << std::endl;
        }
        }
    }
    //endpoint time 
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    //calculate time needed for the program as a difference between end and begin timepoints 
    std::cout << "calc time = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
    return f_new;

    /*
    idk but its fast from the beginning. 40 runs 1252ns,60 runs 1526ns and 100 runs 3141ns
    would've been much slower if we had used a recursive implementation as this would lead to lots of unnecessary calculation
    */
}

void fibonacci(int n){
    std::cout << "\nnum fibonacci terms N = " << n << ":" << std::endl;
    int res = fib(n, 0); //show single terms >> 0:true, 1:false
    std::cout << "Last term: " << res << std::endl;
}

int iterative(int q,int n){
    if (n != 0) {
        int q_next = q;
        for (int i = 1; i < n; i++){
            q_next = q*q_next;
            //std::cout << q_next << std::endl;
        }
    return q_next;
    } else {
    //for q^0 = 1
        return 1;
    }
}

int recursive(int q, int n){
    if (n != 0){
        return q*recursive(q, n-1);
    } else {
        return 1; 
    }
}

int better(int q, int n){
    //use exponentiation by squaring method to optimize program time
    int m = recursive(q, n/2);
    if (n % 2 == 0){ //even, (q^n)^2=q^2n
        return m*m;
    } else { //odd, same principle 2n+1
        return m*m*q;
    }
}   //2^2: 875|537|405[ns]
    //4^4: 758|556|432[ns]
    //2^15: 1087|1087|638[ns]

//additional function to check if the input for each function from listed above is valid and to run the function
int exe(int ex){ //exercises 1-3 (written to be "pretty"(output) not efficient)
    int num;
    int num2;
    if (ex == 1){
        //input & check
        while (std::cout << "Enter number, please: " << std::flush && !(std::cin >> num)) {
            std::cerr << "Invalid input" << std::endl;
            return 1;
        }
        //function
        collatz(num); //-2384 => -5


    } else if(ex == 2){
        while (std::cout << "Enter fib-term, please: " << std::flush && !(std::cin >> num)) {
            std::cerr << "Invalid input" << std::endl;
            return 1;
        }
        fibonacci(num);


    } else if(ex == 3){
        while (std::cout << "For q^n,\nenter q and n, please: " << std::flush && !(std::cin >> num >> num2)) {
            std::cerr << "Invalid input" << std::endl;
            return 1;
        }
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now(); //timestamps 1-4
        int res1 = iterative(num, num2);
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        int res2 = recursive(num, num2);
        std::chrono::steady_clock::time_point t3 = std::chrono::steady_clock::now();
        int res3 = better(num, num2);
        std::chrono::steady_clock::time_point t4 = std::chrono::steady_clock::now();

        int a = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count(); //calc runtime funcs
        int b = std::chrono::duration_cast<std::chrono::nanoseconds>(t3 - t2).count();
        int c = std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count();

        std::cout << "calc time = " << a << '|' << b << '|' << c << "[ns]" << std::endl;
        std::cout << "iterative: " << res1 << "\nrecursive: " << res2 << "\noptimized: " << res3 << std::endl;
    } else {
        std::cerr << "change exercise number pls" << std::endl;
        return 1;
    }
    return 0;
}

int main(int argc, char** argv){
    int err = exe(3); //enter exercise number
    return err;
}
