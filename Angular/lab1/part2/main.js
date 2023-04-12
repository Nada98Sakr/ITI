class Account {
    constructor(Acc_No, Balance) {
        this.Acc_No = Acc_No;
        this.Balance = Balance;
    }
    debitAmount() {
        throw new Error("Method not implemented");
    }
    creditAmount() {
        throw new Error("Method not implemented");
    }
    getBalance() {
        throw new Error("Method not implemented");
    }
}
class Saving_Account extends Account {
    constructor(Min_balance, Date_of_opening, Acc_No, Balance) {
        super(Acc_No, Balance);
        this.Min_balance = Min_balance;
        this.Date_of_opening = Date_of_opening;
    }
    addCustomer() {
        throw new Error("Method not implemented");
    }
    removeCustomer() {
        throw new Error("Method not implemented");
    }
}
class Current_Account extends Account {
    constructor(Min_balance, Date_of_opening, Acc_No, Balance) {
        super(Acc_No, Balance);
        this.Min_balance = Min_balance;
        this.Date_of_opening = Date_of_opening;
    }
    addCustomer() {
        throw new Error("Method not implemented");
    }
    removeCustomer() {
        throw new Error("Method not implemented");
    }
}