#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

class Rectangle {
public:
  Rectangle(int width, int height);

  int GetWidth() const;
  int GetHeight() const;

  int GetArea() const;
  int GetPerimeter() const;

private:
  int width_;
  int height_;
};

#endif // RECTANGLE_H_INCLUDED