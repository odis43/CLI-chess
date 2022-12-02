#ifndef OBSERVER
#define OBSERVER

class Observer {
    public:
        virtual void notify() = 0;
        virtual ~Observer();
        
};

#endif
