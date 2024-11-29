#ifndef __TV_H__
#define __TV_H__

class Tv {
  private:
    int state;  // on or off
    int volumn;
    int maxchannel;
    int channel;
    int mode;   // broadcat or cable
    int input;  // TV or DVD

  public:
    enum {
        Off,
        On
    };
    enum {
        MinVal,
        MaxVal = 10
    };
    enum {
        Antenna,
        Cable
    };
    enum {
        TV,
        DVD
    };
    explicit Tv(int s = Off, int mc = 15)
        : state(s),
          volumn(5),
          maxchannel(mc),
          channel(2),
          mode(Cable),
          input(TV) {}
    void onoff() {
        state = (state == On) ? Off : On;
    }
    bool ison() const {
        return state == On;
    }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {
        mode = (mode == Antenna) ? Cable : Antenna;
    }
    void set_input() {
        input = (input == TV) ? DVD : TV;
    }
    void settings() const;
    Tv(const Tv& t) {
        state = t.state;
        volumn = t.volumn;
        maxchannel = t.maxchannel;
        channel = t.channel;
        mode = t.mode;
        input = t.input;
    }
    Tv& operator=(const Tv& t) {
        state = t.state;
        volumn = t.volumn;
        maxchannel = t.maxchannel;
        channel = t.channel;
        mode = t.mode;
        input = t.input;
        return *this;
    }
    ~Tv() {}

  public:
    friend class Remote;
};

class Remote {
  private:
    int mode;

  public:
    Remote(int m = Tv::TV) : mode(m) {}
    bool volup(Tv& t) {
        return t.volup();
    }
    bool voldown(Tv& t) {
        return t.voldown();
    }
    void onoff(Tv& t) {
        t.onoff();
    }
    void chanup(Tv& t) {
        t.chanup();
    }
    void chandown(Tv& t) {
        t.chandown();
    }
    void set_chan(Tv& t, int c) {
        t.channel = c;
    }
    void set_mode(Tv& t) {
        t.set_mode();
    }
    void set_input(Tv& t) {
        t.set_input();
    }
};

#endif  // !__TV_H__
