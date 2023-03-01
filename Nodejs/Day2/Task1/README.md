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

![1](https://user-images.githubusercontent.com/77510429/222145376-afaf2e31-980c-4ee5-bb63-d43a95a08ee8.PNG)
![2](https://user-images.githubusercontent.com/77510429/222145386-59cba2be-f33e-4fbb-8ad6-bfe0aa50d795.PNG)
