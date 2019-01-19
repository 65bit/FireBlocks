#pragma once

#include "lib/private/FastDelegate.hpp"
#include "lib/private/FastDelegateBind.hpp"

namespace lib
{
    template<typename T>
    class Delegate : public fastdelegate::FastDelegate<T> {};

    /*
    template<typename... T>
    class Delegate;

    template<typename Return>
    class Delegate<Return> : public fastdelegate::FastDelegate0<Return> {};

    template<typename T1, typename Return>
    class Delegate<T1, Return> : public fastdelegate::FastDelegate1<T1, Return> {};

    template<typename T1, typename T2, typename Return>
    class Delegate<T1, T2, Return> : public fastdelegate::FastDelegate2<T1, T2, Return> {};

    template<typename T1, typename T2, typename T3, typename Return>
    class Delegate<T1, T2, T3, Return> : public fastdelegate::FastDelegate3<T1, T2, T3, Return> {};

    template<typename T1, typename T2, typename T3, typename T4, typename Return>
    class Delegate<T1, T2, T3, T4, Return> : public fastdelegate::FastDelegate4<T1, T2, T3, T4, Return> {};

    template<typename Return, typename... T>
    Delegate<T..., Return> MakeReturnDelegate()
    {
        return Delegate<T..., Return>{};
    }

    template<typename... T>
    Delegate<T..., fastdelegate::detail::DefaultVoid> MakeDelegate()
    {
        return Delegate<T..., fastdelegate::detail::DefaultVoid>{};
    }
    */
}
