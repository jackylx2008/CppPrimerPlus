#ifndef __DMA_H__
#define __DMA_H__
class Dma_ABC {
  private:
    char* label;
    int rating;

  public:
    explicit Dma_ABC(const char* l = "null", int r = 0);
    Dma_ABC(const Dma_ABC& dma);
    virtual ~Dma_ABC();
    Dma_ABC& operator=(const Dma_ABC& dma);
    virtual void View() const;
};

class baseDMA : public Dma_ABC {
  private:
  public:
    explicit baseDMA(const char* l = "null", int r = 0);
    baseDMA(const baseDMA& bd);
    virtual ~baseDMA();
    virtual baseDMA& operator=(const baseDMA& bd);
    virtual void View() const;
};

// class lacksDMA : public Dma_ABC {
//   private:
//     char color[40];
//
//   public:
//     lacksDMA();
//     explicit lacksDMA(const char* l = "null", int r = 0,
//                       const char* c = "null");
//     lacksDMA(const lacksDMA&);
//     virtual lacksDMA& operator=(const lacksDMA&);
//     virtual ~lacksDMA();
//     virtual void View() const;
// };
// class hasDMA : public Dma_ABC {
//   private:
//     char* style;
//
//   public:
//     hasDMA();
//     explicit hasDMA(const char* l = "null", int r = 0, const char* s =
//     "null"); hasDMA(const hasDMA&); virtual hasDMA& operator=(const hasDMA&);
//     virtual ~hasDMA();
//     virtual void View() const;
// };
#endif  // !__DMA_H__