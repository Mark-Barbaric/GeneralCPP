//If a function works with a pointer to a base object, it should work with other derived objects too
class GeometricObject{

    double m_height {0.0};
    double m_width {0.0};

public:

    virtual ~GeometricObject() = default;
    virtual void setHeight(double height) = 0;
    virtual void setWidth(double width)  = 0;
    virtual void setBounds(double height, double width) = 0;
};

class Square : public GeometricObject{

    void setWidth(double width) override {
        m_width = width;
        setHeight(width);
    }
public:
    void setHeight(double height) override {
        m_height = height;
        setWidth(height);
    }

    void setBounds(double height, double width) override{
        assert(width == height);
        setHeight(height);
    }
};

class Rectangle : public GeometricObject{

public:

    void setHeight(double height) {m_height = height;}
    void setWidth(double width) {m_width = width;}
    void setBounds(double height, double width) {
        setHeight(height);
        setWidth(width);
    }

};