#include <iostream>

struct box {
    char marker[40];
    float height;
    float width;
    float length;
    float volume;
};

void ShowBox(const box b);
void SetVolume(box *b);
int main(int argc, char *argv[]) {
    box b1 = {"box1", 1.1, 2.2, 3.3, 0.0};
    ShowBox(b1);

    SetVolume(&b1);
    ShowBox(b1);
    return 0;
}
void ShowBox(const box b) {
    std::cout << "marker = " << b.marker << std::endl;
    std::cout << "height = " << b.height << std::endl;
    std::cout << "width = " << b.width << std::endl;
    std::cout << "length = " << b.length << std::endl;
    std::cout << "volume = " << b.volume << std::endl;
}

void SetVolume(box *b) {
    b->volume = b->height * b->width * b->length;
}
