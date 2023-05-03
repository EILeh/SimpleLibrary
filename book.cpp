#include "book.hh"
#include <iostream>

Book::Book(const std::string &author, const std::string &title):
    author_(author),
    title_(title),
    loan_date_(Date()),
    due_date_(Date()),
    is_loaned_(false)
{

}

// Checks if book is loaned or not. If it is, prints the date when it was loaned
// and the date when it will be returned. Otherwise prints available.
void Book::print() const
{
    std::cout << author_ << " : " << title_ << std::endl;
    if ( is_loaned_ )
    {
        std::cout << "- loaned: ";
        loan_date_.print();
        std::cout << "- to be returned: ";
        due_date_.print();
    }
    else
    {
        std::cout << "- available" << std::endl;
    }
}

// Checks if book is loaned or not. If it isn't, prints a message that book
// can't be renewed, otherwise moves the return date by 28 days.
void Book::renew()
{
    if ( !is_loaned_ )
    {
        std::cout << "Not loaned: cannot be renewed" << std::endl;

    }
    else
    {
        due_date_.advance(28);
    }
}

// Checks if book is loaned or not. If it is, prints a message that book can't
// be renewed. If book isn't loaned, stores to the variable loan_date_ today's
// date. After that it stores the loan_date_ variable's information to due_date_
// and then moves it by 28 days. Sets variable's is_loaned_ value to true.
void Book::loan(const Date &date)
{
    if ( is_loaned_ )
    {
        std::cout << "Already loaned: cannot be loaned" << std::endl;
        return;
    }
    loan_date_ = date;
    due_date_ = loan_date_;
    due_date_.advance(28);
    is_loaned_ = true;
}

// Sets to the variable is_loaned_ a value false.
void Book::give_back()
{
    is_loaned_ = false;
}

