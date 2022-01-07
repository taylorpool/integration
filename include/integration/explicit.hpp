#pragma once

namespace math::integrate
{
template <typename X, typename T, typename F>
X forward_euler(const X& x, const T& dt, const F& dxdt)
{
    return x + dt*dxdt(x);
}

template <typename X, typename T, typename F>
X midpoint(const X& xk_1, const X& xk, const T& dt, const F& dxdt)
{
    return xk_1 + 2*dt*dxdt(xk);
}

template <typename X, typename T, typename F>
X adams_bash2(const X& xk_1, const X& xk, const T& dt, const F& dxdt)
{
    return xk_1 + dt*(-0.5*dxdt(xk) + 1.5*dxdt(xk_1));
}

template <typename X, typename T, typename F>
X rk4(const X& xk, const T& dt, const F& dxdt)
{
    X k0 = dxdt(xk);
    decltype(k0) k1 = dxdt(xk + dt/2.0*k0);
    decltype(k0) k2 = dxdt(xk + dt/2.0*k1);
    decltype(k0) k3 = dxdt(xk + dt*k2);
    return xk + dt/6.0*(k0 + 2*k1 + 2*k2 + k3);
}
}