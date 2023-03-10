union T {
    int x;
    double d;
    char b[sizeof(double)];
};

T t = {0};

// g++ -std=c++98 -c 3-7-3.cpp