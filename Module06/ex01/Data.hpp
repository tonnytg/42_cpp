#ifndef DATA_HPP
# define DATA_HPP

class Data {
private:
    int _n;
public:
    Data();
    ~Data();
    Data(Data const & src);
    Data & operator=(Data const & src);
    Data(int n);
    int getN() const;
    void setN(int n);
};

#endif