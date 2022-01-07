#pragma once
#include <iostream>
#include <vector>
#include "integration/explicit.hpp"

template <typename T>
std::vector<T> operator+(const std::vector<T>& left, const std::vector<T>& right)
{
    std::vector<T> sum(left);
    for(int index = 0; index < left.size(); ++index)
    {
        sum[index] += right[index];
    }
    return sum;
}

template <typename T>
std::vector<T> operator*(const std::vector<T>& left, const std::vector<T>& right)
{
    std::vector<T> product(right);
    for(int index = 0; index < right.size(); ++index)
    {
        product[index] *= left[index];
    }
    return product;
}

template <typename T>
std::vector<T> operator*(double left, const std::vector<T>& right)
{
    std::vector<T> product(right);
    for(int index = 0; index < right.size(); ++index)
    {
        product[index] *= left;
    }
    return product;
}

int main(int argc, char* argv[])
{
    std::cout << "Hello World!" << std::endl;
    
    std::vector<double> xk = {1, 0};
    double dt = 1.0;
    auto f = [](const std::vector<double>& x)
    {
        return std::vector(x.size(), 1.0);
    };
    auto newx = math::integrate::forward_euler(xk, dt, f);
    std::cout << newx[0] << " " << newx[1] << std::endl;
    auto g = [](const std::vector<double>& x)
    {
        return std::vector(x.size(), 4.0);
    };
    xk[0] = 0;
    xk[1] = 0;
    newx = math::integrate::rk4(xk, dt, g);
    std::cout << newx[0] << " " << newx[1] << std::endl;


}