#include <iostream>
#include <cstring>
#include <string>
using namespace std;


class Seat{//b1
      public:
          bool booking_status;
          int row_no;
          int seat_no;
          Seat* next;
          Seat* prev;
          Seat(){//b2
              row_no = -1;
              seat_no = -1;
              booking_status = false;
              next = nullptr;
              prev = nullptr;
          }//b2

};//b1


class Cinemax{//b3

      private:
          int rows;
          int seats;
      public:
          Seat* Heads[10];
          Cinemax(){//b5
                rows = 10;
                seats = 10;
          }//b5
          void book_front_seat(int head_indx , bool status){//b4
                if(!Heads[head_indx]){//b6
                    Heads[head_indx] = new Seat();
                }//b6
          }//b4
            



};//b3


int main(){
Cinemax c;
c.Heads[8] = new Seat();
          cout<<c.Heads[8]->row_no;
return 0;}
