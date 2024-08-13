#ifndef __FRND2TEMP_H__
#define __FRND2TEMP_H__

template <typename T>
void GetCount_temp();

template <typename T>
void GetItem_temp(const T&);

template <typename T>
class HasFriend {
  private:
    static int count;
    T item;

  public:
    HasFriend<T>(int i) : item(i) {
        count++;
    }
    HasFriend<T>(double i) : item(i) {
        count++;
    }
    friend void GetCount_Notemp();
    friend void GetItem_Notemp(HasFriend<T> const& c);

    friend void GetCount_temp<T>();
    friend void GetItem_temp<>(HasFriend<T> const& c);
};

template <typename T>
class HasFriendInClass {
  private:
    static int count;
    T item;

  public:
    HasFriendInClass<T>(int i) : item(i) {
        count++;
    }
    HasFriendInClass<T>(double i) : item(i) {
        count++;
    }

    template <typename T1, typename T2>
    friend void show(const T1& t1, const T2& t2);
};
#endif  // !__FRND2TEMP_H__
