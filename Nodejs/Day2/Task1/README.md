# Nodejs lab2
## Task1
# Creating Module 
a module that helps you to add, update, display one ticket or diplay all tickets

```Ticket Reservation Module
class TicketReservation{
    tickets = [];
    AddTicket(id, seatNumber, flightNumber, departureAirport, arrivalAirport, flightDate){
        let ticket = {
            id,
            seatNumber,
            flightNumber,
            departureAirport,
            arrivalAirport,
            flightDate,
        };
        this.tickets.push(ticket);
    }
    getTicket(id){
        let wantedTicket;
        this.tickets.forEach(ticket => {
            if(ticket.id == id){
                wantedTicket = ticket
            }
        })
        return wantedTicket;
    }
    UpdateTicket(ticket){
        this.tickets.forEach( t => {
            if(t.id == ticket.id){
                t = ticket
            }
        });
    }
    DisplayAllTickets(){
        return this.tickets;
    }
}
![1](https://user-images.githubusercontent.com/77510429/222146414-6cf2f68e-fb31-49b1-b0d3-8955c7e03f41.PNG)
![2](https://user-images.githubusercontent.com/77510429/222146428-5e4bcd16-c4b7-4f6d-be65-7b2141138ca9.PNG)

