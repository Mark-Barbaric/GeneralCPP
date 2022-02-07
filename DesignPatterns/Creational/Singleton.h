class Singleton{

    static Singleton* m_singleton {nullptr};

public:

    static Singleton* getSingleton() {
        if(!m_singleton){
            m_singleton = new Singleton;
        }

        return m_singleton;
    }

    Singleton(const Singleton& rhs) = delete;
    Singleton(const Singleton&& rhs) = delete;
    Singleton& operator =(const Singleton& rhs) = delete;
    Singleton& operator =(const Singleton&& rhs) = delete;


};