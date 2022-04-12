struct vec2d        //defining 2d vectors, and creating their "rules"
{
    float x, y;     //defines vec2d as a datatype
    vec2d(float x_input = 0, float y_input = 0)
    {
        x = x_input;
        y = y_input;
    }
    float norm(){
        return sqrt(x*x+y*y);
    }
    vec2d unit(){
        vec2d v(x,y);
        return v/v.norm();
    }
    
    friend vec2d operator+(vec2d const &, vec2d const &);   //lets the + operator interact with vec2d. + is basically declared a friend and is let into vec2d's house.
    friend vec2d operator-(vec2d const &, vec2d const &);   //lets - into struct house
    friend vec2d operator*(vec2d const &, vec2d const &);   // lets * into struct house
    friend vec2d operator/(vec2d const &, vec2d const &);

    friend vec2d operator*(vec2d const &, float const &); //allows for multiplying a vector with a constant. requires 2 lines to be commutative
    friend vec2d operator*(float const &, vec2d const &);   
    friend vec2d operator/(vec2d const &, float const &); //allows for dividing a vector by a constant 
    friend vec2d operator/(float const &, vec2d const &); //allows for dividing a constant by a vector (idk if i need this???)
    friend ostream &operator<<(ostream &, const vec2d &); //allows for 
    
};

vec2d operator+(vec2d const &c1, vec2d const &c2)           // rules for addition of vectors (vector calculus + array behaviour)
{
    return vec2d(c1.x + c2.x, c1.y + c2.y);
}
vec2d operator-(vec2d const &c1, vec2d const &c2)           //rules for subtracting vectors (vector calculus + array behaviour)
{
    return vec2d(c1.x - c2.x, c1.y - c2.y);
}
vec2d operator*(vec2d const &c1, vec2d const &c2)           //rules for multiplying vectors (array behaviour)
{
    return vec2d(c1.x * c2.x, c1.y * c2.y);
}

vec2d operator/(vec2d const &c1, vec2d const &c2)           //rules for dividing vectors (array behaviour)
{   
    return vec2d(c1.x / c2.x, c1.y / c2.y);
}

vec2d operator*(vec2d const &c1, float const &c2)           //rules for scaling vectors by multiplication
{
    return vec2d(c1.x * c2, c1.y * c2);
}

vec2d operator*(float const &c1, vec2d const &c2)           //rules for scaling vectors by multiplication, commutative property.
{
    return vec2d(c1 * c2.x, c1 * c2.y);
}

vec2d operator/(vec2d const &c1, float const &c2)           //rules for scaling vectors by dividing
{
    return vec2d(c1.x /c2, c1.y/c2);
}
ostream &operator<<(ostream &os, const vec2d &c2)
{
    os << "[" << c2.x << "," << c2.y <<"]";
    return os;
}