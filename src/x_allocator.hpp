#pragma once

#include <iostream>
#include <cstddef>

template<class _T>
struct XAllocator_base {
    typedef _T value_type;
};

template<class _T>
struct XAllocator_base<const _T> {
    typedef _T value_type;
};

template<class _T>
class XAllocator : public XAllocator_base<_T> {
public:
    // embed data type table
    typedef typename std::size_t size_type;
    typedef typename std::ptrdiff_t diff_type;
    typedef _T *ptr;
    typedef const _T *const_ptr;
    typedef _T &ref;
    typedef const _T &const_ref;
    typedef XAllocator_base<_T> _my_base;
    typedef typename _my_base::value_type value_type;

    template<class _U>
    struct rebind {
        typedef XAllocator<_U> other;
    };

    // constructor
    XAllocator() throw() {
    }

    // copy constructor
    XAllocator(const XAllocator &) throw() {
    }

    template<class _otherAllocator>
    XAllocator(const XAllocator<_otherAllocator> &) throw() {
    }

    // deconstructor
    ~XAllocator() throw() {
    }

    // allocate
    ptr allocate(size_type n, typename XAllocator<_T>::const_ptr hint = 0) {
        static int i = 0;
        i++;
        std::cout << "The " << i << "'th allocate" << std::endl;
        std::cout << "for " << n << " item" << std::endl;
        return (ptr) (::operator new(n * sizeof(_T)));
    }

    // placement new
    void construct(ptr p, const_ref value) {
        new(p)_T(value);
    }

    // de-construct for item
    void destroy(ptr p) {
        p->~_T();
    }

    // free memory
    void deallocate(ptr p, size_type n) {
        ::operator delete(p);
    }
};
