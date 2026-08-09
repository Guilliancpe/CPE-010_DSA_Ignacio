#include <iostream>
#include <string>
#include "SUP_LL.h"

int main(){

   Job job1;

    job1.id = 1;
    job1.page = 5;
    job1.name = "Lanc e lot";

    Job job2;

    job2.id = 2;
    job2.page = 6;
    job2.name = "Dog cat";

    Job job3;

    job3.id = 3;
    job3.page = 7;
    job3.name = "Andy Sachs";


    Printer<Job> printer;

    printer.enqueue(&printer.frontptr, &printer.backptr, job1);
    std::cout << printer.frontptr->data.name << " " << printer.backptr->data.id << std::endl;

    printer.enqueue(&printer.frontptr, &printer.backptr, job2);
    std::cout << printer.frontptr->data.name << " " << printer.backptr->data.name << std::endl;

    printer.enqueue(&printer.frontptr, &printer.backptr, job3);
    std::cout << printer.frontptr->data.name << " " << printer.backptr->data.name << std::endl;

    printer.dequeue(&printer.frontptr, &printer.backptr);
    std::cout << printer.frontptr->data.name << " " << printer.backptr->data.name << std::endl;
    return 0;
}
