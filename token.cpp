// #include<iostream>
// #include"token.h"
// using namespace std;

// string token::radio(array handCard, card x) {
//     int index = 0;
//     while (handCard[index].getColor() == x.getColor() && index <= handCard.size() - 1) {
//         if (handCard[index].getNum >= x.getNum()) {
//             int max = handCard[index].getNum();
//         }
//         else {
//             int max = x.getNum();
//         }
//         if (handCard[index].getNum <= x.getColor()) {
//             int min = handCard[index].getNum();
//         }
//         else {
//             int min = x.getNum();
//         }
//         index++
//     }
//     if (max == min) {
//         return "only";
//     }
//     else if (max == x.getNum()) {
//         return "max";
//     }
//     else if (min == x.getNum()) {
//         return "min";
//     }
//     else {
//         return "wrong selection";
//     }
// }
// void token::distress(string direction,int playernumber) {


//     if (playernumber == 3) {
//         p1DisNum = player1.getdistressnumber();
//         p2DisNum = player2.getdistressnumber();
//         p3DisNum = player3.getdistressnumber();
//         if (direction == "r") {
//             player1.gethandcard().remove(p1DisNum);
//             player2.gethandcard().add(p1DisNum);
//             player2.gethandcard().remove(p2DisNum);
//             player3.gethandcard().add(p2DisNum);
//             player3.gethandcard().remove(p3DisNum);
//             player1.gethandcard().add(p3DisNum);
//         }else {
//             player1.gethandcard().remove(p1DisNum);
//             player3.gethandcard().add(p1DisNum);
//             player3.gethandcard().remove(p3DisNum);
//             player2.gethandcard().add(p3DisNum);
//             player2.gethandcard().remove(p2DisNum);
//             player1.gethandcard().add(p2DisNum);
//         }
//     }
//     else if (playernumber == 4) {
//         p1DisNum = player1.getdistressnumber();
//         p2DisNum = player2.getdistressnumber();
//         p3DisNum = player3.getdistressnumber();
//         p4DisNum = player4.getdistressnumber();
//         if (direction == "r") {
//             player1.gethandcard().remove(p1DisNum);
//             player2.gethandcard().add(p1DisNum);
//             player2.gethandcard().remove(p2DisNum);
//             player3.gethandcard().add(p2DisNum);
//             player3.gethandcard().remove(p3DisNum);
//             player4.gethandcard().add(p3DisNum);
//             player4.gethandcard().remove(p4DisNum);
//             player1.gethandcard().add(p4DisNum);
//         }
//         else {
//             player1.gethandcard().remove(p1DisNum);
//             player4.gethandcard().add(p1DisNum);
//             player4.gethandcard().remove(p4DisNum);
//             player3.gethandcard().add(p4DisNum);
//             player3.gethandcard().remove(p3DisNum);
//             player2.gethandcard().add(p3DisNum);
//             player2.gethandcard().remove(p2DisNum);
//             player1.gethandcard().add(p2DisNum);
//         }
//     }
//     else if (playernumber == 5) {
//         p1DisNum = player1.getdistressnumber();
//         p2DisNum = player2.getdistressnumber();
//         p3DisNum = player3.getdistressnumber();
//         p4DisNum = player4.getdistressnumber();
//         p5DisNum = player5.getdistressnumber();
//         if (direction == "r") {
//             player1.gethandcard().remove(p1DisNum);
//             player2.gethandcard().add(p1DisNum);
//             player2.gethandcard().remove(p2DisNum);
//             player3.gethandcard().add(p2DisNum);
//             player3.gethandcard().remove(p3DisNum);
//             player4.gethandcard().add(p3DisNum);
//             player4.gethandcard().remove(p4DisNum);
//             player5.gethandcard().add(p4DisNum);
//             player5.gethandcard().remove(p5DisNum);
//             player1.gethandcard().add(p5DisNum);
//         }
//         else {
//             player1.gethandcard().remove(p1DisNum);
//             player5.gethandcard().add(p1DisNum);
//             player5.gethandcard().remove(p5DisNum);
//             player4.gethandcard().add(p5DisNum);
//             player4.gethandcard().remove(p4DisNum);
//             player3.gethandcard().add(p4DisNum);
//             player3.gethandcard().remove(p3DisNum);
//             player2.gethandcard().add(p3DisNum);
//             player2.gethandcard().remove(p2DisNum);
//             player1.gethandcard().add(p2DisNum);
//         }
//     }
// }