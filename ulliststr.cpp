#include "ulliststr.h"

#include <cstddef>
#include <iostream>
#include <stdexcept>

ULListStr::ULListStr() {
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

ULListStr::~ULListStr() { clear(); }

bool ULListStr::empty() const { return size_ == 0; }

size_t ULListStr::size() const { return size_; }

void ULListStr::push_back(const std::string& val) {

    // @summary Create new item with null reference to next
    Item* item = new Item();
    item->val[0] = val;
    item->prev = tail_;
    item->next = NULL;
    tail_ = item;

    // @condition If head is empty, make head point to new item
    if (head_ == NULL) {
        head_ = item;
    }

    // @condition If size will be 2,  connect the items
    if (tail_->prev != NULL) {
        tail_->prev->next = tail_;
    }

    size_++;
}

void ULListStr::push_front(const std::string& val) {

    // @summary Create new item with null reference to previous
    Item* item = new Item();
    item->val[0] = val;
    item->prev = NULL;
    item->next = head_;
    head_ = item;

    // @summary If tail is empty, make tail point to new item
    if (tail_ == NULL) {
        tail_ = item;
    }

    // @condition If size will be 2,  connect the items
    if (head_->next != NULL) {
        head_->next->prev = head_;
    }

    size_++;
}

void ULListStr::pop_front() {

    // @summary Remove item at front of list
    if (!this->empty()) {
        Item* temp = new Item();
        temp = head_;
        head_ = head_->next;
        if (head_ != NULL) {
            head_->prev = NULL;
        }
        if(temp != tail_) {
            delete temp;
        }
        size_--;
    }
}

void ULListStr::pop_back() {

    // @summary Remove item at end of list
    if (!this->empty()) {
        Item* temp = new Item();
        temp = tail_;
        tail_ = tail_->prev;
        if (tail_ != NULL) {
            tail_->next = NULL;
        }
        if(temp != head_) {
            delete temp;
        }
        size_--;
    }
}

std::string const& ULListStr::front() const { return head_->val[0]; }

std::string const& ULListStr::back() const { return tail_->val[0]; }

std::string* ULListStr::getValAtLoc(size_t loc) const {
    Item* cursorHead = head_;
    for (size_t x = 0; x < size_; x++) {
        if (loc == x) {
            return cursorHead->val;
        }
        cursorHead = cursorHead->next;
    }
    return cursorHead->val;
}

void ULListStr::set(size_t loc, const std::string& val) {
    std::string* ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string& ULListStr::get(size_t loc) {
    std::string* ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const& ULListStr::get(size_t loc) const {
    std::string* ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

void ULListStr::clear() {
    while (head_ != NULL) {
        Item* temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}
