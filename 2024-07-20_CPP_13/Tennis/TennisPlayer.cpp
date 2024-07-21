#include <iostream>

#include "./TennisPlayer.h"

void TennisPlayer::ShowTable() {
    if (HasTable) {
        std::cout << fname << " " << lname << " has a table" << std::endl;
    } else {
        std::cout << fname << " " << lname << " hasn't a table" << std::endl;
    }
}
TennisPlayer TennisPlayer::operator=(const TennisPlayer &tp) {
    lname = tp.lname;
    fname = tp.fname;
    HasTable = tp.HasTable;
    return *this;
}

RatedPlayer::RatedPlayer(const std::string &first_name,
                         const std::string &last_name, bool hastable,
                         unsigned int score)
    : TennisPlayer(first_name, last_name, hastable), Scorce(score) {
}
RatedPlayer::RatedPlayer(const TennisPlayer &tp, unsigned int score)
    : Scorce(score), TennisPlayer(tp) {
}
RatedPlayer::RatedPlayer(const RatedPlayer &rp)
    : Scorce(1000), TennisPlayer("&rp") {
}
void RatedPlayer::ShowPlayer() {
    ShowTable();
    std::cout << "Score = " << Scorce << std::endl;
}
