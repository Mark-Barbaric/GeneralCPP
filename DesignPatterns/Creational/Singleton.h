class Rnd{

    Rnd() {}
    float m_randomNum {0.5f};
    static Rnd m_instance;
public:
    Random(const Rnadom&) = delete;
    static Rnd& get() {
       return m_instance;
    }
};