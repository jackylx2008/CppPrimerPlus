#ifndef __MOVE_H__
#define __MOVE_H__

class Move {
private:
  double x;
  double y;

public:
  explicit Move(double a = 0, double b = 0);
  void showmove() const;
  Move add(const Move &m) const;
  // sets x, y to a, b
  // shows current x, y values
  // this function adds x of m to x of invoking object to get new x,
  // adds y of m to y of invoking object to get new y, creates a new
  // move object initialized to new x, y values and returns it
  void reset(double a = 0, double b = 0); // resets x,y to a, b };
};
#endif // !__MOVE_H__
