#pragma once

#include <vector>
#include <algorithm>

#include "lib/Delegate.hpp"

namespace lib
{
    template<typename T>
    class Callback
    {
        using DelegateAlias = Delegate<T>;
        
    public:
        void operator += (const DelegateAlias& _delegate)
        {
            m_delegates.push_back(_delegate);
        }

        void operator -= (DelegateAlias _delegate)
        {
            auto it  = std::remove_if(m_delegates.begin(), m_delegates.end(), [&_delegate](const DelegateAlias& _internalDelegate)
                                      {
                                          return _delegate == _internalDelegate;
                                      });
            
            if(it != m_delegates.end())
            {
                m_delegates.erase(it, m_delegates.end());
            }
        }

        template<typename O, typename R, typename... Args>
        void add(O* _object, R(O::*_function)(Args...))
        {
            DelegateAlias delegate;
            delegate.bind(_object, _function);
            
            (*this) += delegate;
        }
        
        template<typename O, typename R, typename... Args>
        void remove(O* _object, R(O::*_function)(Args...))
        {
            DelegateAlias delegate;
            delegate.bind(_object, _function);
            
            (*this) -= delegate;
        }
        
        template<typename... Args>
        void operator ()(Args&&... _args)
        {
            auto copy = m_delegates;
            
            for(const auto& delegate : copy)
            {
                delegate(std::forward<Args>(_args)...);
            }
        }
        
    private:
        std::vector<DelegateAlias> m_delegates;
    };
}
