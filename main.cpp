/* Simple Library
 *
 * Description
 *
 * Program prints a book's author, name and status. If book's status is that it
 * is loaned then also the information of when it was loaned and when it will
 * be returned will also be printed. If books is not loaned, program will print
 * available.
 *
 * Writer of the program
 *
 * Name: EILeh
 */


#include "book.hh"
#include "date.hh"
#include <iostream>

using namespace std;

int main()
{
    // Creating a date
    Date today(5, 5, 2020);

    // Creating a book
    Book book1("Kivi", "Seitseman veljesta");
    book1.print();

    // Loaning a book
    book1.loan(today);

    // Two weeks later
    today.advance(14);

    // Trying to loan a loaned book
    book1.loan(today);
    book1.print();

    // Renewing a book
    book1.renew();
    book1.print();

    // Returning the book
    book1.give_back();

    // Trying to renew an available book
    book1.renew();
    book1.print();

    // Loaning again (two weeks later)
    book1.loan(today);
    book1.print();

    return 0;
}
