
var flightModule = require("./flightModule");

let MyTickets = flightModule.TicketReservation;

let user1 = new MyTickets();

user1.AddTicket(1, 20, 3, 'Egypt', 'Germany', new Date('2019-03-02'));
user1.AddTicket(2, 5, 2, "Netherlands", "Egypt", new Date('2020-03-20'));
user1.AddTicket(3, 20, 5, "Egypt", "Netherlands", new Date('2020-03-28'));

console.log("----------------------------------------------");
console.log("Displaying All tickets");
console.log(user1.DisplayAllTickets())

console.log("----------------------------------------------");
console.log("git ticket with id = 1");
let ticket1 = user1.getTicket(1)
console.log(ticket1);
ticket1.seatNumber = 35
user1.UpdateTicket(ticket1)

console.log("----------------------------------------------");
console.log("update ticket seat number  with id = 1 to 35");
console.log(user1.getTicket(1))
console.log("----------------------------------------------");
