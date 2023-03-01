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

