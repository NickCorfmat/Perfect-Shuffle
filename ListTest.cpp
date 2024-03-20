// --------------------------------------------------------------
// Nicolas Corfmat
// CruzID: ncorfmat
// Assignment: pa5
// --------------------------------------------------------------

#include <iostream>
#include <string>
#include <stdexcept>
#include "List.h"

using namespace std;

int main() {

   int i, n = 15;
   List A, B, C, D, E, F;

   cout << "A.position() = " << A.position() << endl;
   cout << "A = " << A << endl;

   for (i = 1; i <= n; i++) {
      A.insertAfter(i * 2);
      B.insertBefore(i * 3);
      C.insertAfter(i * 4);
      D.insertBefore(i * 5);
   }

   cout << endl;
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
   cout << "C = " << C << endl;
   cout << "C.position() = " << C.position() << endl;
   cout << "D = " << D << endl;
   cout << "D.position() = " << D.position() << endl;
   cout << endl;

   A.moveBack();
   B.moveFront();
   C.moveFront();
   D.moveBack();

   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
   cout << "C = " << C << endl;
   cout << "C.position() = " << C.position() << endl;
   cout << "D = " << D << endl;
   cout << "D.position() = " << D.position() << endl;

   cout << endl << "B: ";
   
   for (i = 1; i <= 7; i++) {
      cout << B.moveNext() << " ";
   }

   cout << endl << "B.position() = " << B.position() << endl;

   cout << endl << "C: ";
   
   for (i = 1; i <= 7; i++) {
      cout << C.moveNext() << " ";
   }

   cout << endl << "C.position() = " << C.position() << endl;

   cout << endl;
   cout << "A==B is " << (A == B ? "true" : "false") << endl;
   cout << "B==C is " << (B == C ? "true" : "false") << endl;
   cout << "C==D is " << (C == D ? "true" : "false") << endl;
   cout << "D==A is " << (D == A ? "true" : "false") << endl;
   cout << endl;

   cout << B << endl;
   cout << B.position() << endl;
   B.moveFront();
   cout << B.findNext(12) << endl;
   cout << B << endl;
   B.eraseBefore();
   B.eraseAfter();
   cout << B << endl;
   cout << B.position() << endl;
   cout << B.findPrev(6) << endl;
   B.eraseBefore();
   B.eraseAfter();
   cout << B << endl;
   cout << B.position() << endl;
   cout << B.findNext(25) << endl;
   cout << B.position() << endl;
   cout << B.findPrev(25) << endl;
   cout << B.position() << endl;
   cout << endl;

   for (i = 15; i >= 1; i--) {
	A.insertAfter(i * 2 + 1);
      	A.movePrev();
   }
   
   cout << "A = " << A << endl;

   for (i = 1; i <= 25; i++) {
      A.moveNext();
   }

   cout << A.position() << endl;
   A.cleanup();
   cout << "A = " << A << endl;
   cout << A.position() << endl;
   cout << endl;

   E = A;

   cout << "E = " << E << endl;
   cout << "E==A is " << (E == A ? "true" : "false") << endl;

   cout << endl;

   F = A.concat(B);
   cout << "F = " << F << endl;
   cout << "length: " << F.length() << endl;
   cout << "front: " << F.front() << endl;
   cout << "back: " << F.back() << endl;
   cout << "position: " << F.position() << endl;
   
   for (i = 1; i <= 7; i++) {
      cout << "peekNext: " << F.peekNext() << endl;
      F.insertBefore(-i);
      cout << F.moveNext() << endl;
   }

   cout << "F = " << F << endl;
   cout << endl;

   cout << "test exceptions: " << endl;
   cout << "A = " << A << endl;
   A.moveFront();
   try {
      A.peekPrev();
   } catch (std::range_error& e) {
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try {
      A.movePrev();
   } catch (std::range_error& e) {
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try {
      A.setBefore(5);
   } catch (std::range_error& e) {
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try {
      A.eraseBefore();
   } catch (std::range_error& e) {
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   A.moveBack();
   try {
      A.peekNext();
   } catch (std::range_error& e) {
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try {
      A.moveNext();
   } catch (std::range_error& e) {
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try {
      A.setAfter(5);
   } catch (std::range_error& e) {
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try {
      A.eraseAfter();
   } catch (std::range_error& e) {
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   A.clear();
   try {
      A.front();
   } catch (std::length_error& e) {
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try {
      A.back();
   } catch (std::length_error& e) {
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }

   cout << endl;

   // Inserting values in List A
   for (i = 1; i <= 5; i++) {
      A.insertAfter(i + 100);
   }

   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;

   // Moving to the front and inserting values in List B
   B.moveFront();

   for (i = 1; i <= 3; i++) {
      B.insertBefore(i + 200);
   }

   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;

   // Moving to the back and inserting values in List C
   C.moveBack();

   for (i = 1; i <= 4; i++) {
      C.insertAfter(i + 300);
   }

   cout << "C = " << C << endl;
   cout << "C.position() = " << C.position() << endl;

   // Moving to the front and inserting values in List D
   D.moveFront();

   for (i = 1; i <= 2; i++) {
      D.insertBefore(i + 400);
   }

   cout << "D = " << D << endl;
   cout << "D.position() = " << D.position() << endl;

   cout << endl;

   // Concatenating lists A, B, C, and D into E
   E = A.concat(B).concat(C).concat(D);
   cout << "E = " << E << endl;
   cout << "E.position() = " << E.position() << endl;

   // Moving to the back and erasing elements in E
   E.moveBack();
   E.eraseBefore();
   E.eraseBefore();
   cout << "E = " << E << endl;
   cout << "E.position() = " << E.position() << endl;

   // Moving to the front and erasing elements in E
   E.moveFront();
   E.eraseAfter();
   E.eraseAfter();
   cout << "E = " << E << endl;
   cout << "E.position() = " << E.position() << endl;

   cout << endl;

   // Testing front() and back() on empty list
   List emptyList;
   
   try {
      cout << "Front of empty list: " << emptyList.front() << endl;
   } catch (std::length_error& e) {
      cout << e.what() << endl;
   }
   try {
      cout << "Back of empty list: " << emptyList.back() << endl;
   } catch (std::length_error& e) {
      cout << e.what() << endl;
   }

   cout << endl;

   return EXIT_SUCCESS;
}
