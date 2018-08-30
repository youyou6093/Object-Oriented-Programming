class Triangle{
    
    int size;
    char border;
    char fill;
    static const int MIN_SIZE=1;
    static const int MAX_SIZE=39;
    
    
public:
    Triangle(int n,char a='#',char b='*');
    int GetSize() const;
    int Perimeter() const;
    double Area() const;
    void Grow();
    void Shrink();
    void Draw() const;
    void Summary() const;
    void SetBorder(char a);
    void SetFill(char a);
};
