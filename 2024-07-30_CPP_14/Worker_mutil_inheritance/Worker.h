#ifndef __WORKER_H__
#define __WORKER_H__

#include <cstdint>
#include <iostream>
#include <string>

class Worker {
  private:
    std::string Name;
    long ID;

  protected:
    virtual void Set_data();
    virtual void Get_data() const;

  public:
    Worker() : Name("Null"), ID(0L) {}
    Worker(std::string name, long id) : Name(name), ID(id) {}
    Worker(const Worker& w) : Name(w.Name), ID(w.ID) {}
    virtual ~Worker() {}
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Singer : virtual public Worker {
  private:
    enum {
        Vtypes = 5
    };
    enum {
        null,
        high,
        medium,
        low,
        bass,
    };
    static const char* pv_type[Vtypes];
    int Voice;

  protected:
    virtual void Set_data();
    virtual void Get_data() const;

  public:
    Singer() : Worker(), Voice(null) {}
    Singer(const Worker& worker, int voice = null)
        : Worker(worker), Voice(voice) {}
    Singer(std::string name, long id, int voice)
        : Worker(name, id), Voice(voice) {}
    Singer(const Singer& singer)
        : Worker((const Worker&)singer), Voice(singer.Voice) {}
    virtual ~Singer() {}
    virtual void Set();
    virtual void Show() const;
};

class Waiter : virtual public Worker {
  private:
    int Power;

  protected:
    virtual void Set_data();
    virtual void Get_data() const;

  public:
    Waiter() : Worker(), Power(0) {}
    Waiter(std::string name, long id, int power)
        : Worker(name, id), Power(power) {}
    Waiter(const Worker& worker, int power = 0)
        : Worker(worker), Power(power) {}
    Waiter(const Waiter& waiter)
        : Worker((const Worker&)waiter), Power(waiter.Power) {}
    virtual ~Waiter() {}
    virtual void Set();
    virtual void Show() const;
};

class SingerWaiter : virtual public Singer, virtual public Waiter {
  protected:
    virtual void Set_data() {}
    virtual void Get_data() const {}

  public:
    SingerWaiter() : Worker(), Singer(), Waiter() {}
    // SingerWaiter(std::string n, long id, int v, int p)
    //     : Worker(n, id), Singer(n, id, v), Waiter(n, id, p) {}
    // SingerWaiter(const Worker& w, int v, int p)
    //     : Worker(w), Singer(w, v), Waiter(w, p) {}
    virtual ~SingerWaiter() {}
    virtual void Set();
    virtual void Show() const;
};

#endif  // !__WORKER_H__
