#ifndef RING_ARRAY_H
#define RING_ARRAY_H

/**
 * \brief this class represents a ring array, that is, a circular array. The
 * array has a fixed capacity, and it is possible to insert elements in it
 * until it becomes full. Any attempt to insert more elements in a filled array
 * will abort the program.
 */
template <class T, unsigned N> class RingArray {
  public:
    RingArray(): _first(0), _last(0) {}
    /**
     * \brief This method adds a new value into the array. If the array is full,
     * then this method stops the program. After inserting an element in the
     * array, the number of elements stored there increases by one.
     * \param value the element that must be inserted.
     */
    void add(T value);

    /**
     * \brief This method returns the oldest element stored in the array. After
     * returning an element, that element is removed from the array. Thus, the
     * number of elements in the array decreases by one. If we try to retrieve
     * an element from an empty array, then this method aborts the program.
     */
    T get();

    /**
     * This method is true if the array contains N-1 elements.
     * \return true if the array contains N-1 elements.
     */
    bool isFull() const;

    /**
     * This method is true if the array contains zero elements.
     * \return true if the array is empty.
     */
    bool isEmpty() const;

  private:
    unsigned _first; ///< The index of the oldest element in the array.
    unsigned _last; ///< The index of the next empty spot in the array.
    T buf[N]; ///< The buffer that stores the data in the array.
};

#endif