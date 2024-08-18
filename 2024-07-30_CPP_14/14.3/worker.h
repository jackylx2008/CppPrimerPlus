#ifndef __WORKER_H__
#define __WORKER_H__

#include <string>

class Worker {  // an abstract base class

  private:
    std::string fullname;
    long id;

  protected:
    virtual void Data() const;
    virtual void Get();

  public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string& s, long n) : fullname(s), id(n) {}
    virtual ~Worker() = 0;  // pure virtual function
    virtual void Set() = 0;
    virtual void Show() const = 0;
};
class Waiter : virtual public Worker {
  private:
    int panache;

  protected:
    void Data() const;
    void Get();

  public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string& s, long n, int p = 0)
        : Worker(s, n), panache(p) {}
    Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};
class Singer : virtual public Worker {
  protected:
    enum {
        other,
        alto,
        contralto,
        soprano,
        bass,
        baritone,
        tenor
    };
    enum {
        Vtypes = 7
    };
    void Data() const;

  private:
    static char* pv[Vtypes];  // string equivs of voice types
    int voice;

  public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string& s, long n, int v = other)
        : Worker(s, n), voice(v) {}
    explicit Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
    void Get();
};
// multiple inheritance
class SingingWaiter : public Singer, public Waiter {
  protected:
    void Data() const;
    void Get();

  public:
    SingingWaiter() {}
    explicit SingingWaiter(const std::string& s, long n, int p = 0,
                           int v = other)
        : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
    explicit SingingWaiter(const Worker& wk, int p = 0, int v = other)
        : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    explicit SingingWaiter(const Waiter& wt, int v = other)
        : Worker(wt), Waiter(wt), Singer(wt, v) {}
    explicit SingingWaiter(const Singer& wt, int p = 0)
        : Worker(wt), Waiter(wt, p), Singer(wt) {}
    void Set();
    void Show() const;
};

#endif  // !__WORKER_H__
