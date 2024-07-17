/*! \class Queue
 *  \brief Brief class description
 *
 *  Detailed description
 */
typedef double Item;
class My_Queue {
  public:
    /*! \enum
     *
     *  Detailed description
     */
    enum {
        Q_SIZE = 10
    };
    explicit My_Queue(int q_size = Q_SIZE);
    ~My_Queue();
    bool is_full(void) const;
    bool is_empty(void) const;
    int queue_count(void) const;
    bool pop(Item& item);
    bool push(const Item& item);
    void show_queue(void) const;

  private:
    const int m_qsize;
    int m_items;
    /*! \struct Node
     *  \brief Brief struct description
     *
     *  Detailed description
     */
    struct Node {
        Item item; /*!< Detailed description */
        Node* next;
    }; /* optional variable list */
    Node* front;
    Node* rear;
};
