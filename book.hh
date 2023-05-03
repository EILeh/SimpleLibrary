#ifndef BOOK_HH
#define BOOK_HH

#include "date.hh"
#include <string>


class Book
{
public:
    Book(std::string const &author, std::string const &title);
    void print() const;
    void renew();
    void loan(Date const &date);
    void give_back();

private:
    std::string author_;
    std::string title_;
    Date loan_date_;
    Date due_date_;
    bool is_loaned_;

};

#endif // BOOK_HH
