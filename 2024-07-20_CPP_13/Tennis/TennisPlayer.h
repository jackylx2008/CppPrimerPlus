#ifndef __TENNIS_PLAYER_H__
#define __TENNIS_PLAYER_H__

#include <string>

class TennisPlayer {
  private:
    std::string lname;
    std::string fname;
    bool HasTable;

  public:
    TennisPlayer(const std::string &first_name = "",
                 const std::string &last_name = "", bool hastable = false) {
        fname = first_name;
        lname = last_name;
        HasTable = hastable;
    }
    void ShowTable();
    ~TennisPlayer() = default;
    TennisPlayer operator=(const TennisPlayer &tp);
};

class RatedPlayer : public TennisPlayer {
  private:
    unsigned int Scorce;
    RatedPlayer();

  public:
    RatedPlayer(const std::string &first_name = "",
                const std::string &last_name = "", bool hastable = false,
                unsigned int score = 0);
    explicit RatedPlayer(const TennisPlayer &tp, unsigned int score = 0);
    RatedPlayer(const RatedPlayer &rp);
    void ShowPlayer();
    ~RatedPlayer() = default;
};

#endif  // !__TENNIS_PLAYER_H__
