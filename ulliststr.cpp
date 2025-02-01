#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) // adds to back list
{
  if(tail_ == NULL || tail_->last == ARRSIZE) {
    Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 0;

    if(tail_ == NULL) { //empty, make new t and h
      head_ = newItem;
      tail_ = newItem;
    } else {
      tail_->next = newItem;
      newItem->prev = tail_;
      tail_ = newItem; // update tail
    }
  }
  tail_->val[tail_->last] = val;
  tail_->last++; 
  size_++; 
}

void ULListStr::push_front(const std::string& val)
{
  
  if (head_ == NULL || head_->first == 0) {
    Item* newItem = new Item();
    newItem->first = ARRSIZE;  // start end of arr
    newItem->last = ARRSIZE;   

    if (head_ == NULL) {
      head_ = newItem;
      tail_ = newItem;
    } else {
      head_->prev = newItem;
      newItem->next = head_;
      head_ = newItem;  // updatea head 
    }
  }
  
  head_->first--;  
  head_->val[head_->first] = val;

  size_++; 
}

void ULListStr::pop_back() //remove back lsit
{
  if (tail_ == NULL) {
    throw std::out_of_range("List is empty");
  }
  tail_->last--;
  size_--;
  if (tail_->first == tail_->last) {
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != NULL) {
      tail_->next = NULL;
    }
    delete temp; //feee old tail
  }
}

void ULListStr::pop_front()
{
  if (head_ == NULL) {
    throw std::out_of_range("List is empty");
  }
  head_->first++;
  size_--;
  if (head_->first == head_->last) {
    Item* temp = head_;
    head_ = head_->next; // move head to next item
    if (head_ != NULL) {
      head_->prev = NULL;
    }
    delete temp;
  }
}

std::string const & ULListStr::back() const
{
  if (tail_ == NULL) {
    throw std::out_of_range("List is empty"); // emtpy list error
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  if (head_ == NULL) {
    throw std::out_of_range("List is empty");
  }
  return head_->val[head_->first]; //return first value to head
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_) {
    return nullptr; 
  }
  Item* currentItem = head_;
  size_t currentIndex = 0;

  while (currentItem != NULL) {
    size_t itemSize = currentItem->last - currentItem->first;
    if (loc < currentIndex + itemSize) {
      return &currentItem->val[currentItem->first + (loc - currentIndex)];
    }
    currentIndex += itemSize; //updaye current index
    currentItem = currentItem->next; // move tot he next item
  }
  return NULL; // if not gfound
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
